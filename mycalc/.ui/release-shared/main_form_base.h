/****************************************************************************
** Form interface generated from reading ui file 'main_form_base.ui'
**
** Created: Sun May 12 21:29:20 2024
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
    QMultiLineEdit* i_x;
    QListBox* s_o;
    QListBox* s_y;
    QMultiLineEdit* i_y;
    QListBox* s_z;
    QMultiLineEdit* o_ans;
    QPushButton* s_ans;
    QPushButton* s_c;

public slots:
    virtual void slot_ans();
    virtual void slot_c();
    virtual void slot_op();
    virtual void slot_x();
    virtual void slot_y();
    virtual void slot_z();

};

#endif // TMAINFORMBASE_H
