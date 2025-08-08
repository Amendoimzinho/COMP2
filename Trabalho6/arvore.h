#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>

using namespace std;

template <typename T>
class ArvoreBusca {
protected:
    T info;
    ArvoreBusca* right;
    ArvoreBusca* left;

    ArvoreBusca(T newInfo) {
        info = newInfo;
        right = nullptr;
        left = nullptr;
    }

    
    static T getHighLow (ArvoreBusca*& node) {
        if (node->right==nullptr) return node->info;
        else return getHighLow (node->right);
    }
    
    static T getLowHigh (ArvoreBusca*& node) {
        if (node->left==nullptr) return node->info;
        else return getLowHigh (node->left);
    }

    public: 
    
    static void add (const T& newInfo, ArvoreBusca*& node) {
        if (node == nullptr)
            node = new ArvoreBusca (newInfo); 
        else if (newInfo >= node->info)
            add(newInfo, node->right);
        else
            add(newInfo, node->left);
    }

    static void remove (const T& rmvInfo, ArvoreBusca*& node) {
        if (node == nullptr) return;

        if (rmvInfo > node->info)
            remove (rmvInfo, node->right);

        else if (rmvInfo < node->info)
            remove (rmvInfo, node->left);
        
        else if (node->info == rmvInfo) {
            if (node->right==nullptr && node->left==nullptr){
                delete node;
                node = nullptr;
            }
            else if (node->left==nullptr) {
                node->info = getLowHigh(node->right);
                remove (node->info, node->right);
            }
            else {
                node->info = getHighLow(node->left);
                remove (node->info, node->left);
            }
        }
    }

    void show () {
        if(left) left->show();
        cout << info << endl;
        if(right) right->show();
    }
};

#endif