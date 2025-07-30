#include "listas.h"

int main() {
    ListaOrdenada<int> B;

    B.add(1);
    B.add(5);
    B.add(3);
    B.add(18);
    B.add(0);

    B.remove(3);

    B.add(7);
    B.add(7);
    B.add(7);
    B.add(-23);
    B.add(54);

    B.remove(7);
    B.remove(1);

    B.show();
}