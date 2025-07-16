#include "matriz.h"

#include <iostream>
#include <iomanip>
#include <pstl/glue_execution_defs.h>

Matriz::Matriz(const int L, const int C) {
    if (L > MAX_SIZE || C > MAX_SIZE || L < 0 || C < 0)
        throw std::invalid_argument("Tamanho Maior Que Permitido\n");
    this->Linhas = L;
    this->Colunas = C;
}

            /*  OPERADORES  */

Matriz &Matriz::operator=(const Matriz &newM) {
    if (this != &newM) {
        this->Linhas = newM.Linhas;
        this->Colunas = newM.Colunas;
        for (int i = 0 ; i < this->Linhas ; i++)
            for (int j = 0 ; j < this->Colunas ; j++)
                this->M[i][j] = newM.getItem(i,j);
    }
    return *this;
}

Matriz Matriz::operator+(const Matriz &newM) const {
    if (this->Linhas != newM.getL() || this->Colunas != newM.getC())
        throw std::invalid_argument("Tamanhos Incompativeis");
    Matriz Res(this->Linhas,this->Colunas);
    for (int i = 0 ; i < this->Linhas ; i++)
        for (int j = 0 ; j < this->Colunas ; j++)
            Res.setItem(i,j, this->M[i][j] + newM.getItem(i,j));
    return Res;
}

Matriz Matriz::operator-(const Matriz &newM) const {
    if (this->Linhas != newM.getL() || this->Colunas != newM.getC())
        throw std::invalid_argument("Tamanhos Incompativeis");
    Matriz Res(this->Linhas,this->Colunas);
    for (int i = 0 ; i < this->Linhas ; i++)
        for (int j = 0 ; j < this->Colunas ; j++)
            Res.setItem(i,j, this->M[i][j] - newM.getItem(i,j));
    return Res;
}

Matriz Matriz::operator*(const Matriz &newM) const {
    if (this->Colunas != newM.getL())
        throw std::invalid_argument("Tamanhos Incompativeis");

    Matriz Res(this->Linhas, newM.Colunas);

    for (int i = 0 ; i < this->Linhas ; i++)
        for (int j = 0; j < newM.getC() ; j++) {
            int Aux = 0;
            for (int k = 0; k < this->Colunas ; k++) {
                Aux += this->M[i][k] * newM.getItem(k,j);
            }
            Res.M[i][j] = Aux;
        }

    return Res;
}

Matriz Matriz::operator*(const int newI) const {
    Matriz Aux(this->Linhas, this->Colunas);
    for (int i = 0 ; i < this->Linhas ; i++)
        for (int j = 0 ; j < this->Colunas ; j++)
            Aux.M[i][j] = this->M[i][j] * newI;
    return Aux;
}

Matriz& Matriz::operator+=(const Matriz &newM) {
    if (this->Linhas != newM.Linhas || this->Colunas != newM.Colunas)
        throw std::invalid_argument("Tamanhos Incompativeis");

    for (int i = 0 ; i < this->Linhas ; i++)
        for (int j = 0 ; j < this->Colunas ; j++)
            M[i][j] += newM.M[i][j];
    return *this;
}

Matriz& Matriz::operator-=(const Matriz &newM) {
    if (this->Linhas != newM.Linhas || this->Colunas != newM.Colunas)
        throw std::invalid_argument("Tamanhos Incompativeis");

    for (int i = 0 ; i < this->Linhas ; i++)
        for (int j = 0 ; j < this->Colunas ; j++)
            M[i][j] -= newM.M[i][j];
    return *this;
}

