#ifndef LISTAS_H
#define LISTAS_H

#include <iostream>

/// @brief Cria uma fila encadeada
/// @tparam T Um tipo qualquer
template <typename T>
class Fila {
    protected:
    class Node {
        private:
        T info;
        Node* Prox;

        public:
        Node(const T& newInfo) {info = newInfo ;Prox = nullptr;}

        T getInfo () const {
            return info;
        }

        Node* getProx () const {
            return Prox;
        }
        
        void enqueue_N (const T& newInfo) {
            if (Prox == nullptr)
                Prox = new Node(newInfo);
            else
                Prox->enqueue_N(newInfo);
        };

        void dequeue_N (Node*& Head) {
            Node* aux = Head;
            if (Head != nullptr) Head = Prox;
            delete aux;
        }

    };

    Node* Head;

    public:

    Fila() {
        Head = nullptr;
    }

    Fila(const T& newInfo) {
        Head = new Node(newInfo);
    }

    void enqueue (const T& newInfo) {
        if(!empty())
            Head->enqueue_N(newInfo);
        else
            Head = new Node(newInfo);
    }

    void dequeue () {
        Head->dequeue_N(Head);
    }

    T peek () const {
        return Head->getInfo();
    }

    bool empty () {
        return Head==nullptr;
    }

    void show () {
        Node* aux = Head;
        while (aux) {
            std::cout<<aux->getInfo()<<std::endl;
            aux = aux->getProx();
        }
    }

    ~Fila() {
        while(!empty()) {
            dequeue();
        }
    }
};

/// @brief Cria uma lista ordenada
/// @tparam X Precisa ter '>=' implementado!
template <typename X>
class ListaOrdenada {
    protected:
    class Node {
        private:
        X info;
        Node* Prox;

        void rmv (Node*& node) {
            Node* aux = node;
            node = node->Prox;
            delete aux;
        }

        public:

        Node(const X& newInfo, Node* newProx=nullptr) {
            info = newInfo;
            Prox = newProx;
        }

        X getInfo () const {
            return info;
        }

        Node* getProx () const {
            return Prox;
        }

        void add_N (const X& newInfo, Node*& node) {
            if (node == nullptr || node->info >= newInfo)
                node = new Node(newInfo, node);
            else
                node->add_N(newInfo, node->Prox);
        }

        void remove_N (const X& rmvInfo, Node*& node) {
            if(node == nullptr) return;
            if (node->info == rmvInfo)
                rmv(node);
            else
                remove_N(rmvInfo, node->Prox);
        }
    };

    Node* Head;

    public:

    ListaOrdenada() {
        Head = nullptr;
    }

    bool empty () const {
        return Head==nullptr;
    }

    void add (const X& newInfo) {
        if (!empty())
            Head->add_N(newInfo,Head);
        else
            Head = new Node(newInfo);
    }

    void remove (const X& rmvInfo) {
        Head->remove_N(rmvInfo,Head);
    }

    void show () const {
        Node* aux = Head;
        while(aux) {
            std::cout<< aux->getInfo() << std::endl;
            aux = aux->getProx();
        }
    }

    ~ListaOrdenada() {
        while(!empty()) {
            remove(Head->getInfo());
        }
    }
};

#endif
