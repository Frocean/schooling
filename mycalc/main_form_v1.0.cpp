#include <qmultilineedit.h>
#include "main_form.h"
#include <qlineedit.h>
#include <qlistbox.h>
#include <qstring.h>
#include <stdlib.h>
int s1[10005], s2[10005],s[10005], o[10005];
int mode[] = {2,8,10,16};
int moder[] = {2,4,10,5};

// chtonum: transfer char to int
int chtonum(char c) {return ('0'<=c)&&(c<='9')?c-'0':c-'A'+10;}
int max(int x,int y) {return x>y?x:y;}
void swap(int &x, int &y) {int z = x; x = y, y = z;}
void reset() {
	memset(o, 0, sizeof(o));
	memset(s, 0, sizeof(s));
	memset(s1, 0, sizeof(s1));
	memset(s2, 0, sizeof(s2));
}
bool judge(char c, int mo) {
	switch (mo) {
		case 0:return ('0'==c)||(c=='1');break;
		case 1:return ('0'<=c)&&(c<='7');break;
		case 2:return ('0'<=c)&&(c<='9');break;
		case 3:return (('0'<=c)&&(c<='9'))||(('A'<=c)&&(c<='F'));break;
		default:return false;
	}
	return false;
}
// upd: ensure the array is decimal
int upd(int rarr[],int l) {
	for (int j = 1 ; j < l ; ++ j) {
		rarr[j + 1] += rarr[j] / 10;
		rarr[j] %= 10;
	}
	for (int j = l ; rarr[j] > 9 ; ++ j) {
		rarr[++l] += rarr[j] / 10;
		rarr[j] %= 10;
		if (l > 10000) exit(EXIT_FAILURE);
	}
	return l;
}
// trans: original result mode length
int trans(int ori[], int res[], int mo, int len) {
	int leng = 1;
	res[1] = ori[1];
	leng = upd(res,1);
	// multiply by bit and reverse high-low
	for (int i = 2 ; i <= len ; ++ i) {
		for (int j = 1 ; j <= leng ; ++ j) res[j] *= mo;
		res[1] += ori[i];
		leng = upd(res,leng);
	}
	return leng;
}
void exchange(int arr1[], int arr2[], int &lx, int &ly) {
	int* bot = new int[10005];
	memset(bot, 0, sizeof(bot));
	memcpy(bot, arr1, sizeof(arr1));
	memcpy(arr1, arr2, sizeof(arr2));
	memcpy(arr2, bot, sizeof(bot));
	swap(lx, ly);
	delete[] bot;
}
bool cmp(int arr1[], int arr2[], int l1, int l2) {
	if (l1 > l2) return false;
	if (l1 < l2) return true;
	for (int i = l1 ; i ; -- i)
		if (arr1[i] > arr2[i]) return false; else
		if (arr1[i] < arr2[i]) return true;
	return false;
}
int unitrans(int ori[], int res[], int mo, int len) {
	//ori: small -> big
	//bot: small -> big
	//res: small -> big
	int* bot = new int[10005];
	int leng = 0, l = 0;
	memset(bot, 0, sizeof(bot));
	//divide 2 get mod
	while (len > 1) {
		if (!ori[len]) -- len;
		bot[++leng] = ori[1] & 1;
		if (leng > 10000) exit(EXIT_FAILURE);
		ori[1] &= 14;
		for (int i = len, extra = 0, ebot ; i ; -- i) {
			ebot = extra;
			ori[i] & 1 ? extra = 5 : extra = 0;
			ori[i] >>= 1; ori[i] += ebot;
		}
	}
	while (ori[1] > 1) {
		bot[++leng] = ori[1] & 1;
		ori[1] >>= 1;
		if (leng > 10000) exit(EXIT_FAILURE);
	}
	bot[++leng] = ori[1];
	//mix bit together 2 -> 1bit, 8 -> 3bit, 16 -> 4bit
	for (int i = 1, stat = 1, bitt = 1 ; i <= leng ; ++ i) {
		if (stat == 1) ++ l;
		res[l] += bitt * bot[i];
		++ stat;
		if (stat == mo) stat = 1, bitt = 1;
		else bitt <<= 1;
	}
	delete[] bot;
	return l;
}
QString getans(int ans[], int l, short sym) {
	QString result = "";
	if (sym) result += '-';
	for (int i = l ; i ; -- i)
		(ans[i] <= 9)
			? result += QString::number(ans[i])
			: result += 'A' + ans[i] - 10;
	return result;
}
int _add(int ons[], int ar1[], int ar2[], int lx, int ly) {
	int l = lx>ly?lx:ly;
	for (int i = 1 ; i <= l ; ++ i) ons[i] += ar1[i] + ar2[i];
	l = upd(ons,l);
	return l;
}
int _subtract(int ons[], int ar1[], int ar2[], int lx, int ly) {
	// subtract from high to low (small <- big)
	for (int i = ly ; i ; -- i) {
		ar1[i] -= ar2[i];
		for (int j = i ; ar1[j] < 0 ; )
			ar1[j] += 10,
			--ar1[++j];
		if (!ar1[lx]) --lx;
	}
	for (int i = 1 ; i <= lx ; ++ i) ons[i] = ar1[i];
	return lx;
}
int _multiply(int ons[], int ar1[], int ar2[], int lx, int ly) {
	for (int i = 1 ; i <= ly ; ++ i) {
		for (int j = 1 ; j <= lx ; ++ j)
			ons[i + j - 1] += ar1[j] * ar2[i];
		upd(ons, i + lx - 1);
	}
	return ons[lx + ly] ? lx + ly : lx + ly - 1;
}
int _divide(int ons[], int ar1[], int ar2[], int lx, int ly) {
	int bot[10005],tob[10005];
//	ons[1] = 0;
	// divide from high to low
	for (int head = lx, tail = lx - ly + 1 ; tail > 0 ; --head, --tail) {
		int now = 0;
		memset(bot,0,sizeof(bot));
		// get 1 * now number, every time decrease by 1
		for (int i = 1 ; i <= ly ; ++ i) bot[tail + i - 1] = ar2[i];
		while (!cmp(ar1, bot, head + 1, head + 1)) {
			++ now;
			_subtract(tob, ar1, bot, head, head);
		}
		ons[tail] = now;
	}
	return max(lx - ly + (ons[lx - ly + 1] != 0), 1);
}
void TMainForm::slot_ans() {
	o_ans -> setText("");
	QString x_text = i_x -> text();
	QString y_text = i_y -> text();
	int x_len = x_text.length();
	int y_len = y_text.length();
	if (x_len > 10000 || y_len > 10000) {
		o_ans -> setText("Number is too large. Error code: 1");
		return;
	}
	const char *x_array = x_text.ascii();
	const char *y_array = y_text.ascii();
	
	// check if '-' and then copy
	short x_sym = (x_text[0] == '-');
	short y_sym = (y_text[0] == '-');
	char x_char[10005], y_char[10005];
	memset(x_char, 0, sizeof(x_char));
	memset(y_char, 0, sizeof(y_char));
	strcpy(x_char + 1, x_array + x_sym);
	strcpy(y_char + 1, y_array + y_sym);
	x_len -= x_sym, y_len -= y_sym;
	if (i_x -> text().isEmpty()) x_len = 1, x_char[1] = '0';
	if (i_y -> text().isEmpty()) y_len = 1, y_char[1] = '0';

	// judge if legal
	int x_index = s_x -> currentItem();
	int y_index = s_y -> currentItem();
	int z_index = s_z -> currentItem();
	for (int i = 1 ; i <= x_len ; ++ i) {
		if (('a' <= x_char[i]) && (x_char[i] < 'g'))
			x_char[i] -= 'a' - 'A'; //transfer a to A
		if (!judge(x_char[i], x_index)) {
			o_ans -> setText("Compile Error: illegal number"); return;
		}
	}
	for (int i = 1 ; i <= y_len ; ++ i) {
		if (('a' <= y_char[i]) && (y_char[i] < 'g'))
			y_char[i] -= 'a' - 'A'; //transfer a to A
		if (!judge(y_char[i], y_index)) {
			o_ans -> setText("Compile Error: illegal number"); return;
		}
	}
	
	
	// transfer to decimal: small -> big
	reset();
	o_ans -> setText("");
	int o1[10005], o2[10005];
	memset(o1, 0, sizeof(o1));
	memset(o2, 0, sizeof(o2));
	for (int i = 1 ; i <= x_len ; ++ i) o1[i] = chtonum(x_char[i]);
	for (int i = 1 ; i <= y_len ; ++ i) o2[i] = chtonum(y_char[i]);
	o_ans -> setText("Number is too large. Error code: 2");
	x_len = trans(o1, s1, mode[x_index], x_len);
	y_len = trans(o2, s2, mode[y_index], y_len);
	
	//transform operator
	int op_index = s_o -> currentItem();
	short sym = 0;
	switch (op_index) {
		case 0:
			// -A + -B = -(A+B) -> + change symbol
			if (x_sym && y_sym) sym = 1; else
			// -A +  B = B - A  -> -
			if (x_sym) op_index = 1, exchange(s1, s2, x_len, y_len); else
			//  A + -B = A - B  -> -
			if (y_sym) op_index = 1; break;
		case 1:
			// -A - -B = B - A  -> -
			if (x_sym && y_sym) exchange(s1, s2, x_len, y_len); else
			// -A -  B = -(A+B) -> + change symbol
			if (x_sym) sym = 1, op_index = 0; else
			//  A - -B = A + B  -> +
			if (y_sym) op_index = 0; break;
		case 2: sym = x_sym ^ y_sym; break;
		case 3: sym = x_sym ^ y_sym; break;
		default:o_ans -> setText("Compile Error: unknown operation(1)");return;
	}
	if (op_index == 1)
		if (cmp(s1, s2, x_len, y_len))
			sym = !sym, exchange(s1, s2, x_len, y_len);
			
	
	// calculate in op_index
	// origin: small -> big
	// after: small -> big
	// output: big -> small
	o_ans -> setText("Number is too large. Error code: 3");
	int len;
	QString bot;
	switch (op_index) {
		case 0:
			len = _add(s,s1,s2,x_len,y_len);
			if (z_index != 2)
				len = unitrans(s,o,moder[z_index],len),
				o_ans -> setText(getans(o,len,sym));
			else o_ans -> setText(getans(s,len,sym));
			break;
		case 1:
			len = _subtract(s,s1,s2,x_len,y_len);
			if (z_index != 2)
				len = unitrans(s,o,moder[z_index],len),
				o_ans -> setText(getans(o,len,sym));
			else o_ans -> setText(getans(s,len,sym));
			break;
		case 2:
			len = _multiply(s,s1,s2,x_len,y_len);
//	o_ans -> setText(QString::number(s[1])+' '+QString::number(s[2]));
//	o_ans -> setText(QString::number(len));
//	return;
			if (z_index != 2)
				len = unitrans(s,o,moder[z_index],len),
				o_ans -> setText(getans(o,len,sym));
			else o_ans -> setText(getans(s,len,sym));
			break;
		case 3:
			if (!y_len || (y_len == 1 && y_char[1] == '0')) {
				o_ans -> setText("Compile Error: divide by zero, you're suck in math");return;
			} else {
				len = _divide(s,s1,s2,x_len,y_len);
				if (z_index != 2)
					len = unitrans(s,o,moder[z_index],len),
					o_ans -> setText(getans(o,len,sym));
				else o_ans -> setText(getans(s,len,sym));
			}
			break;
		default:o_ans -> setText("Compile Error: unknown operation(2)");return;
	}
}
void TMainForm::slot_x() {}
void TMainForm::slot_y() {}
void TMainForm::slot_z() {}
void TMainForm::slot_c() {
	reset();
	i_x -> setText("");
	i_y -> setText("");
	o_ans -> setText("");
}
void TMainForm::slot_op() {}
