#ifndef MATRIZ_H
#define MATRIZ_H

#define MAX_SIZE 5
#include <iostream>

class Matriz {
private:
    int M[MAX_SIZE][MAX_SIZE]{};
    int Linhas;
    int Colunas;
public:
    explicit Matriz(int L=MAX_SIZE, int C = MAX_SIZE);

    Matriz& operator=(const Matriz& newM);
    Matriz operator+(const Matriz &newM) const;
    Matriz operator-(const Matriz& newM) const;
    Matriz operator*(const Matriz& newM) const;
    Matriz operator*(int newI) const;
    Matriz& operator+=(const Matriz &newM);
    Matriz& operator-=(const Matriz &newM);
    Matriz& operator*=(const Matriz& newM) ;
    Matriz& operator*=(int newI);
    bool operator==(const Matriz& newM) const;
    friend std::istream& operator>>(std::istream& is, Matriz& newM);
    friend std::ostream& operator<<(std::ostream& os, const Matriz& newM);

    int getL() const;
    int getC() const;
    int getItem(int Linha, int Coluna) const;

    void setItem(int Linha, int Coluna, int newV);

    Matriz getTransposta() const;
    Matriz getOposta() const;
    Matriz getCopia(); // Não entendi :(
    // int getDeterminante() const;

    bool ehQuadrada() const;
    bool ehIdentidade() const;
    bool ehDiagonal() const;
    // bool ehSingular();
    // bool ehSimetrica();
    // bool ehAntiSimetrica();
};

#endif //MATRIZ_H
