/*
*Programmerare: Eskbr129, Bjoed735
 *Eskil Brännerud, Björn Edblom.
 *
 * I denna klass implementerade vi fördefinierade funktioner, som ska användas för att sedan i huvudprogrammet
 * kunna räkna ut kortast rutt mellan punkter
 *
*/

#include <iostream>
#include "Tour.h"
#include "Node.h"
#include "Point.h"


//Default constructor
Tour::Tour(): startNode(nullptr){}

//Constructor for testCase

/**
 * TourConstructor
 *
 * the test constructor to create a loop between 4 nodes
 *
 * @param Point a, Point b, Point c, Point d
 */
Tour::Tour(Point a, Point b, Point c, Point d){

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

/**
 * TourDestructor
 *
 * Goes through every node and deletes them
 *
 */
Tour::~Tour(){
    if(startNode->next==nullptr){
        return;
    }

    Node *n = startNode;
    Node *nextNode = startNode->next;
    do{
        nextNode = n->next;
        delete n;
        n = nextNode;
    }while(n != startNode);

}

/**
 * show
 *
 * Go through all the nodes and print them out in console
 *
 */
void Tour::show()
{

    if(startNode->next==nullptr){
        return;
    }
    Node *n = startNode;
    do{
        cout << n->point << "\n";
        n = n->next;
    }while(n != startNode);

}

/**
 * draw
 *
 * Goes through every node and draws lines between the points
 *
 * @param QGraphicsScene scene
 */
void Tour::draw(QGraphicsScene *scene)
{

    // do nothing if there is no node
    if(startNode->next==nullptr){
        return;
    }
    Node *n = startNode;

    // draw a line between points while you are not at the begining again
    do{
        n->point.drawTo(n->next->point,scene);
        n = n->next;
    }while(n != startNode);


}

/**
 * size
 *
 * Counts every point in the tour
 *
 */
int Tour::size()
{

    int size = 0;
    if(startNode->next==nullptr){
        return size;
    }
    Node *n = startNode;
    // goes through every node and counts how many there is until it goes back to first node
    do{
        size++;
        n = n->next;
    }while(n != startNode);

    return size;
}

/**
 * distance
 *
 * Goes through the route and add up the distance on the tour
 *
 */
double Tour::distance()
{

    int distance = 0;
    if(startNode->next==nullptr){
        return distance;
    }
    Node *n = startNode;

    // Goes through every node and add up the distance throughout the route
    do{
        distance = distance + n->point.distanceTo(n->next->point);
        n = n->next;
    }while(n != startNode);

    return distance;
}

/**
 * insertNearest
 *
 * Inserts point p with the nearest node
 *
 * @param Point p
 */
void Tour::insertNearest(Point p)
{

    Node *n = startNode;

    // If the list is empty create node with nullpointer
    if(startNode==nullptr){
        startNode = new Node(p,nullptr);
        startNode->next = startNode;
        return;
    }

    Node *nearestNode = startNode;

    // Goes through every node and compare it to the nearestNode and se witch one is closer
    do{
        if(n->point.distanceTo(p) < nearestNode->point.distanceTo(p)){
            nearestNode = n;
        }
        n = n->next;

    }while(n != startNode);

    // Insert tempNode in the list
    Node *tempNode = new Node(p,nearestNode->next);
    nearestNode->next = tempNode;

}

/**
 * insertSmallest
 *
 * Insert point p with the node that has the smallest distance wich creates the route with shortest distance
 *
 * @param Point p
 */
void Tour::insertSmallest(Point p)
{
    Node *n = startNode;

    // If the list is empty create node with nullpointer
    if(startNode==nullptr){
        startNode = new Node(p,nullptr);
        startNode->next = startNode;
        return;
    }

    Node *nearestNode = startNode;

    // goes through the list and tries to find the shortest path between points a,b and c
    do{
        if((n->point.distanceTo(p)+p.distanceTo(n->next->point) - n->point.distanceTo(n->next->point)) <
                (nearestNode->point.distanceTo(p)+p.distanceTo(nearestNode->next->point) - nearestNode->point.distanceTo(nearestNode->next->point))){
            nearestNode = n;
        }
        n = n->next;

    }while(n != startNode);

    // Insert tempNode in the list
    Node *tempNode = new Node(p,nearestNode->next);
    nearestNode->next = tempNode;
}
