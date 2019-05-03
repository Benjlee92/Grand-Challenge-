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
// for each vertex (key in the map), associate with a list of connected vertices, and how many connections
template< typename T > using graph_type = map< T, vector<T> >;

template< typename T > // print a graph
ostream& print( const graph_type<T>& graph, ostream& stm = cout )
{
     // for each pair (vertex, list of connected vertices, number of connections) in the graph
     for( const auto& pair : graph )
     {
          stm << "vertex " << pair.first << " ---> [ " ;
          // print each vertex in the list of connected vertices
          for( const auto& v : pair.second ){
               stm << v << ' ' ;

          }
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
graph_type<T> create( istream& stm )
{
     graph_type<T> graph ;

     T from, to;
     while( stm >> from >> to ) // for each edge  'from' ---> 'to'
     {
          graph[from].push_back(to); // add 'to' to the set of vertices connected to 'from'
          graph[to];
          graph[to].push_back(from) ;
          graph[from];
          // we may not see the vertex 'to' again in the input (there may be
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

template< typename T >
graph_type<T> SortIntoBuckets( istream& stm )
{
     graph_type<T> graph ;

     T from, to ;
     while( stm >> from >> to ) // for each edge  'from' ---> 'to'
     {
          graph[from].push_back(to) ;
           // add 'to' to the set of vertices connected to 'from'
          graph[to] ;


          // we may not see the vertex 'to' again in the input (there may be
          // no other edge connected to 'to'), so add it to the map right now
          // or, for an undirected graph:
          // graph[to].push_back(from) ;
     }

     /////////////////////////////////////////////////////////////////////////////////////////////////
     /// comment this out if multiple edges between the same pair of vertices are to be preserved ///
     /////////////////////////////////////////////////////////////////////////////////////////////////

     // clean up: remove duplicate entries (if any) in lists of connected vertices

     /////////////////////////////////////////////////////////////////////////////////////////////////
     /////////////////////////////////////////////////////////////////////////////////////////////////
     /////////////////////////////////////////////////////////////////////////////////////////////////

     return graph ;
}

int main() {
     ifstream myReadFile;

     char output[100];
     int x = 0;
     int choice = 3;
     int count = 0;
     string filename = "graph2.net";
     bool session = true;
     string temp;
     string dummyLine; //Need this to skip the first two lines that are not data
     string finalString;
     string answer;
     string exportFileName;
     while(session == true){
          // Interaction with user
          cout << endl;
          cout << " ----------------------------------------------------------------" << endl;
          cout << "|Hello what would you like to do?                                |" << endl;
          cout << "| 1) Insert a file name                                          |" << endl;
          cout << "| 2) Run the EdgeList Algorithm.                                 |" << endl;
          cout << "| 3) Quit                                                        |" << endl;
          cout << " ----------------------------------------------------------------" << endl;
          // Collect their choice
          cin >> choice;
          //Choice 1 - Enter filename to extract data from
          if(choice == 1){
               cout << "Please enter the file name:" << endl;
               cin >> filename;
          }
          //Choice 2 - Main algorithm to search tree
          else if (choice == 2 && filename != ""){
               myReadFile.open(filename);
               if (myReadFile.is_open()) {
                    cout << "File opened" << endl;
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
                    // Fix This
                    // cout << "Would you like to export this to a file? [Y/N]" << endl;
                    // cin >> answer;
                    // if(answer == "Y"){
                    //      cout << "What would you like to name the file?" << endl;
                    //      cin >> exportFileName;
                    //      ofstream out(exportFileName);
                    //      out << print(graph);
                    //      out.close();
                    // }
               }
               myReadFile.close();
          }
          //Choice 3 - Quit
          else if(choice == 3){
               cout << "Thanks for using our services" << endl;
               session = false;
          }
          else {
               cout<< "Sorry please enter an integer of (1,2,3). Thanks!" << endl;
          }
     }
     return x;
}
