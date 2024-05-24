#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void do_echo(int sockfd, struct sockaddr *pcliaddr, socklen_t clilen) {
    int n;
    socklen_t len;
    char mesg[1024];
    fd_set readfds;
    struct timeval tv;
    int maxfd = sockfd + 1;

    for (;;) {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        FD_SET(STDIN_FILENO, &readfds);

        tv.tv_sec = 1;
        tv.tv_usec = 0;

        int retval = select(maxfd, &readfds, NULL, NULL, &tv);

        if (retval == -1) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(sockfd, &readfds)) {
            len = clilen;
            n = recvfrom(sockfd, mesg, sizeof(mesg) - 1, 0, pcliaddr, &len);
            if (n < 0) {
                perror("recvfrom");
                exit(EXIT_FAILURE);
            }
            mesg[n] = '\0';
            printf("\n%s\n", mesg);
        }

        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            printf("[input]");
            if (fgets(mesg, sizeof(mesg), stdin) != NULL) {
                sendto(sockfd, mesg, strlen(mesg), 0, pcliaddr, clilen);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    printf("[input]");
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd;
    struct sockaddr_in servaddr, cliaddr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    do_echo(sockfd, (struct sockaddr *) &cliaddr, sizeof(cliaddr));
    return 0;
}

