#ifndef CONTADOR_H
#define CONTADOR_H

class Contador {
protected:
    int contador;
public:

    //Construtor
    explicit Contador(int newC=0);

    // Zera o contador
    // Pre: Nenhuma
    // Pos: 'contador' = 0;
    void zerar();

    // Incrementa 'contador' em 'incC'
    // Pre: 'incC' eh um int
    // Pos: 'contador' aumenta em 'incC'
    //      Retorna o novo valor de 'contador'
    int incrementar(int incC=1);

    // Pega o valor do contador
    // Pre: Nenhuma
    // Pos: Retorna o valor de 'contador'
    [[nodiscard]] int getC() const;

    // Destrutor
    ~Contador();
};

#endif
