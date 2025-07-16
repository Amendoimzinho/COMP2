#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa {
private:
    std::string Nome;
    Pessoa* Pai;
    Pessoa* Mae;
protected:
    static bool ehAncestral_rc(const Pessoa* p, const Pessoa* p2);
public:
    explicit Pessoa( const std::string &newNome, Pessoa* newPai = nullptr, Pessoa* newMae = nullptr);

    std::string getNome() const;
    Pessoa* getPai() const;
    Pessoa* getMae() const;

    bool ehSemanticamenteIgual(const Pessoa* p2) const;
    bool ehIrmaos(const Pessoa* p2) const;
    bool ehAncestral(const Pessoa* p2) const;

    ~Pessoa();
};
#endif