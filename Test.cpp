/*
9. ќпределить класс CIntN дл€ работы с целыми знаковыми числами,
состо€щими из N дес€тичных цифр, где N задаетс€ в конструкторе. ¬
классе должны быть определены необходимые конструкторы, деструктор,
операторы присваивани€, сложени€, вычитани€.
¬ отдельном файле должен быть написан тест на данный класс.
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
