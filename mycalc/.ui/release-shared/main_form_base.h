/****************************************************************************
** Form interface generated from reading ui file 'main_form_base.ui'
**
** Created: Wed May 15 15:25:09 2024
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
class QListBox;
class QListBoxItem;
class QMultiLineEdit;
class QPushButton;

class TMainFormBase : public QWidget
{ 
    Q_OBJECT

public:
    TMainFormBase( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~TMainFormBase();

    QListBox* s_x;
    QPushButton* s_ans;
    QPushButton* k_2;
    QPushButton* k_5;
    QPushButton* k_3;
    QMultiLineEdit* o_ans;
    QPushButton* k_6;
    QPushButton* k_7;
    QPushButton* k_8;
    QPushButton* k_c;
    QPushButton* k_9;
    QPushButton* k_d;
    QPushButton* k_e;
    QPushButton* k_f;
    QPushButton* k_1;
    QPushButton* s_o1;
    QPushButton* s_o0;
    QPushButton* s_o2;
    QPushButton* s_o3;
    QPushButton* k_4;
    QPushButton* k_a;
    QPushButton* k_0;
    QListBox* s_y;
    QPushButton* k_n_x;
    QMultiLineEdit* i_x;
    QMultiLineEdit* i_y;
    QListBox* s_z;
    QPushButton* s_2;
    QPushButton* s_1;
    QPushButton* k_n_y;
    QPushButton* k_b;
    QPushButton* s_c;
    QPushButton* s_b;

public slots:
    virtual void k0_slot();
    virtual void k1_slot();
    virtual void k2_slot();
    virtual void k3_slot();
    virtual void k4_slot();
    virtual void k5_slot();
    virtual void k6_slot();
    virtual void k7_slot();
    virtual void k8_slot();
    virtual void k9_slot();
    virtual void ka_slot();
    virtual void kb_slot();
    virtual void kc_slot();
    virtual void kd_slot();
    virtual void ke_slot();
    virtual void kf_slot();
    virtual void knx_slot();
    virtual void kny_slot();
    virtual void slot_b();
    virtual void slot_ans();
    virtual void slot_c();
    virtual void slot_i1();
    virtual void slot_i2();
    virtual void slot_o0();
    virtual void slot_o1();
    virtual void slot_o2();
    virtual void slot_o3();
    virtual void slot_x();
    virtual void slot_y();
    virtual void slot_z();

};

#endif // TMAINFORMBASE_H