Matriz& Matriz::operator*=(const Matriz &newM) {
    if (this->Colunas != newM.Linhas)
        throw std::invalid_argument("Tamanhos Incompativeis");

    Matriz Res(this->Linhas, newM.Colunas);

    for (int i = 0 ; i < this->Linhas ; i++)
        for (int j = 0; j < newM.Colunas ; j++) {
            int Aux = 0;
            for (int k = 0; k < this->Colunas ; k++) {
                Aux += this->M[i][k] * newM.M[k][j];
            }
            Res.M[i][j] = Aux;
        }

    this->Linhas = Res.Linhas;
    this->Colunas = Res.Colunas;
    for (int i = 0 ; i < this->Linhas ; i++)
        for (int j = 0 ; j < this->Colunas ; j++)
            this->M[i][j] = Res.M[i][j];

    return *this;
}

Matriz& Matriz::operator*=(const int newI) {
    for (int i = 0 ; i < this->Linhas ; i++)
        for (int j = 0 ; j < this->Colunas ; j++)
            this->M[i][j] *= newI;
    return *this;
}

bool Matriz::operator==(const Matriz &newM) const {
    if (this->Colunas == newM.Colunas && this->Linhas == newM.Linhas) {
        for (int i = 0 ; i < this->Linhas ; i++)
            for (int j = 0; j < this->Colunas ; j++)
                if (this->M[i][j] != newM.M[i][j])
                    return false;
        return true;
    }
    return false;
}

std::istream& operator>>(std::istream& is, Matriz& newM) {
    for (int i = 0 ; i < newM.Linhas ; i++)
        for (int j = 0; j < newM.Colunas ; j++)
            is >> newM.M[i][j];
    return is;
}

std::ostream& operator<<(std::ostream& os, const Matriz& newM) {
    for (int i = 0 ; i < newM.Linhas ; i++) {
        for (int j = 0; j < newM.Colunas ; j++)
            os << newM.M[i][j] << " ";
        os << std::endl;
    }
    return os;
}

/*  METODOS  */

int Matriz::getL() const {
    return this->Linhas;
}

int Matriz::getC() const {
    return this->Colunas;
}

int Matriz::getItem(const int Linha, const int Coluna) const {
    if (Linha > this->Linhas || Coluna > this->Colunas || Linha < 0 || Coluna < 0)
        throw std::out_of_range("Valor Inacessivel\n");
    return this->M[Linha][Coluna];
}

void Matriz::setItem(const int Linha, const int Coluna, const int newV) {
    if (Linha > this->Linhas || Coluna > this->Colunas || Linha < 0 || Coluna < 0)
        throw std::out_of_range("Valor Inacessivel\n");
    this->M[Linha][Coluna] = newV;
}

Matriz Matriz::getTransposta() const {
    Matriz Aux(this->Colunas, this->Linhas);
    for (int i = 0 ; i < this->Linhas ; i++)
        for (int j = 0; j < this->Colunas ; j++)
            Aux.M[j][i] = this->M[i][j];
    return Aux;
}

Matriz Matriz::getOposta() const {
    return *this * -1;
}

Matriz Matriz::getCopia() {
    return *this;
}

// int Matriz::getDeterminante() {
//
// }

bool Matriz::ehQuadrada() const {
    return this->Linhas == this->Colunas;
}

bool Matriz::ehIdentidade() const {
    if (!this->ehQuadrada()) return false;

    for (int i = 0 ; i < this->Linhas ; i++)
        for (int j = 0; j < this->Colunas ; j++) {
            if (i == j){ if (this->M[i][j] != 1) return false;}
            else         if (this->M[i][j] != 0) return false;
        }

    return true;
}

bool Matriz::ehDiagonal() const{
    if (!this->ehQuadrada()) return false;

    for (int i = 0 ; i < this->Linhas ; i++)
        for (int j = 0; j < this->Colunas ; j++) {
            if (i == j){ if (!this->M[i][j]) return false;}
            else         if (this->M[i][j] != 0) return false;
        }

    return true;
}

//
// bool Matriz::ehSingular() {
// }
//
// bool Matriz::ehSimetrica() {
// }
//
// bool Matriz::ehAntiSimetrica() {
//     }



