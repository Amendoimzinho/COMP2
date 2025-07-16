#include <iostream>
#include "pessoa.h"

Pessoa::Pessoa(const std::string &newNome, Pessoa* newPai, Pessoa* newMae){
    std::cout << "Criando 'Pessoa'\n";
    this->Nome = newNome;
    this->Pai = newPai;
    this->Mae = newMae;
}

std::string Pessoa::getNome() const{
    return this->Nome;
}

Pessoa* Pessoa::getPai() const{
    return this->Pai;
}

Pessoa* Pessoa::getMae() const{
    return this->Mae;
}

bool Pessoa::ehSemanticamenteIgual(const Pessoa* p2) const {
    if(this->Nome == p2->getNome())
        if(this->Mae && p2->getMae())
            if(this->Mae->Nome == p2->getMae()->getNome())
                return true;
    return false;
}

bool Pessoa::ehIrmaos(const Pessoa* p2) const {
    if(this->Nome != p2->getNome())
        if(this->Pai && p2->getPai())
            if(this->Mae && p2->getMae())
                if (this->Pai->Nome == p2->getPai()->getNome() ||
                    this->Mae->Nome == p2->getMae()->getNome())
                    return true;
    return false;
}

bool Pessoa::ehAncestral(const Pessoa* p2) const {
    bool Result = false;

    if(this->Nome == p2->getNome()) return Result;

    if(this->Mae)
        Result = ehAncestral_rc(this->Mae, p2);

    if(!Result && this->Pai)
        Result = ehAncestral_rc(this->Pai, p2);

    return Result;

}

bool Pessoa::ehAncestral_rc(const Pessoa* p, const Pessoa* p2){
    bool Result = false;
    if(p->getNome() == p2->getNome()) return true;
    if(p->getMae())
        Result = ehAncestral_rc(p->getMae(), p2);
    if(!Result && p->getPai())
        Result = ehAncestral_rc(p->getPai(), p2);
    return Result;
}

Pessoa::~Pessoa() {
    std::cout << "Deletando 'Pessoa'\n";
}
