/*
9. ���������� ����� CIntN ��� ������ � ������ ��������� �������,
���������� �� N ���������� ����, ��� N �������� � ������������. �
������ ������ ���� ���������� ����������� ������������, ����������,
��������� ������������, ��������, ���������.
� ��������� ����� ������ ���� ������� ���� �� ������ �����.
*/
#include <iostream>
//#include <fstream>
#include "CIntN.h"
using namespace std;

int main(void) {
    int k;
    k = Autotest();
    if (k != 0) {
        cout << "Autotest failed\n" << endl;
        return 1;
    }
    else {
        cout << "Autotest passed" << endl;
    }
    return 0;
}
