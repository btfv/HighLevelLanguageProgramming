
#include <iostream>
#include "id_string.h"
#include "decimal_string.h"
int main()
{
    string** x = new string*[3];
    x[0] = new id_string("dsd_");
    x[1] = new decimal_string("125125512");
    for (int i = 0; i < 3; i++) {
        std::cout << *x[i] << "\n";
    }
    return 0;
}