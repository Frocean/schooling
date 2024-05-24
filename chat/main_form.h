#if !defined(__MAIN_FORM_H__)
# define __MAIN_FORM_H__
#include "chat.h"
#include <qsocketnotifier.h>
#include <sys/socket.h>
#include <arpa/inet.h>
class TMainForm: public TMainFormBase {
	Q_OBJECT
	public:
		TMainForm(QWidget * parent = 0, const char * name = 0, 
WFlags f = WType_TopLevel);
		virtual ~TMainForm();
	public slots:
		void slot_clear();
		void slot_close();
		void slot_data();
		void slot_edit();
		void slot_ip();
		void slot_port();
		void slot_send();
	private:
    	int sockfd;
		struct sockaddr_in servaddr, cliaddr;
    	QSocketNotifier *socketNotifier;
    	QString clientip, username;
    	int clientport;
};
#endif
