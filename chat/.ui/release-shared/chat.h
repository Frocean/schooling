/****************************************************************************
** Form interface generated from reading ui file 'chat.ui'
**
** Created: Tue May 21 21:47:00 2024
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef TMAINFORMBASE_H
#define TMAINFORMBASE_H

#include <qvariant.h>
#include <qwidget.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QLabel;
class QLineEdit;
class QMultiLineEdit;
class QPushButton;
class QTextBrowser;

class TMainFormBase : public QWidget
{ 
    Q_OBJECT

public:
    TMainFormBase( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~TMainFormBase();

    QLabel* text_port;
    QLabel* text_ip;
    QLineEdit* t_ip;
    QLineEdit* t_port;
    QMultiLineEdit* t_edit;
    QTextBrowser* t_recv;
    QPushButton* t_send;
    QPushButton* t_clear;
    QPushButton* t_close;

public slots:
    virtual void slot_clear();
    virtual void slot_close();
    virtual void slot_edit();
    virtual void slot_ip();
    virtual void slot_port();
    virtual void slot_send();

};

#endif // TMAINFORMBASE_H
