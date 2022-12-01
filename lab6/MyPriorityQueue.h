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

    //Number of things in priority queue;
    int n = 0;
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
};

template <typename T, typename C>
MyPriorityQueue<T,C>::MyPriorityQueue(){
    //vector_array = new MyVector<T>();
    n = vector_array.size();

}

template <typename T, typename C>
MyPriorityQueue<T,C>::~MyPriorityQueue(){
    delete &vector_array;
}

template <typename T, typename C>
void MyPriorityQueue<T,C>::push(const T& t){
    int curr = n++;
       vector_array[curr] = t;  // Start at end of heap
       // Now sift up until curr's parent's key > curr's key
       while ((curr != 0) && (vector_array[curr].compareTo(vector_array[parent(curr)]) > 0)) {
         swap(vector_array, curr, parent(curr));
         curr = parent(curr);
    }
    n = vector_array.size();
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
    swap(vector_array, 0, --n); // Swap maximum with last value
     // Not on last element
    if (n != 0){
      // Put new heap root val in correct place
      shiftdown(0);
      }
    return vector_array[n];
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
    if ((pos < 0) || (pos >= n)) return; // Illegal position
    while (!isLeaf(pos)) {
      int j = leftchild(pos);
      if ((j<(n-1)) && (vector_array[j].compareTo(vector_array[j+1]) < 0))
        j++; // j is now index of child with greater value
      if (vector_array[pos].compareTo(vector_array[j]) >= 0) return;
      swap(vector_array, pos, j);
      pos = j;  // Move down
    }
  }


template <typename T, typename C>
bool MyPriorityQueue<T,C>::isLeaf(int pos){
    return (pos >= n/2) && (pos < n);
};
template <typename T, typename C>
int MyPriorityQueue<T,C>::leftchild(int pos){
    if (pos >= n/2){
        return -1;
    }
    return 2*pos + 1;
};
template <typename T, typename C>
int MyPriorityQueue<T,C>::rightchild(int pos){
    if (pos >= (n-1)/2){
        return -1;
    }
    return 2*pos + 2;
};
template <typename T, typename C>
int MyPriorityQueue<T,C>::parent(int pos){
    if (pos <= 0){
        return -1;
    }
    return (pos-1)/2;
};

#endif // MY_PRIORITY_QUEUE_H
