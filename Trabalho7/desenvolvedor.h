#ifndef DESENVOLVEDOR_H
#define DESENVOLVEDOR_H

#include "funcionario.h"

using namespace std;

class Desenvolvedor : public Funcionario {
    private:
    int qntProjetos;

    public:

    Desenvolvedor(string newName = "", double newSalario = 0, int qntProj = 0) : Funcionario(newName, newSalario) {
        qntProjetos = qntProj;
    }

    double calcularSalario() override {
        return salarioBase + 500 * qntProjetos;
    }

    void exibirInfo() override {
        cout << endl
             << "Nome: " << nome << endl
             << "Tipo: Desenvolvedor" << endl
             << "Salario:" << calcularSalario() << endl;
    }

    ~Desenvolvedor() override {}
};

#endif