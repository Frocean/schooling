/****************************************************************************
** Form implementation generated from reading ui file 'chat.ui'
**
** Created: Tue May 21 21:47:01 2024
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "chat.h"

#include <qlabel.h>
#include <qlineedit.h>
#include <qmultilineedit.h>
#include <qpushbutton.h>
#include <qtextbrowser.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a TMainFormBase which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
TMainFormBase::TMainFormBase( QWidget* parent,  const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "TMainFormBase" );
    resize( 280, 300 ); 
    setMaximumSize( QSize( 280, 300 ) );
    setCaption( tr( "2021210720-Tencen pp 2024" ) );

    text_port = new QLabel( this, "text_port" );
    text_port->setGeometry( QRect( 20, 40, 80, 20 ) ); 
    text_port->setText( tr( "Client's Port" ) );
    text_port->setAlignment( int( QLabel::AlignCenter ) );

    text_ip = new QLabel( this, "text_ip" );
    text_ip->setGeometry( QRect( 20, 20, 80, 20 ) ); 
    text_ip->setText( tr( "Client's IP" ) );
    text_ip->setAlignment( int( QLabel::AlignCenter ) );

    t_ip = new QLineEdit( this, "t_ip" );
    t_ip->setGeometry( QRect( 100, 20, 80, 20 ) ); 

    t_port = new QLineEdit( this, "t_port" );
    t_port->setGeometry( QRect( 100, 40, 80, 20 ) ); 

    t_edit = new QMultiLineEdit( this, "t_edit" );
    t_edit->setGeometry( QRect( 10, 190, 260, 50 ) ); 

    t_recv = new QTextBrowser( this, "t_recv" );
    t_recv->setGeometry( QRect( 10, 60, 260, 125 ) ); 

    t_send = new QPushButton( this, "t_send" );
    t_send->setGeometry( QRect( 220, 245, 50, 30 ) ); 
    t_send->setText( tr( "Send" ) );

    t_clear = new QPushButton( this, "t_clear" );
    t_clear->setGeometry( QRect( 170, 245, 50, 30 ) ); 
    t_clear->setText( tr( "Clear" ) );

    t_close = new QPushButton( this, "t_close" );
    t_close->setGeometry( QRect( 120, 245, 50, 30 ) ); 
    t_close->setText( tr( "Close" ) );

    // signals and slots connections
    connect( t_ip, SIGNAL( textChanged(const QString&) ), this, SLOT( slot_ip() ) );
    connect( t_port, SIGNAL( textChanged(const QString&) ), this, SLOT( slot_port() ) );
    connect( t_send, SIGNAL( clicked() ), this, SLOT( slot_send() ) );
    connect( t_clear, SIGNAL( clicked() ), this, SLOT( slot_clear() ) );
    connect( t_close, SIGNAL( clicked() ), this, SLOT( slot_close() ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
TMainFormBase::~TMainFormBase()
{
    // no need to delete child widgets, Qt does it all for us
}

void TMainFormBase::slot_clear()
{
    qWarning( "TMainFormBase::slot_clear(): Not implemented yet!" );
}

void TMainFormBase::slot_close()
{
    qWarning( "TMainFormBase::slot_close(): Not implemented yet!" );
}

void TMainFormBase::slot_edit()
{
    qWarning( "TMainFormBase::slot_edit(): Not implemented yet!" );
}

void TMainFormBase::slot_ip()
{
    qWarning( "TMainFormBase::slot_ip(): Not implemented yet!" );
}

void TMainFormBase::slot_port()
{
    qWarning( "TMainFormBase::slot_port(): Not implemented yet!" );
}

void TMainFormBase::slot_send()
{
    qWarning( "TMainFormBase::slot_send(): Not implemented yet!" );
}

