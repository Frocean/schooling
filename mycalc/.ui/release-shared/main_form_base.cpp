/****************************************************************************
** Form implementation generated from reading ui file 'main_form_base.ui'
**
** Created: Wed May 15 15:25:10 2024
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "main_form_base.h"

#include <qlistbox.h>
#include <qmultilineedit.h>
#include <qpushbutton.h>
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
    resize( 716, 420 ); 
    setMaximumSize( QSize( 720, 420 ) );
    setCaption( tr( "2021210720" ) );

    s_x = new QListBox( this, "s_x" );
    s_x->insertItem( tr( "binary" ) );
    s_x->insertItem( tr( "octonary" ) );
    s_x->insertItem( tr( "decimal" ) );
    s_x->insertItem( tr( "hexdecimal" ) );
    s_x->setGeometry( QRect( 10, 10, 100, 70 ) ); 
    s_x->setFrameShape( QListBox::StyledPanel );
    s_x->setFrameShadow( QListBox::Sunken );

    s_ans = new QPushButton( this, "s_ans" );
    s_ans->setGeometry( QRect( 560, 340, 100, 40 ) ); 
    s_ans->setText( tr( "Get Answer" ) );

    k_2 = new QPushButton( this, "k_2" );
    k_2->setGeometry( QRect( 340, 140, 100, 40 ) ); 
    k_2->setText( tr( "2" ) );

    k_5 = new QPushButton( this, "k_5" );
    k_5->setGeometry( QRect( 340, 190, 100, 40 ) ); 
    k_5->setText( tr( "5" ) );

    k_3 = new QPushButton( this, "k_3" );
    k_3->setGeometry( QRect( 450, 140, 101, 40 ) ); 
    k_3->setText( tr( "3" ) );

    o_ans = new QMultiLineEdit( this, "o_ans" );
    o_ans->setGeometry( QRect( 120, 340, 430, 40 ) ); 

    k_6 = new QPushButton( this, "k_6" );
    k_6->setGeometry( QRect( 450, 190, 101, 40 ) ); 
    k_6->setText( tr( "6" ) );

    k_7 = new QPushButton( this, "k_7" );
    k_7->setGeometry( QRect( 230, 240, 100, 40 ) ); 
    k_7->setText( tr( "7" ) );

    k_8 = new QPushButton( this, "k_8" );
    k_8->setGeometry( QRect( 340, 240, 100, 40 ) ); 
    k_8->setText( tr( "8" ) );

    k_c = new QPushButton( this, "k_c" );
    k_c->setGeometry( QRect( 120, 290, 100, 40 ) ); 
    k_c->setText( tr( "C" ) );

    k_9 = new QPushButton( this, "k_9" );
    k_9->setGeometry( QRect( 450, 240, 101, 40 ) ); 
    k_9->setText( tr( "9" ) );

    k_d = new QPushButton( this, "k_d" );
    k_d->setGeometry( QRect( 230, 290, 100, 40 ) ); 
    k_d->setText( tr( "D" ) );

    k_e = new QPushButton( this, "k_e" );
    k_e->setGeometry( QRect( 340, 290, 100, 40 ) ); 
    k_e->setText( tr( "E" ) );

    k_f = new QPushButton( this, "k_f" );
    k_f->setGeometry( QRect( 450, 290, 101, 40 ) ); 
    k_f->setText( tr( "F" ) );

    k_1 = new QPushButton( this, "k_1" );
    k_1->setGeometry( QRect( 230, 140, 100, 40 ) ); 
    k_1->setText( tr( "1" ) );

    s_o1 = new QPushButton( this, "s_o1" );
    s_o1->setGeometry( QRect( 560, 190, 100, 40 ) ); 
    s_o1->setText( tr( "(-) subtract" ) );

    s_o0 = new QPushButton( this, "s_o0" );
    s_o0->setGeometry( QRect( 560, 140, 100, 40 ) ); 
    s_o0->setText( tr( "(+) add" ) );

    s_o2 = new QPushButton( this, "s_o2" );
    s_o2->setGeometry( QRect( 560, 240, 100, 40 ) ); 
    s_o2->setText( tr( "(*) multiply" ) );

    s_o3 = new QPushButton( this, "s_o3" );
    s_o3->setGeometry( QRect( 560, 290, 100, 40 ) ); 
    s_o3->setText( tr( "(/) divide" ) );

    k_4 = new QPushButton( this, "k_4" );
    k_4->setGeometry( QRect( 230, 190, 100, 40 ) ); 
    k_4->setText( tr( "4" ) );

    k_a = new QPushButton( this, "k_a" );
    k_a->setGeometry( QRect( 120, 190, 100, 40 ) ); 
    k_a->setText( tr( "A" ) );

    k_0 = new QPushButton( this, "k_0" );
    k_0->setGeometry( QRect( 120, 140, 100, 40 ) ); 
    k_0->setText( tr( "0" ) );

    s_y = new QListBox( this, "s_y" );
    s_y->insertItem( tr( "binary" ) );
    s_y->insertItem( tr( "octonary" ) );
    s_y->insertItem( tr( "decimal" ) );
    s_y->insertItem( tr( "hexdecimal" ) );
    s_y->setGeometry( QRect( 560, 60, 100, 70 ) ); 

    k_n_x = new QPushButton( this, "k_n_x" );
    k_n_x->setGeometry( QRect( 560, 10, 100, 40 ) ); 
    k_n_x->setText( tr( "Negative" ) );

    i_x = new QMultiLineEdit( this, "i_x" );
    i_x->setGeometry( QRect( 120, 10, 430, 40 ) ); 

    i_y = new QMultiLineEdit( this, "i_y" );
    i_y->setGeometry( QRect( 120, 90, 430, 40 ) ); 

    s_z = new QListBox( this, "s_z" );
    s_z->insertItem( tr( "binary" ) );
    s_z->insertItem( tr( "octonary" ) );
    s_z->insertItem( tr( "decimal" ) );
    s_z->insertItem( tr( "hexdecimal" ) );
    s_z->setGeometry( QRect( 10, 340, 100, 70 ) ); 

    s_2 = new QPushButton( this, "s_2" );
    s_2->setGeometry( QRect( 10, 290, 100, 40 ) ); 
    s_2->setText( tr( "v" ) );

    s_1 = new QPushButton( this, "s_1" );
    s_1->setGeometry( QRect( 10, 240, 100, 40 ) ); 
    s_1->setText( tr( "^" ) );

    k_n_y = new QPushButton( this, "k_n_y" );
    k_n_y->setGeometry( QRect( 10, 90, 100, 40 ) ); 
    k_n_y->setText( tr( "Negative" ) );

    k_b = new QPushButton( this, "k_b" );
    k_b->setGeometry( QRect( 120, 240, 100, 40 ) ); 
    k_b->setText( tr( "B" ) );

    s_c = new QPushButton( this, "s_c" );
    s_c->setGeometry( QRect( 10, 140, 100, 40 ) ); 
    s_c->setText( tr( "C/CE" ) );

    s_b = new QPushButton( this, "s_b" );
    s_b->setGeometry( QRect( 10, 190, 100, 40 ) ); 
    s_b->setText( tr( "Backspace" ) );

    // signals and slots connections
    connect( s_ans, SIGNAL( clicked() ), this, SLOT( slot_ans() ) );
    connect( s_x, SIGNAL( selected(int) ), this, SLOT( slot_x() ) );
    connect( s_y, SIGNAL( selected(int) ), this, SLOT( slot_y() ) );
    connect( s_z, SIGNAL( selected(int) ), this, SLOT( slot_z() ) );
    connect( s_c, SIGNAL( clicked() ), this, SLOT( slot_c() ) );
    connect( s_o0, SIGNAL( clicked() ), this, SLOT( slot_o0() ) );
    connect( s_o1, SIGNAL( clicked() ), this, SLOT( slot_o1() ) );
    connect( s_o2, SIGNAL( clicked() ), this, SLOT( slot_o2() ) );
    connect( s_o3, SIGNAL( clicked() ), this, SLOT( slot_o3() ) );
    connect( s_1, SIGNAL( clicked() ), this, SLOT( slot_i1() ) );
    connect( s_2, SIGNAL( clicked() ), this, SLOT( slot_i2() ) );
    connect( k_0, SIGNAL( clicked() ), this, SLOT( k0_slot() ) );
    connect( k_1, SIGNAL( clicked() ), this, SLOT( k1_slot() ) );
    connect( k_2, SIGNAL( clicked() ), this, SLOT( k2_slot() ) );
    connect( k_3, SIGNAL( clicked() ), this, SLOT( k3_slot() ) );
    connect( k_a, SIGNAL( clicked() ), this, SLOT( ka_slot() ) );
    connect( k_4, SIGNAL( clicked() ), this, SLOT( k4_slot() ) );
    connect( k_5, SIGNAL( clicked() ), this, SLOT( k5_slot() ) );
    connect( k_6, SIGNAL( clicked() ), this, SLOT( k6_slot() ) );
    connect( k_b, SIGNAL( clicked() ), this, SLOT( kb_slot() ) );
    connect( k_7, SIGNAL( clicked() ), this, SLOT( k7_slot() ) );
    connect( k_8, SIGNAL( clicked() ), this, SLOT( k8_slot() ) );
    connect( k_9, SIGNAL( clicked() ), this, SLOT( k9_slot() ) );
    connect( k_c, SIGNAL( clicked() ), this, SLOT( kc_slot() ) );
    connect( k_d, SIGNAL( clicked() ), this, SLOT( kd_slot() ) );
    connect( k_e, SIGNAL( clicked() ), this, SLOT( ke_slot() ) );
    connect( k_f, SIGNAL( clicked() ), this, SLOT( kf_slot() ) );
    connect( k_n_y, SIGNAL( clicked() ), this, SLOT( kny_slot() ) );
    connect( k_n_x, SIGNAL( clicked() ), this, SLOT( knx_slot() ) );
    connect( s_b, SIGNAL( clicked() ), this, SLOT( slot_b() ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
TMainFormBase::~TMainFormBase()
{
    // no need to delete child widgets, Qt does it all for us
}

void TMainFormBase::k0_slot()
{
    qWarning( "TMainFormBase::k0_slot(): Not implemented yet!" );
}

void TMainFormBase::k1_slot()
{
    qWarning( "TMainFormBase::k1_slot(): Not implemented yet!" );
}

void TMainFormBase::k2_slot()
{
    qWarning( "TMainFormBase::k2_slot(): Not implemented yet!" );
}

void TMainFormBase::k3_slot()
{
    qWarning( "TMainFormBase::k3_slot(): Not implemented yet!" );
}

void TMainFormBase::k4_slot()
{
    qWarning( "TMainFormBase::k4_slot(): Not implemented yet!" );
}

void TMainFormBase::k5_slot()
{
    qWarning( "TMainFormBase::k5_slot(): Not implemented yet!" );
}

void TMainFormBase::k6_slot()
{
    qWarning( "TMainFormBase::k6_slot(): Not implemented yet!" );
}

void TMainFormBase::k7_slot()
{
    qWarning( "TMainFormBase::k7_slot(): Not implemented yet!" );
}

void TMainFormBase::k8_slot()
{
    qWarning( "TMainFormBase::k8_slot(): Not implemented yet!" );
}

void TMainFormBase::k9_slot()
{
    qWarning( "TMainFormBase::k9_slot(): Not implemented yet!" );
}

void TMainFormBase::ka_slot()
{
    qWarning( "TMainFormBase::ka_slot(): Not implemented yet!" );
}

void TMainFormBase::kb_slot()
{
    qWarning( "TMainFormBase::kb_slot(): Not implemented yet!" );
}

void TMainFormBase::kc_slot()
{
    qWarning( "TMainFormBase::kc_slot(): Not implemented yet!" );
}

void TMainFormBase::kd_slot()
{
    qWarning( "TMainFormBase::kd_slot(): Not implemented yet!" );
}

void TMainFormBase::ke_slot()
{
    qWarning( "TMainFormBase::ke_slot(): Not implemented yet!" );
}

void TMainFormBase::kf_slot()
{
    qWarning( "TMainFormBase::kf_slot(): Not implemented yet!" );
}

void TMainFormBase::knx_slot()
{
    qWarning( "TMainFormBase::knx_slot(): Not implemented yet!" );
}

void TMainFormBase::kny_slot()
{
    qWarning( "TMainFormBase::kny_slot(): Not implemented yet!" );
}

void TMainFormBase::slot_b()
{
    qWarning( "TMainFormBase::slot_b(): Not implemented yet!" );
}

void TMainFormBase::slot_ans()
{
    qWarning( "TMainFormBase::slot_ans(): Not implemented yet!" );
}

void TMainFormBase::slot_c()
{
    qWarning( "TMainFormBase::slot_c(): Not implemented yet!" );
}

void TMainFormBase::slot_i1()
{
    qWarning( "TMainFormBase::slot_i1(): Not implemented yet!" );
}

void TMainFormBase::slot_i2()
{
    qWarning( "TMainFormBase::slot_i2(): Not implemented yet!" );
}

void TMainFormBase::slot_o0()
{
    qWarning( "TMainFormBase::slot_o0(): Not implemented yet!" );
}

void TMainFormBase::slot_o1()
{
    qWarning( "TMainFormBase::slot_o1(): Not implemented yet!" );
}

void TMainFormBase::slot_o2()
{
    qWarning( "TMainFormBase::slot_o2(): Not implemented yet!" );
}

void TMainFormBase::slot_o3()
{
    qWarning( "TMainFormBase::slot_o3(): Not implemented yet!" );
}

void TMainFormBase::slot_x()
{
    qWarning( "TMainFormBase::slot_x(): Not implemented yet!" );
}

void TMainFormBase::slot_y()
{
    qWarning( "TMainFormBase::slot_y(): Not implemented yet!" );
}

void TMainFormBase::slot_z()
{
    qWarning( "TMainFormBase::slot_z(): Not implemented yet!" );
}

