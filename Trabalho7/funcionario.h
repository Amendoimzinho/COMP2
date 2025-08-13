#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include <string>

using namespace std;

class Funcionario {
    private:
    static int qntFuncionarios;

    protected:
    string nome;
    double salarioBase;

    public:

    Funcionario(string newName = "", double newSalario = 0) {
        nome = newName;
        salarioBase = newSalario;
        qntFuncionarios++;
    }

    virtual double calcularSalario()  = 0;

    virtual void exibirInfo() = 0;

    static int nFuncionarios() {
        return qntFuncionarios;
    }

    virtual ~Funcionario() {
        qntFuncionarios--;
    }
};

int Funcionario::qntFuncionarios = 0;

#endif