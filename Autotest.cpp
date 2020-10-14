#include "CIntN.h"

int Autotest() {
	int n[2], m[2];
	n[0] = 2;
	n[1] = 5;
	m[0] = 1;
	m[1] = 9;
	CIntN A(2, true, n);
	CIntN B(2, false, m);
	CIntN C = A + B;
	int* l = C.GetIntN();
	if (l[0] != 0 || l[1] != 6) {
		return 1;
	}
	bool h = C.GetSign();
	if (h != true) {
		return 1;
	}
	
	C = A - B;
	l = C.GetIntN();
	if (l[0] != 4 || l[1] != 4) {
		return 1;
	}
	h = C.GetSign();
	if (h != true) {
		return 1;
	}
	return 0;
}