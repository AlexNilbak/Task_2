#include "CIntN.h"
#include <iostream>
#include <string.h>
using namespace std;

CIntN::CIntN() {
    Reset();
}
CIntN::CIntN(int N, bool sign, int* IntN) {
    this->IntN = new int[N];
    this->N = N;
    this->sign = sign;
    for (int i = 0; i < N; i++) {
        this->IntN[i] = IntN[i];
    }
}
CIntN::~CIntN(){
   Clean();
}
CIntN::CIntN(const CIntN& b){
    Copy(b);
}
int CIntN::GetN() {
    return N;
}
int* CIntN::GetIntN() {
    return IntN;
}
bool CIntN::GetSign() {
    return sign;
}
CIntN CIntN::operator+(const CIntN& b){
    if (N != b.N) {
        cout << "Error: numbers of different sizes" << endl;
        throw - 1;
    }
    int* m = new int[N];
    CIntN A(N, true, m);
    int k = 0;
    if (sign == b.sign) {
        A.sign = sign;
        for (int i = N-1; i >= 0; i--) {
            A.IntN[i] = IntN[i] + b.IntN[i];
            if (k == 1) {
                A.IntN[i]++;
                k = 0;
            }
            if (A.IntN[i] > 9) {
                A.IntN[i] = A.IntN[i] -10;
                k = 1;
            }
        }
        if (k == 1) {
            cout << "Error: result exceeds the limit" << endl;
            throw - 2;
        }
        return A;
    }
    if (sign != b.sign) {
        int t = 0;
        for (int i = 0; i < N; i++) {
            if (t == 0) {
                if (IntN[i] > b.IntN[i]) {
                    t = 1;
                }
                if (IntN[i] < b.IntN[i]) {
                    t = 2;
                }
            }
        }
        if (t == 0) {
            for (int i = 0; i < N; i++) {
                A.IntN[i] = 0;
            }
        }
        if (t == 1) {
            CIntN d(N, b.sign, IntN);
            A = d - b;
            A.sign = sign;
        }
        if (t == 2) {
            CIntN d(N, b.sign, IntN);
            A = d - b;
            A.sign = b.sign;
        }
        return A;
    }
}
CIntN CIntN::operator-(const CIntN& b){
    if (N != b.N) {
        cout << "Error: numbers of different sizes" << endl;
        throw - 1;
    }
    int* m = new int[N];
    CIntN A(N, true, m);
    int k = 0;


    if (sign != b.sign) {
        CIntN d(N, b.sign, IntN);
        A = d + b;
        A.sign = sign;
    }
    if (sign == b.sign) {
        int t = 0;
        for (int i = 0; i < N; i++) {
            if (t == 0) {
                if (IntN[i] > b.IntN[i]) {
                    t = 1;
                }
                if (IntN[i] < b.IntN[i]) {
                    t = 2;
                }
            }
        }
        if (t == 0) {
            for (int i = 0; i < N; i++) {
                A.IntN[i] = 0;
            }
        }
        int k = 0;
        int f = 0;
        if (t == 1) {
            A.sign = sign;
            f = 1;
        }
        if (t == 2) {
            A.sign = !sign;
            f = -1;
        }
        for (int i = N - 1; i >= 0; i--) {
            A.IntN[i] = (IntN[i] - b.IntN[i])*f;
            if (k == 1) {
                A.IntN[i]--;
                k = 0;
            }
            if (A.IntN[i] < 0) {
                A.IntN[i] = 10 + A.IntN[i];
                k = 1;
            }
        }
    }
    return A;
}
CIntN& CIntN::operator=(const CIntN& b){
    if(this!=&b){
        Clean();
        Copy(b);
    }
    return *this;
}
void CIntN::Clean(){
    delete[] IntN;
    Reset();
}
void CIntN::Reset(){
    IntN=NULL;
    N=0;
}
void CIntN::Copy(const CIntN& b){
    N = b.N;
    sign = b.sign;
    IntN = new int[N];
    for (int i = 0; i < N; i++) {
        IntN[i] = b.IntN[i];
    }
}

