#ifndef VETOR_H
#define VETOR_H


#define MAX_SIZE 100

/**
 * @author Noam Daniel Wandscheer Brecher
 * @file 'vetor.h'
 * @class Vetor
 * @brief Cria um vetor de MAX_SIZE (100)
*/
template <typename T>
class Vetor {
    private:
    T elementos[MAX_SIZE];
    int topo;

    public:

/**
 * @brief Construtora
 * @post Topo iniciado com 0
*/
    Vetor() {
        this->topo = 0;
    }

/**
 * @brief Construtora de Copia
 * @param vetor Vetor a seu copiado
 * @pre 'vetor' eh valido 
 * @post Novo Vetor eh a copia de 'vetor'
*/
    Vetor(const Vetor& vetor) {
        this->topo = vetor.topo;

        for(int i = 0; i < vetor.topo; i++) {
            this->elementos[i] = vetor.elementos[i];
        }
    }

/**
 * @brief Destrutora 
 * @post Vetor destruido
*/
    ~Vetor(){}

/**
 * @brief Retorna o tamanho do vetor
 * @return Retorna o tamanho
*/
    int size() const {
        return this->topo;
    }

/**
 * @brief Adiciona 'valor' no elemento de 'index'
 * @param index Um inteiro
 * @param valor Um novo valor do tipo 'T'
 * @post 'index' atualizado com a soma
 * @throws 'const char*' se 'index' esta fora do escopo
*/
    void add(int index, const T& valor) {
        if(index < 0 || index >= this->topo) throw  "Fora do Escopo";
        this->elementos[index] += valor;
    }

/**
 * @brief Retorna o valor em 'index'
 * @param index Um inteiro
 * @return Retorna o valor em 'index'
 * @throws 'const char*' se 'index' esta fora do escopo
*/
    T& at(int index) const {
        if(index < 0 || index >= this->topo) throw  "Fora do Escopo";

        return elementos[index];
    }

/**
 * @brief Adiciona um valor no final de 'elementos'
 * @param valor Um valor do tipo 'const T'
 * @post Valor adicionado no final e topo atualizado
 * @throws 'const char*' se o vetor estiver cheio
*/
    void push(const T& valor) {
        if (topo >= MAX_SIZE) throw  "Tamanho Excedido";

        this->elementos[this->topo++] = valor;
    }

/**
 * @brief Retorna o valor em 'index'
 * @param index Um inteiro
 * @return Retorna o valor em 'index'
 * @throws 'const char*' se 'index' esta fora do escopo
*/
    T& operator[](int index) const {
        return this->at(index);
    }

/**
 * @brief Adiciona um valor no final de 'elementos'
 * @param valor Um valor do tipo 'const T'
 * @post Valor adicionado no final e topo atualizado
 * @throws 'const char*' se o vetor estiver cheio
*/
    void operator+=(const T& valor) {
        this->push(valor);
    }


/**
 * @brief Sobreescreve o Vetor atual com o novo Vetor
 * @param vetor Um 'Vetor' valido
 * @post Vetor atual eh uma copia de 'vetor'
*/
    Vetor& operator=(const Vetor& vetor) {
        if (this == &vetor) return *this;

        this->topo = vetor.topo;

        for(int i = 0; i < vetor.topo; i++) {
            this->elementos[i] = vetor.elementos[i];
        }
        return *this;
    }

/**
 * @brief Imprime o Vetor atual
 * @post Vetor atual eh impresso no terminal
*/
    void show() const {
        for (int i = 0; i < this->topo; i++)
            std::cout << elementos[i] << ' ';
        std::cout << std::endl;
    }
};

#endif