#ifndef GERENTE_H
#define GERENTE_H

#include "funcionario.h"

using namespace std;

class Gerente : public Funcionario {
    private:
    double bonusAnual;

    public:

    Gerente(string newName = "", double newSalario = 0, int bonus = 0) : Funcionario(newName, newSalario) {
        bonusAnual = bonus;
    }

    double calcularSalario() override {
        return salarioBase + bonusAnual / 12;
    }

    void exibirInfo() override {
        cout << endl
             << "Nome: " << nome << endl
             << "Tipo: Gerente" << endl
             << "Salario:" << calcularSalario() << endl;
    }

    ~Gerente() override {}
};

#endif