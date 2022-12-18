// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own, along with
// comments on every function and on complex code sections.
// TODO: write comment header for this file; remove this comment

#include "costs.h"
#include "trailblazer.h"
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
    // TODO: implement this function; remove these comments
    //       (The function body code provided below is just a stub that returns
    //        an empty vector so that the overall project will compile.
    //        You should remove that code and replace it with your implementation.)
    vector<Vertex*> path;
    return path;
}

vector<Node *> dijkstrasAlgorithm(BasicGraph& graph, Vertex* start, Vertex* end) {
    // TODO: implement this function; remove these comments
    //       (The function body code provided below is just a stub that returns
    //        an empty vector so that the overall project will compile.
    //        You should remove that code and replace it with your implementation.)
    vector<Vertex*> path;
    return path;
}

vector<Node *> aStar(BasicGraph& graph, Vertex* start, Vertex* end) {
    // TODO: implement this function; remove these comments
    //       (The function body code provided below is just a stub that returns
    //        an empty vector so that the overall project will compile.
    //        You should remove that code and replace it with your implementation.)
    vector<Vertex*> path;
    return path;
}
