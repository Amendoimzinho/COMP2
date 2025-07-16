#include <iostream>
#include "vetor.h"

int main() {
    Vetor<int> v1;

    v1 += 0;
    v1 += 1;
    v1 += 2;

    v1.push(18);
    v1.push(19);

    v1.show();

    Vetor<int> v2(v1);

    v2.add(0, 15);

    v2.show();

    v1 = v2;

    v1.show();
}