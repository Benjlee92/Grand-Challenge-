#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "GCGraph.h"
#include <queue>
using namespace std;

int main(int argc, char* argv[]){

	Graph Chal;


	int vert[2000] = {0};

	ifstream myFile;
	myFile.open("graph3.net");//argv[1]); //some test graph.net

	string v1;
	string v2;
	string line;
	ifstream();
	getline(myFile, line);
	getline(myFile, line);

	stringstream ssline(line);

	int counter = 0;

	while(getline(myFile, line)){
		stringstream ssline(line);
		getline(ssline, v1, ' ');
		getline(ssline, v2, '\n');
		//cout<<v1<<endl<<v2<<endl;
		vert[counter] = stoi(v1);
		counter++;
		vert[counter] = stoi(v2);
		counter++;

	}
	for(int i = 0; i < 1500; i++){
		cout<<vert[i]<<endl;
	}
	


	// while(getline(ssline, line, ' ')){
	// 	cout<<line<<endl;
	
	// }//end of adding verticesreset



	// while(getline(myFile, line)){//start adding edges 
	// 	stringstream ssline(line);
	// 	string connection; 
	// 	int counter = 0;
	// 	string v1;
	// 	int temp;


	return 0;
}

