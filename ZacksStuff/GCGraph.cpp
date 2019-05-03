#include "GCGraph.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


void GCGraph::buildVertexList(string filename){
	string dummyLine;
	myReadFile.open(filename);
	if (myReadFile.is_open()) {
	//cout << "File opened" << endl;
		getline(myReadFile,dummyLine);//This skips the first line of the file data
		getline(myReadFile,dummyLine);//This skips the second line of the file data
		    while(getline(myReadFile, temp)) // delimiter as space
		    {
		         stringstream linestream(temp);
		         int val1;
		         int val2;
		         linestream >> val1 >> val2;
		         finalString += to_string(val1) + " " + to_string(val2) + " ";
		    }
		    istringstream stm(finalString);
		    const graph_type<string> graph = create<string>(stm);
		    print(graph);
		   }
	myReadFile.close();
	}
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