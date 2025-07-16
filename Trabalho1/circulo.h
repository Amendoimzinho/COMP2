
#ifndef CIRCULO_H
#define CIRCULO_H
#include "ponto.h"

class Circulo : public Ponto {
private:
    double r;
public:
    Circulo();
    Circulo(double x, double y, double r);

    void aumentar();
    void aumentar(double plusX);

    void diminuir();
    void diminuir(double minusX);

    double getArea();
    double getPerimetro();

    void setR(double r);
    double getR();

    void mostrar();

    ~Circulo();

};

#endif //CIRCULO_H
