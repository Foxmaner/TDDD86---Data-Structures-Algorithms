// This is the .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <iostream>
#include "Tour.h"
#include "Node.h"
#include "Point.h"


//Default constructor
Tour::Tour(): startNode(nullptr)
{

    // TODO: write this member
}

//Constructor for testCase
Tour::Tour(Point a, Point b, Point c, Point d)
{
    // TODO: write this member

    //Skapar 4 noder och tilldelar en punkt till varje
    Node* aNode = new Node(a,nullptr);
    Node* bNode = new Node(b,nullptr);
    Node* cNode = new Node(c,nullptr);
    Node* dNode = new Node(d,nullptr);

    //Länka ihop punkterna i en cirkel
    aNode->next = bNode;
    bNode->next = cNode;
    cNode->next = dNode;
    dNode->next = aNode;

    //Tilldelar starten
    startNode = aNode;
}

Tour::~Tour()
{
    // TODO: write this member
}

void Tour::show()
{
    // TODO: write this member
    if(startNode->next==nullptr){
        return;
    }
    Node *n = startNode;
    do{
        cout << n->point << "\n";
        n = n->next;
    }while(n != startNode);

}

void Tour::draw(QGraphicsScene *scene)
{
    // TODO: write this member


    if(startNode->next==nullptr){
        return;
    }
    Node *n = startNode;
    do{
        n->point.drawTo(n->next->point,scene);
        n = n->next;
    }while(n != startNode);


}

int Tour::size()
{
    // TODO: write this member
    int size = 0;
    if(startNode->next==nullptr){
        return size;
    }
    Node *n = startNode;
    do{
        size++;
        n = n->next;
    }while(n != startNode);

    return size;
}

double Tour::distance()
{
    // TODO: write this member
    int distance = 0;
    if(startNode->next==nullptr){
        return distance;
    }
    Node *n = startNode;
    do{
        distance = distance + n->point.distanceTo(n->next->point);
        n = n->next;
    }while(n != startNode);

    return distance;
}

void Tour::insertNearest(Point p)
{
    // TODO: write this member
    Node *n = startNode;

    if(startNode==nullptr){
        startNode = new Node(p,nullptr);
        startNode->next = startNode;
        return;
    }

    Node *nearestNode = startNode;
    do{
        if(n->point.distanceTo(p) < nearestNode->point.distanceTo(p)){
            nearestNode = n;
        }
        n = n->next;

    }while(n != startNode);

    Node *tempNode = new Node(p,nearestNode->next);
    nearestNode->next = tempNode;

}

void Tour::insertSmallest(Point p)
{
    // TODO: write this member
    Node *n = startNode;

    if(startNode==nullptr){
        startNode = new Node(p,nullptr);
        startNode->next = startNode;
        return;
    }

    Node *nearestNode = startNode;
    do{
        if((n->point.distanceTo(p)+p.distanceTo(n->next->point)) < (nearestNode->point.distanceTo(p)+p.distanceTo(nearestNode->next->point))){
            nearestNode = n;
        }
        n = n->next;

    }while(n != startNode);

    Node *tempNode = new Node(p,nearestNode->next);
    nearestNode->next = tempNode;
}
