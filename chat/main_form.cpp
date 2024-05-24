//https://documentation.help/Qt-3.0.5/index.html
#include <qmultilineedit.h>
#include <qapplication.h>
#include <qtextbrowser.h>
#include <netinet/in.h>
#include "main_form.h"
#include <qlineedit.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <qlistbox.h>
#include <qstring.h>
#include <ifaddrs.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <netdb.h>

//QString int2qs(int x) {
//	int tot = 0;
//	char bot[8];
//	QString ret;
//	while (x)
//		bot[++tot] = '0' + (x % 10),
//		x /= 10;
//	while (tot) ret += bot[tot--];
//	return ret;
//}

QString getlocalip() {
    struct ifaddrs *ifaddr, *ifa;
    int family;
    char host[NI_MAXHOST];

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        return "";
    }

    QString ipAddress = "";

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL)
            continue;

        family = ifa->ifa_addr->sa_family;

        if (family == AF_INET) {
            if (getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in),
                            host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST) == 0) {
                if (strcmp(ifa->ifa_name, "lo") != 0) {
                    ipAddress = host;
                    break;
                }
            }
        }
    }

    freeifaddrs(ifaddr);

    return ipAddress;
}

TMainForm::TMainForm(QWidget *parent, const char *name, WFlags f)
    : TMainFormBase(parent, name, f), sockfd(-1), socketNotifier(NULL), clientport(0) {

	t_recv -> setText("Welcome to use Tencenpp2024. version: 1.0.0\n");
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

	clientport = 8080;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    socketNotifier = new QSocketNotifier(sockfd, QSocketNotifier::Read, this);
    connect(socketNotifier, SIGNAL(activated(int)), this, SLOT(slot_data()));
}

TMainForm::~TMainForm() {
    if (sockfd >= 0) {
        close(sockfd);
    }
    delete socketNotifier;
}

void TMainForm::slot_clear() {
    t_edit->setText("");
}

void TMainForm::slot_close() {
    close();
    qApp -> quit();
}

void TMainForm::slot_edit() {
}

void TMainForm::slot_name() {
	username = t_n -> text();
}
void TMainForm::slot_ip() {
    clientip = t_ip -> text();
}

void TMainForm::slot_port() {
    clientport = t_port -> text().toInt();
}

void TMainForm::slot_send() {
    if (clientip.isEmpty() || clientport == 0) {
    	t_recv -> setText("Error: Plz set IP and port first.");
        return;
    }

    QString i_text = t_edit -> text();
    
    if (i_text.isEmpty()) {
        return;
    }
    
    i_text = getlocalip() + "[" + username + "]:" + i_text;
	const char *i_array = i_text.ascii();

    struct sockaddr_in destAddr;
    bzero(&destAddr, sizeof(destAddr));
    destAddr.sin_family = AF_INET;
    destAddr.sin_addr.s_addr = inet_addr(clientip.ascii());
    destAddr.sin_port = htons(clientport);

    sendto(sockfd, i_array, strlen(i_array), 0, (struct sockaddr*)&destAddr, sizeof(destAddr));

	t_edit -> setText("");
}

void TMainForm::slot_data() {
    char buffer[1024];
    socklen_t len = sizeof(cliaddr);
    int n = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr*)&cliaddr, &len);
    if (n > 0) {
        buffer[n] = '\0';
        QString receivedMessage = QString::fromUtf8(buffer);
        t_recv -> append(receivedMessage);
//        t_recv -> append(clientip + ":" + int2qs(clientport) + ":" + receivedMessage);
        QScrollBar *vScrollBar = t_recv -> verticalScrollBar();
        vScrollBar -> setValue(vScrollBar -> maxValue());
    } else {
        std::cerr << "recvfrom error: " << strerror(errno) << std::endl;
    }
}
