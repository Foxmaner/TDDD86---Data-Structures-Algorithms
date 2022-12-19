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
                if(depthFirstReq(graph,n, end , path)){
                    path.push_back(start);
                    return true;
                }
            }
        }
    }
    start->setColor(GRAY);
    return false;

}



vector<Node *> depthFirstSearch(BasicGraph& graph, Vertex* start, Vertex* end) {
    vector<Vertex*> path;
    graph.resetData();
    depthFirstReq(graph, start, end, path);
    return path;
}

vector<Node *> breadthFirstSearch(BasicGraph& graph, Vertex* start, Vertex* end) {
    vector<Vertex*> path;
    graph.resetData();
    queue<Node*> bredthQueue;
    bredthQueue.push(start);
    start->visited = true;


    while(bredthQueue.size()>0){

        Node* currentNode = bredthQueue.front();
        currentNode->visited=true;
        //bredthQueue.pop();

        if(currentNode==end){
            while (currentNode != nullptr) {
                currentNode->setColor(GREEN);
                path.push_back(currentNode);
                currentNode = currentNode->previous;
            }
            reverse(path.begin(),path.end());
            return path;

        }

        //Vi fortsätter
        bredthQueue.pop();
        for(auto n: graph.getNeighbors(currentNode)){
            if(!n->visited){
                //Skapar en rutt, genom att referera grannarna till föregående.
                n->previous=currentNode;
                n->setColor(YELLOW);
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
                    cout << "hejhej!";
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
    // TODO: implement this function; remove these comments
    //       (The function body code provided below is just a stub that returns
    //        an empty vector so that the overall project will compile.
    //        You should remove that code and replace it with your implementation.)
    vector<Vertex*> path;
    return path;
}
