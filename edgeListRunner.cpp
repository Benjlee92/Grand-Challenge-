#include <iostream>
#include <fstream>
using namespace std;
int main() {

 ifstream myReadFile;
 myReadFile.open("testcount.txt");
 char output[100];
 cout << "Test2" << endl;
 if (myReadFile.is_open()) {
      cout << "File opened" << endl;
 while (!myReadFile.eof()) {
    myReadFile >> output;
    cout<<output;
 }
}
myReadFile.close();
return 0;
}
