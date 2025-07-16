#include <iostream>
#include "contador.h"

int main() {
    Contador X; // Cria X com 'contador' = 0
    Contador Y(15); // Cria Y com 'contador' = 15

    std::cout << X.getC() << " - " << Y.getC() << std::endl; // Valores de X e Y
    std::cout << X.incrementar(5) << " - " << Y.incrementar() << std::endl; // Incrementando valores
    Y.zerar(); // Zerando Y
    std::cout << X.incrementar(-3) << " - " << Y.getC() << std::endl; //
    return 0;
}