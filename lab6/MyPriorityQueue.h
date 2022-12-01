// This is the second .h file you will edit
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own, as well as on the members.
// TODO: remove this comment header

#ifndef MY_PRIORITY_QUEUE_H
#define MY_PRIORITY_QUEUE_H

#include "MyVector.h"
#include "MyException.h"


template <typename T, typename C>
class MyPriorityQueue
{
    MyVector<T> vector_array;
    C strictly_larger_operator;

public:
    MyPriorityQueue();

    ~MyPriorityQueue();

    void push(const T& t);

    T top()const;

    void pop();

    bool empty()const;

  unsigned size() const;

private:
    //Number of things in priority queue;
    int n = 0;
    bool isLeaf(int pos);
    int leftchild(int pos);
    int rightchild(int pos);
    int parent(int pos);
};

template <typename T, typename C>
MyPriorityQueue<T,C>::MyPriorityQueue(){
    vector_array = new MyVector<T>();
}

template <typename T, typename C>
MyPriorityQueue<T,C>::~MyPriorityQueue(){
    delete vector_array;
}

template <typename T, typename C>
void MyPriorityQueue<T,C>::push(const T& t){
    // TODO: replace the code below with your code for this member
    MYEXCEPTION("unimplemented method");
}

/*
 * Returns the element with heighest priority
*/
template <typename T, typename C>
T MyPriorityQueue<T,C>::top()const{
    return vector_array[0];
}

template <typename T, typename C>
void MyPriorityQueue<T,C>::pop(){
    // TODO: replace the code below with your code for this member
    MYEXCEPTION("unimplemented method");
}

/*
 * Returns true if storage size = 0;
*/
template <typename T, typename C>
bool MyPriorityQueue<T,C>::empty()const{
    return vector_array.empty();
}

/*
 * Returns the number of elements in storage
*/
template <typename T, typename C>
unsigned MyPriorityQueue<T,C>::size()const{
    return vector_array.size();
}

bool isLeaf(int pos){
    return (pos >= n/2) && (pos < n);
};
int leftchild(int pos){
    if (pos >= n/2){
        return -1;
    }
    return 2*pos + 1;
};
int rightchild(int pos){
    if (pos >= (n-1)/2){
        return -1;
    }
    return 2*pos + 2;
};
int parent(int pos){
    if (pos <= 0){
        return -1;
    }
    return (pos-1)/2;
};

#endif // MY_PRIORITY_QUEUE_H
