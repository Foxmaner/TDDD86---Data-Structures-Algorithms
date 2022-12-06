// This is the second .h file you will edit
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own, as well as on the members.
// TODO: remove this comment header

#ifndef MY_PRIORITY_QUEUE_H
#define MY_PRIORITY_QUEUE_H

#include "MyVector.h"
#include "MyException.h"
#include <algorithm>
using namespace std;


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

    bool isLeaf(int pos);
    int leftchild(int pos);
    int rightchild(int pos);
    int parent(int pos);
    void shiftdown(int pos);
    void swap(T current, T parent);
};

template <typename T, typename C>
MyPriorityQueue<T,C>::MyPriorityQueue(){

}

template <typename T, typename C>
MyPriorityQueue<T,C>::~MyPriorityQueue(){

}

template <typename T, typename C>
void MyPriorityQueue<T,C>::push(const T& t){

    vector_array.push_back(t); // Start at end of heap
    int curr = vector_array.size() - 1;

    while((curr > 0) && !strictly_larger_operator(vector_array[curr], vector_array[parent(curr)])){
        // Swap
        T temp = vector_array[parent(curr)];
        vector_array[parent(curr)] = vector_array[curr];
        vector_array[curr] = temp;

        curr = parent(curr);
    }
        return;
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

    int n = vector_array.size();
    if (n == 0){
        return;
    }// Removing from empty heap
    // Swap maximum with last value
    T temp = vector_array[0];
    vector_array[0] = vector_array[vector_array.size() - 1];
    vector_array[vector_array.size()] = temp;

    if (n > 0){      // Not on last element
        shiftdown(0);   // Put new heap root val in correct place
    }
    vector_array.pop_back();

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


/*
 * Put element in its correct place
*/
template <typename T, typename C>
  void MyPriorityQueue<T,C>::shiftdown(int pos) {
    int n = vector_array.size();
    if ((pos < 0) || (pos >= n)) return; // Illegal position
    while (!isLeaf(pos)) {
      int j = leftchild(pos);
      if ((j<(n-1)) && strictly_larger_operator(vector_array[j], vector_array[j + 1])){
        j++; // j is now index of child with greater value
      }
      if (!strictly_larger_operator(vector_array[pos], vector_array[j])) {
          return;
      }
      T temp = vector_array[pos];
      vector_array[pos] = vector_array[j];
      vector_array[j] = temp;
      pos = j;  // Move down
    }
  }





template <typename T, typename C>
bool MyPriorityQueue<T,C>::isLeaf(int pos){
    int n = vector_array.size();
    return (pos >= n/2) && (pos < n);
};
template <typename T, typename C>
int MyPriorityQueue<T,C>::leftchild(int pos){
    int n = vector_array.size();
    if (pos >= n/2) return -1;
        return 2*pos + 1;
};

template <typename T, typename C>
int MyPriorityQueue<T,C>::rightchild(int pos){
    int n = vector_array.size();
    if (pos >= (n-1)/2) return -1;
        return 2*pos + 2;

};
template <typename T, typename C>
int MyPriorityQueue<T,C>::parent(int pos){
    if (pos <= 0) return -1;
        return (pos-1)/2;
};

#endif // MY_PRIORITY_QUEUE_H
