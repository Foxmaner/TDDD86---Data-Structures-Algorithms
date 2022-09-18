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
}

int Tour::size()
{
    // TODO: write this member
}

double Tour::distance()
{
    // TODO: write this member
}

void Tour::insertNearest(Point p)
{
    // TODO: write this member
}

void Tour::insertSmallest(Point p)
{
    // TODO: write this member
}
