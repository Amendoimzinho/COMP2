#include <iostream>
#include "pessoa.h"

using namespace std;

int main() {
    auto Bisa1 = new Pessoa("Bisavo1");
    auto Bisa2 = new Pessoa("Bisavo2");

    auto Avo1 = new Pessoa("Avo1", Bisa1, Bisa2);
    auto Avo2 = new Pessoa("Avo2", Bisa1);
    auto Avo3 = new Pessoa("Avo3");

    auto Pai1 = new Pessoa("Pai1", Avo1, Avo3);
    auto Pai2 = new Pessoa("Pai2", nullptr, Avo2);
    auto Pai3 = new Pessoa("Pai3");

    auto Pessoa1 = new Pessoa("Pessoa1", Pai1, Pai3);
    auto Pessoa2 = new Pessoa("Pessoa1", Pai1, Pai3);
    auto Pessoa3 = new Pessoa("Pessoa3");


    cout << Pessoa1->ehIrmaos(Pessoa2) << endl;

    cout << Pessoa1->getMae()->getNome() << endl;

    cout <<Avo1->getPai()->getNome() << endl;

    cout << Pessoa1->ehAncestral(Avo3) << endl;

    cout << Pessoa1->ehAncestral(Avo2) << endl;

    cout << Pessoa2->ehAncestral(Bisa1) << endl;

    cout << Pessoa2->ehSemanticamenteIgual(Pessoa1) << endl;

    delete Bisa1;
    delete Bisa2;
    delete Avo1;
    delete Avo2;
    delete Avo3;
    delete Pai1;
    delete Pai2;
    delete Pai3;
    delete Pessoa1;
    delete Pessoa2;
    delete Pessoa3;
}