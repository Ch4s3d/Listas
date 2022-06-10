#ifndef LIST_H
#define LIST_H

#include <cstdlib>
#include <limits>
#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;

class Node {

    int _value;

    Node* next;
    Node* prev;

public:
    Node(int _value){
        this->_value = _value;
        this->next = nullptr;
        this->prev = nullptr;
    }

    int GetValue(){
        return this->_value;
    }

    void SetNext(Node* nodo) {
        this->next = nodo;
    }

    Node* GetNext() {
        return this->next;
    }

    void SetPrev(Node* nodo) {
        this->prev = nodo;
    }

    Node* GetPrev() {
        return this->prev;
    }
};


class List {
    int cont;
    Node* first;
    Node* last;

    public:
        List() {
            this->cont = 0;
            this->first = nullptr;
            this->last = nullptr;
        }

        bool AddLast(int number) {
            Node* nodo = new Node(number);

            if (this->first == nullptr) {
                this->first = nodo;
                this->last = nodo;
            }
            else {

                this->last->SetNext(nodo);
                nodo->SetPrev(this->last);
                this->last = nodo;
            }
            cout << "Added: " << number << endl;
            this->cont++;

            return true;
        }

        bool Delete(int a){

            return true;
        }

        void PrintAll(){

            int n = 1;

            if(this->first == nullptr)
                return;

            Node* index = this->first;
            while(index != nullptr){
                cout << n << ": " << index->GetValue() << endl;
                index = index->GetNext();
                n++;
            }
        }
};



#endif // LIST_H
