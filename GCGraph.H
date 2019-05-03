#ifndef GCGRAPH_H
#define GCGRAPH_H
#include<vector>
#include<set>
#include<list>
#include<iostream>

struct vertex;

struct adjVertex{
    vertex *v;
};

struct vertex{
    int name;
    std::vector<adjVertex> adj;
};

struct graphNode{
	int neighborWeights;
	std::vector<vertex> vert;
	int size = vert.size();
	std::list<std::list<int> > edges;
	int edgeNum;
	graphNode *next;
};

struct Motif{
	int neighborWeights;
	int Id;
	int Counter;
	graphNode * head;

};

class Graph
{
    public:
        Graph(){};  // Already implemented
        ~Graph(){}; // Already implemented
        //void addEdge(int v1, int v2);
        //void addVertex(int name);
        //void displayEdges();
        void buildVertexList();
        void addVertex(int name);
        void addEdge(int v1, int v2);
        void addAdjVertex(vertex );
        void addThree();
        void ThreeLineAdd();
        void TriangleAdd();
        void addSingleEdge();
        void addMultipleEdges();

    protected:
    private:
        std::vector<vertex> vertices;
};

#endif // GRAPH_H