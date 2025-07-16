#include <iostream>
#include <cmath>
#include "circulo.h"

Circulo::Circulo() {
    this->y = 0;
    this->x = 0;
    this->r = 0;
}

Circulo::Circulo(const double x, const double y, const double r) {
    this->y = y;
    this->x = x;
    this->r = r;
}
void Circulo::aumentar() {
    this->r++;
}

void Circulo::aumentar(const double plusX) {
    this->r += plusX;
}
void Circulo::diminuir() {
    this->r--;
}

void Circulo::diminuir(const double minusX) {
    if ((this->r - minusX <= 0)) return;
    this->r -= minusX;
}

double Circulo::getArea() {
    return M_PI * this->r * this->r;
}

double Circulo::getPerimetro() {
    return 2 * M_PI * this->r;
}

void Circulo::setR(double r) {
    this->r = r;
}


double Circulo::getR() {
    return this->r;
}

void Circulo::mostrar() {
    std::cout << "Centro: (" <<this->x << ", " << this->y << ") | Raio: " << this->r << std::endl;
}

Circulo::~Circulo() {
    std::cout << "Circulo Destruido" << std::endl;
}



