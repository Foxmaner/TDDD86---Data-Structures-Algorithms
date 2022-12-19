// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own, along with
// comments on every function and on complex code sections.
// TODO: write comment header for this file; remove this comment

#include <algorithm>
#include "costs.h"
#include "trailblazer.h"
#include "pqueue.h"
#include <queue>
// TODO: include any other headers you need; remove this comment
using namespace std;

bool depthFirstReq(BasicGraph& graph, Vertex* start, Vertex* end, vector<Node*>& path){
    //Starts by visiting the start node
    start->visited = true;
    start->setColor(GREEN);
    // If you have reached the end.
    if(start == end){
        path.push_back(start);
        return true;
    }
    else{
        // Check every neighbor and see if they are not visited
        for(auto n: graph.getNeighbors(start)){
            if(!n->visited){
                //recursivly visit the neighbors
                if(depthFirstReq(graph,n, end , path)){
                    //Add current node to the path
                    path.push_back(start);
                    return true;
                }
            }
        }
    }
    //If the node is already visited
    start->setColor(GRAY);
    return false;

}



vector<Node *> depthFirstSearch(BasicGraph& graph, Vertex* start, Vertex* end) {
    vector<Vertex*> path;
    graph.resetData();
    //Calls the recursive help function
    depthFirstReq(graph, start, end, path);
    return path;
}

vector<Node *> breadthFirstSearch(BasicGraph& graph, Vertex* start, Vertex* end) {
    vector<Vertex*> path;
    graph.resetData();
    queue<Node*> bredthQueue;
    bredthQueue.push(start);
    //Start by visiting the start node
    start->visited = true;

    //Continiue while there are nodes left to explore
    while(bredthQueue.size()>0){
        //Handle the next node in queue
        Node* currentNode = bredthQueue.front();
        currentNode->visited=true;
        currentNode->setColor(GREEN);

        //See if the node is the end
        if(currentNode==end){
            //If so, backtrack, and push into the path vector
            while (currentNode != nullptr) {
                currentNode->setColor(GREEN);
                path.push_back(currentNode);
                currentNode = currentNode->previous;
            }
            //Reverse it so its in the correct order
            reverse(path.begin(),path.end());
            return path;

        }
        //If we are not at the end node
        bredthQueue.pop();
        //Go through all neighbor nodes
        for(auto n: graph.getNeighbors(currentNode)){
            //Handle those who are not already visited
            if(!n->visited){
                n->visited = true;
                //Create a route by giving the neighbor a referance to its previus node
                //Makes it possible to backtrack a route
                n->previous=currentNode;
                n->setColor(YELLOW);
                //Push the neighbor to then handle it as the currentNode
                bredthQueue.push(n);
            }

        }

    }

    return path;
}

vector<Node *> dijkstrasAlgorithm(BasicGraph& graph, Vertex* start, Vertex* end) {
    graph.resetData();
    vector<Vertex*> path;

    PriorityQueue<Vertex*> pQueue;
    //Sets current vertex to start
    Vertex* currentVertex = start;
    //Sets the cost to 0
    pQueue.enqueue(currentVertex, 0);

    //Fortsätt sålänge det finns fler paths att undersöka
    while(!pQueue.isEmpty()){
        currentVertex = pQueue.dequeue();
        currentVertex->visited=true;
        currentVertex->setColor(GREEN);

        //Kolla om vi är framme, bygg upp vägen tillbaka.
        if(currentVertex==end){
            while (currentVertex != nullptr) {
                currentVertex->setColor(GREEN);
                path.push_back(currentVertex);
                currentVertex = currentVertex->previous;
            }
            reverse(path.begin(),path.end());
            return path;
        }

        for(auto e: currentVertex->arcs){
            //Följ edge:n till noden i slutet
            Node* neighbor = e->finish;
            //Kolla om den ej är besökt, om besökt så struntar vi i den.
            double newCost = (currentVertex->cost) + (e->cost);
            if(!neighbor->visited){
                neighbor->setColor(YELLOW);
                double oldCost = neighbor->cost;
                //If 0 = we havent shecked it.
                if(oldCost == 0){
                    pQueue.enqueue(neighbor,newCost);
                    neighbor->cost = newCost;
                    neighbor->previous = currentVertex;
                }else{
                    if(oldCost>newCost){
                        pQueue.changePriority(neighbor,newCost);
                        neighbor->previous = currentVertex;
                        neighbor->cost = newCost;
                    }
                }
            }

        }

    }
    return vector<Node*>();
}


vector<Node *> aStar(BasicGraph& graph, Vertex* start, Vertex* end) {
    graph.resetData();
    vector<Vertex*> path;

    PriorityQueue<Vertex*> pQueue;
    //Sets current vertex to start
    Vertex* currentVertex = start;
    //Sets the cost to 0
    pQueue.enqueue(currentVertex, 0);

    //Fortsätt sålänge det finns fler paths att undersöka
    while(!pQueue.isEmpty()){
        currentVertex = pQueue.dequeue();
        currentVertex->visited=true;
        currentVertex->setColor(GREEN);

        //Kolla om vi är framme, bygg upp vägen tillbaka.
        if(currentVertex==end){
            while (currentVertex != nullptr) {
                currentVertex->setColor(GREEN);
                path.push_back(currentVertex);
                currentVertex = currentVertex->previous;
            }
            reverse(path.begin(),path.end());
            return path;
        }

        for(auto e: currentVertex->arcs){
            //Följ edge:n till noden i slutet
            Node* neighbor = e->finish;
            //Kolla om den ej är besökt, om besökt så struntar vi i den.
            double newCost = (currentVertex->cost) + (e->cost);
            if(!neighbor->visited){
                neighbor->setColor(YELLOW);
                double oldCost = neighbor->cost;
                //If 0 = we havent shecked it.
                if(oldCost == 0){
                    neighbor->cost = newCost;
                    pQueue.enqueue(neighbor,neighbor->heuristic(end) + neighbor->cost);
                    neighbor->cost = newCost;
                    neighbor->previous = currentVertex;
                }else{
                    if(oldCost>newCost){
                        neighbor->cost = newCost;
                        pQueue.changePriority(neighbor,neighbor->heuristic(end) + neighbor->cost);
                        neighbor->previous = currentVertex;
                    }
                }
            }

        }

    }
    return vector<Node*>();
}
