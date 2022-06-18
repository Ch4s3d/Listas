#ifndef STATICLIST_H
#define STATICLIST_H

#include <Definitions.h>

class Object {

    int index;
    int _value;

public:
    Object(){
        this->index = -1;
        this->_value = -1;
    }
    Object(int index, int _value){
        this->index = index;
        this->_value = _value;
    }

    int getIndex() const;
    void setIndex(int newIndex);
    int getValue() const;
    void setValue(int newValue);
};

inline int Object::getValue() const
{
    return _value;
}

inline void Object::setValue(int newValue)
{
    _value = newValue;
}

inline int Object::getIndex() const
{
    return index;
}

inline void Object::setIndex(int newIndex)
{
    index = newIndex;
}


class StaticList {
    Object* list;
    int cont = 0;

public:

    StaticList(){
        this->list = new Object[1];
    }

    //-----------------------------------ADD

    bool AddRandom(int size) {
        Object* tempList = new Object[cont+size];

        for(int i=0 ; i<cont ; i++){
            tempList[i] =  this->list[i];
        }

        for(int i=cont ; i<cont+size ; i++){
            tempList[i] =  *new Object(i, rand());
        }

        this->list = tempList;
        cont+=size;
        return true;
    }

    bool AddFirst(int _value) {
        Object* tempList = new Object[cont+1];

        tempList[0] =  *new Object(0, _value);
        for(int i=1 ; i<cont+1 ; i++){
            tempList[i] =  this->list[i];
        }


        this->list = tempList;
        cont++;
        return true;
    }

    //-----------------------------------SHOW

    bool ShowAll() {
        for(int i=0 ; i<this->cont ; i++){
            cout<<  this->list[i].getIndex()+1 << ": " << this->list->getValue() << endl;
        }
        return true;
    }




};

#endif // STATICLIST_H
