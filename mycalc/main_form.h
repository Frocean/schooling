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
		void k0_slot();
		void k1_slot();
		void k2_slot();
		void k3_slot();
		void k4_slot();
		void k5_slot();
		void k6_slot();
		void k7_slot();
		void k8_slot();
		void k9_slot();
		void ka_slot();
		void kb_slot();
		void kc_slot();
		void kd_slot();
		void ke_slot();
		void kf_slot();
		void knx_slot();
		void kny_slot();
		void slot_b();
		void slot_c();
		void slot_i1();
		void slot_i2();
		void slot_o0();
		void slot_o1();
		void slot_o2();
		void slot_o3();
		void slot_x();
		void slot_y();
		void slot_z();
		void slot_ans();
};
#endif
