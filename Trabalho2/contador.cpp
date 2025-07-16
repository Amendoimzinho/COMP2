#include <iostream>
#include "contador.h"

Contador::Contador(const int newC) {
    this->contador = newC;
    std::cout << "Contador Criado\n";
}

void Contador::zerar() {
    this->contador = 0;
}

int Contador::incrementar(const int incC) {
    this->contador += incC;
    return getC();
}

int Contador::getC() const {
    return this->contador;
}

Contador::~Contador() {
    std::cout << "Contador Deletado\n";
}

