#ifndef LIST_H
#define LIST_H

#include <cstdlib>
#include <limits>
#include <bits/stdc++.h>
#include <string>
#include <fstream>
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

    void SetValue(int _value){
        this->_value = _value;
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

        bool AddRandom(int size) {
            for(int i=0 ; i<size ; i++){
                this->AddLast(rand());
            }
            return true;
        }


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

        bool DeleteAll(){
            if(this->last == nullptr && this->last == nullptr)
                return false;

            this->first = nullptr;
            this->last = nullptr;
            this->cont = 0;

            return true;
        }

        //------------------SAVE

        bool toStream(){
            ofstream os("./data.dat");
            if (!os)
            {
                cout << "Error al abrir el fichero\n";
                exit(EXIT_FAILURE);
            }

            Node* index = this->first;

            while(index != nullptr){
                os << index->GetValue() << ";";
                index = index->GetNext();
            }

            return true;

        }

        //------------------RESTORE

        bool fromStream(){
            ifstream is("./data.dat");
            string all = "";
            if (!is)
            {
                cout << "Error al abrir el fichero\n";
                exit(EXIT_FAILURE);
            }

            this->first=nullptr;
            this->last=nullptr;
            this->cont=0;

            getline(is, all);
            //cout << all << endl;

            string token;
            size_t pos = 0;
            string delimiter = ";";

            while ((pos = all.find(delimiter)) != string::npos) {
                token = all.substr(0, pos);
                //cout << token <<endl;

                this->AddLast(stoi(token));
                all.erase(0, pos + delimiter.length());
            }

            return true;

        }
        //------------------SORT VERIFICATION

        bool VerifySort(){
            Node* index = this->first;

            while(index->GetNext() != nullptr){

                if(index->GetValue() > index->GetNext()->GetValue()){
                    return false;
                }
                index = index->GetNext();
            }
            return true;
        }


        //------------------SORT

        void BubbleSort(){
            while(!VerifySort()){
                Node* index = this->first;
                while(index->GetNext() != nullptr){

                    if(index->GetValue() > index->GetNext()->GetValue()){

                        int temp_value = index->GetValue();

                        index->SetValue(index->GetNext()->GetValue());
                        index->GetNext()->SetValue(temp_value);

                    }
                    index = index->GetNext();
                }
            }
        }

        void SelectionSort(){
            while(!VerifySort()){
                Node* pivot = this->first;
                while(pivot->GetNext() != nullptr){
                    Node* index = pivot->GetNext();
                    while(index != nullptr){
                        if(pivot->GetValue() > index->GetValue()){

                            int temp_value = pivot->GetValue();

                            pivot->SetValue(index->GetValue());
                            index->SetValue(temp_value);

                        }

                        index = index->GetNext();
                    }

                    pivot = pivot->GetNext();
                }
            }
        }

        void InsertionSort(){
            while(!VerifySort()){
                Node* pivot = this->first->GetNext();
                while(pivot!= nullptr){
                    Node* index = pivot->GetPrev();
                    while(index != nullptr){
                        if(pivot->GetValue() < index->GetValue()){

                            int temp_value = pivot->GetValue();

                            pivot->SetValue(index->GetValue());
                            index->SetValue(temp_value);

                        }

                        index = index->GetPrev();
                    }

                    pivot = pivot->GetNext();
                }
            }
        }





};



#endif // LIST_H
