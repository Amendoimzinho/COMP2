#include "desenvolvedor.h"
#include "gerente.h"
#include "funcionario.h"

using namespace std;

int main() {
    Funcionario *F1 = new Gerente("um", 10000, 2000),
                *F2 = new Desenvolvedor("dois", 1000, 5),
                *F3 = new Gerente("tres", 15000, 2500),
                *F4 = new Desenvolvedor("quatro", 1500, 10);

    cout << F1->nFuncionarios() << endl;

    F1->exibirInfo();
    F2->exibirInfo();
    F3->exibirInfo();
    F4->exibirInfo();

}