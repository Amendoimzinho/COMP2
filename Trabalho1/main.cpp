#include <iostream>
#include "circulo.h"

using namespace std;

void editar();

int main() {
    Circulo circulo(5, 5, 3);
    Ponto ponto(7, 6);
    char resp;

    circulo.mostrar();

    circulo.setX(8);
    cout << "X: " << circulo.getX() << endl;

    circulo.setY(3.12);
    cout << "Y: " << circulo.getY() << endl;

    circulo.setR(3.5);
    cout << "Raio: " << circulo.getR() << endl;

    circulo.aumentar(10);
    cout << "Raio: " << circulo.getR() << endl;

    circulo.aumentar();
    cout << "Raio: " << circulo.getR() << endl;

    circulo.mostrar();

    circulo.move(ponto);
    cout << ponto.mostrar() << endl;

    circulo.mostrar();

    cout << "Area: " << circulo.getArea() << endl;
    cout << "Perimetro: " << circulo.getPerimetro() << endl;

    return 0;
}

