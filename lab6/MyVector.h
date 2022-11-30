// This is the first .h file you will edit
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own, as well as on the members.
// TODO: remove this comment header

#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include "MyException.h"

template <typename T>
class MyVector
{

public:
    MyVector();

    ~MyVector();

    MyVector(const MyVector& other);

    MyVector& operator =(const MyVector& other);


    void push_back(const T&);

    void pop_back();

    T& operator[](unsigned i);

    const T& operator[](unsigned i)const;

    bool empty()const;

    T* begin();

    T* end();

    void clear();

    unsigned size()const;

private:
    T* storage;
    unsigned int capacity;
    unsigned int numberOfElements;

};

/*
 * Constructor initiates list with capacity 1
*/
template<typename T>
MyVector<T>::MyVector(){
    storage = new T[1];
    capacity = 1;
    numberOfElements = 0;
}

/*
 * Delete the only thing in the heap "storage"
*/
template<typename T>
MyVector<T>::~MyVector(){
    delete [] storage;
}

/*
 * Create a copy of a another MyVecktor
*/
template<typename T>
MyVector<T>::MyVector(const MyVector& other){
    capacity = other.capacity;
    numberOfElements = other.numberOfElements;
    storage = new T[other.capacity];
    for (unsigned int i= 0; i < other.capacity; i ++){
        storage[i] = other.storage[i];
    }
    return this;
}

/*
 * Assign a copy of a another MyVecktor to this MyVecktor and release the array
*/
template<typename T>
MyVector<T>& MyVector<T>::operator =(const MyVector& other){
    // If we assign to itself return this
    if(this == other){
        return this;
    }
    delete [] storage;
    capacity = other.capacity;
    numberOfElements = other.numberOfElements;
    storage = new T[other.capacity];
    for (unsigned int i= 0; i < other.capacity; i ++){
        storage[i] = other.storage[i];
    }

    return this;
}

template<typename T>
void MyVector<T>::push_back(const T& e){
    // TODO: replace the code below with your code for this member
    MYEXCEPTION("unimplemented method");
}

template<typename T>
void MyVector<T>::pop_back(){
    // TODO: replace the code below with your code for this member
    MYEXCEPTION("unimplemented method");
}

template<typename T>
T& MyVector<T>::operator[](unsigned i){
    // TODO: replace the code below with your code for this member
    MYEXCEPTION("unimplemented method");
}

template<typename T>
const T& MyVector<T>::operator[](unsigned i)const{
    // TODO: replace the code below with your code for this member
    MYEXCEPTION("unimplemented method");
}

template<typename T>
bool MyVector<T>::empty()const{
    // TODO: replace the code below with your code for this member
    MYEXCEPTION("unimplemented method");
}

template<typename T>
void MyVector<T>::clear(){
    // TODO: replace the code below with your code for this member
    MYEXCEPTION("unimplemented method");
}

template<typename T>
unsigned MyVector<T>::size()const{
    // TODO: replace the code below with your code for this member
    MYEXCEPTION("unimplemented method");
}

template<typename T>
T* MyVector<T>::begin(){
    // TODO: replace the code below with your code for this member
    MYEXCEPTION("unimplemented method");
}

template<typename T>
T* MyVector<T>::end(){
    // TODO: replace the code below with your code for this member
    MYEXCEPTION("unimplemented method");
}

#endif // MY_VECTOR_H
