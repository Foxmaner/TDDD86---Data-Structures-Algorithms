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
}

/*
 * Assign a copy of a another MyVecktor to this MyVecktor and release the array
*/
template<typename T>
MyVector<T>& MyVector<T>::operator =(const MyVector& other){
    // If we assign to itself return this
    delete [] storage;
    capacity = other.capacity;
    numberOfElements = other.numberOfElements;
    storage = new T[other.capacity];
    for (unsigned int i= 0; i < other.capacity; i++){
        storage[i] = other.storage[i];
    }

    return *this;
}


/*
 * Add a element to the list if the list is full double the size and then add the element
*/

template<typename T>
void MyVector<T>::push_back(const T& e){
    if(numberOfElements == capacity){
        capacity = capacity * 2;
        T* templist = new T[capacity];
        for (unsigned int i= 0; i < numberOfElements; i++){
            templist[i] = storage[i];
        }
        delete [] storage;
        storage = templist;
    }
    storage[numberOfElements] = e;
    numberOfElements++;
}

/*
 * Delete the last element
*/
template<typename T>
void MyVector<T>::pop_back(){
    numberOfElements--;

}


/*
 * Return element at a given position
*/
template<typename T>
T& MyVector<T>::operator[](unsigned i){
    return storage[i];
}

/*
 * Return element at a given position
*/
template<typename T>
const T& MyVector<T>::operator[](unsigned i)const{
    return storage[i];
}


/*
 * Check if the list is empty or not
*/
template<typename T>
bool MyVector<T>::empty()const{
    if(numberOfElements == 0){
        return true;
    }else{
        return false;
    }
}

/*
 * Delete the list and create a new one with capacity 1
*/
template<typename T>
void MyVector<T>::clear(){
    delete [] storage;
    capacity = 1;
    numberOfElements = 0;
    storage = new T[1];
}


/*
 * Return the size of the list
*/
template<typename T>
unsigned MyVector<T>::size()const{
    return  numberOfElements;
}

/*
 * Return the first element of the list
*/
template<typename T>
T* MyVector<T>::begin(){
    return &storage[0];
}

/*
 * Return the last element of the list
*/
template<typename T>
T* MyVector<T>::end(){
    return &storage[numberOfElements];
}

#endif // MY_VECTOR_H
