#if !defined(__MAIN_FORM_H__)
# define __MAIN_FORM_H__
#include "main_form_base.h"
#include <qsocketnotifier.h>
class TMainForm: public TMainFormBase {
	Q_OBJECT
	public:
		TMainForm(QWidget * parent = 0, const char * name = 0, 
WFlags f = WType_TopLevel): TMainFormBase(parent, name, f) {}
		virtual ~TMainForm() {}
	public slots:
		void slot_x();
		void slot_y();
		void slot_op();
		void slot_ans();
};
#endif
