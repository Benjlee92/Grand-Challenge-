#include "GCGraph.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


void GCGraph::buildVertexList();
void GCGraph::addVerrtex(std::string n){
    vertex v;
    v.name = n;
    vertices.push_back(v);
}
void GCGraph::addAdjVertex(vertex );
void GCGraph::addThree();
void GCGraph::ThreeLineAdd();
void GCGraph::TriangleAdd();
void GCGraph::addSingleEdge();
void GCGraph::addMultipleEdges();