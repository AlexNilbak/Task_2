#pragma once

int Autotest();

class CIntN {
	int N;
	int* IntN;
	bool sign;
public:
	CIntN();
	CIntN(int, bool, int*);
	~CIntN();
	CIntN(const CIntN&);
	int GetN();
	int* GetIntN();
	bool GetSign();
    CIntN operator+(const CIntN&);
    CIntN operator-(const CIntN&);
    CIntN &operator=(const CIntN&);
    void Clean();
    void Reset();
    void Copy(const CIntN&);
};

