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

        //-----------------ADD

        bool AddFirst(int number) {
            Node* nodo = new Node(number);

            if (this->first == nullptr) {
                this->first = nodo;
                this->last = nodo;
            }
            else {

                this->first->SetPrev(nodo);
                nodo->SetNext(this->first);
                this->first = nodo;
            }
            //cout << "Added: " << number << endl;
            this->cont++;

            return true;
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
            //cout << "Added: " << number << endl;
            this->cont++;

            return true;
        }

        //------------------GET

        Node* GetFirst(){
            return this->first;
        }
        Node* GetLast(){
            return this->last;
        }



        //------------------SEARCH

        Node* SearchByValue(int _value){
            Node* indexNode = this->first;
            int i = 1;

            while (indexNode != nullptr){
                if(indexNode->GetValue() == _value)
                    return indexNode;
                indexNode=indexNode->GetNext();
                i++;
            }

            return nullptr;
        }

        Node* SearchByPosition(int position){
            Node* indexNode = this->first;

            for (int i=0 ; i<=position ; i++){
                if(indexNode == nullptr)
                    return nullptr;
                indexNode=indexNode->GetNext();
            }
            return indexNode;
        }

        int SearchGetPosition(int _value){
            Node* indexNode = this->first;
            int i = 1;

            while (indexNode != nullptr){
                if(indexNode->GetValue() == _value)
                    return i;
                indexNode=indexNode->GetNext();
                i++;
            }

            return -1;
        }

        int SearchGetValue(int position){
            Node* indexNode = this->first;

            for (int i=0 ; i<=position ; i++){
                if(indexNode == nullptr)
                    return -1;
                indexNode=indexNode->GetNext();
            }
            return indexNode->GetValue();
        }

        //------------------PRINT

        void Print(string caption, Node* nodo){
            cout << caption << nodo->GetValue() << endl;
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

        //------------------DELETE

        bool Delete(Node* node){
            if(node == nullptr)
                return false;

            if(node->GetPrev() == nullptr){
                this->first = node->GetNext();
                this->first->SetPrev(nullptr);
                delete node;
            }

            else if(node->GetNext() == nullptr){
                this->last = node->GetPrev();
                this->last->SetNext(nullptr);
                delete node;
            }

            else if(node->GetNext() == nullptr && node->GetPrev() == nullptr){
                this->first = nullptr;
                this->last = nullptr;
                delete node;
            }

            else{
                node->GetPrev()->SetNext(node->GetNext());
                node->GetNext()->SetPrev(node->GetPrev());
                delete node;
            }

            this->cont--;

            return true;
        }

        bool DeleteFirst(){
            if(this->first == nullptr)
                return false;

            this->first->GetNext()->SetPrev(nullptr);
            this->first = this->first->GetNext();

            this->cont--;

            return true;
        }

        bool DeleteLast(){
            if(this->last == nullptr)
                return false;

            this->last->GetPrev()->SetNext(nullptr);
            this->last = this->last->GetPrev();

            this->cont--;

            return true;
        }


};



#endif // LIST_H
