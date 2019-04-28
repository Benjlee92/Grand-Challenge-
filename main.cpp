#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <fstream>
#include <list>

using namespace std;
// general case: adjacency list where T is the type of the vertex
// for each vertex (key in the map), associate with a list of connected vertices
template< typename T > using graph_type = std::map< T, std::vector<T> > ;

template< typename T > // print a graph
std::ostream& print( const graph_type<T>& graph, std::ostream& stm = std::cout )
{
    // for each pair (vertex, list of connected vertices) in the graph
    for( const auto& pair : graph )
    {
        stm << "vertex " << pair.first << " ---> vertices [ " ;
        // print each vertex in the list of connected vertices
        for( const auto& v : pair.second ) stm << v << ' ' ;
        stm << "]\n" ;
    }

    return stm ;
}

// create a graph from data in an input stream
// eg. input of pairs of adjacent vertices of a directed graph
// 1 7 : edge from 1 -------> 7
// 2 7 : edge from 2 -------> 7
// 1 5 : edge from 1 -------> 5
// etc.
template< typename T >
graph_type<T> create( std::istream& stm )
{
    graph_type<T> graph ;

    T from, to ;
    while( stm >> from >> to ) // for each edge  'from' ---> 'to'
    {
        graph[from].push_back(to) ; // add 'to' to the set of vertices connected to 'from'

        graph[to] ; // we may not see the vertex 'to' again in the input (there may be
                   // no other edge connected to 'to'), so add it to the map right now
        // or, for an undirected graph:
        // graph[to].push_back(from) ;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    /// comment this out if multiple edges between the same pair of vertices are to be preserved ///
    /////////////////////////////////////////////////////////////////////////////////////////////////

    // clean up: remove duplicate entries (if any) in lists of connected vertices
    for( auto& pair : graph ) // for each pair (vertex, list of connected vertices) in the graph
    {
        auto& vec = pair.second ; // list of connected vertices
        std::sort( vec.begin(), vec.end() ) ;
        vec.erase( std::unique( vec.begin(), vec.end() ), vec.end() ) ;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////

    return graph ;
}

int main()
{
    {
        string temp;
        string finalString;
        ifstream myReadFile;
        string dummyLine;
        myReadFile.open("graph3.net");
        if (myReadFile.is_open()) {
             cout << "File opened" << endl;
             getline(myReadFile,dummyLine);//This skips the first line of the file data
             getline(myReadFile,dummyLine);//This skips the second line of the file data
             while(getline(myReadFile, temp)) // delimiter as space
             {
                  cout << "Temp: " << temp << endl;
                  stringstream linestream(temp);

                  int val1 = 4;
                  int val2 = 5;
                  linestream >> val1 >> val2;
                  cout << "Linestream: " << linestream << endl;
                  cout << "Val1: " << val1 << " Val2: " << val2 << endl;
                  finalString += to_string(val1) + " " + to_string(val2) + " ";
                  cout << "Entered into Hashtable" << endl;
             }
             istringstream stm(finalString);
             const graph_type<string> graph = create<string>(stm);
             print(graph);

        }
        myReadFile.close();
        // this graph is an adjacency_list in which each vertex is identified by an int
    }

}
