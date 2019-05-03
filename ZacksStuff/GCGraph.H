#ifndef GCGRAPH_H
#define GCGRAPH_H
#include<vector>
#include<iostream>

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string name;
    std::vector<adjVertex> adj;
};

class Graph
{
    public:
        Graph(){};  // Already implemented
        ~Graph(){}; // Already implemented
        void addEdge(std::string v1, std::string v2);
        void addVertex(std::string name);
        void displayEdges();
    protected:
    private:
        std::vector<vertex> vertices;
};

#endif // GRAPH_H