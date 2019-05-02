#include <iostream>
#include <string>
#include <math.h>


using namespace std;
//Translates the 2d array into a pattern sorted by Number of neighbors to be
//compared to list of H graphs

string translatePattern(int [28][28])
{

     int array[28][28] = {-1};
     int val1 = 0;
     int val2 = 0;

     return "Hello";

}
//Converts a String of an edgelist to a 2d array
int convertStringArray(const std::string& str)
{
     char delim1 = '[';
     char delim2 = ']';
     char delim3 = '{';
     char delim4 = '}';
     char temp ;
     int convertedArray[28][28] = {};
     int tempArray[28] = {};
     //row counter for 2d array
     int vertexCounter = 0;
     //columb for 2d array
     int weightCounter = 0;
     string finalString;
     for (int i = 0; i < str.length(); i++){
          if (str[i] == delim1){
               temp = '{';
          }
          else if (str[i] == delim2){
               temp = '}';
          }
          else {
               temp = str[i];
          }
          finalString += temp;
     }
     for (int i = 0; i < finalString.length(); i++){
          if (finalString[i] == '{' && finalString[i+1] == '{'){
               convertedArray[vertexCounter][0] = (int)finalString[i+2];
               vertexCounter++;
               i++;
          }
          else if (finalString[i] == '{'){
               convertedArray[vertexCounter][0] = (int)finalString[i+1];
               vertexCounter++;
          }
          else if(finalString[i] == '}'){

          }
          else if(finalString[i] == '}' && finalString[i+1] == '}'){

          }
     }
return finalString;

}

int main(){
     string strComp = "[[0,1] [1,2] [2,3] [3,4]]";
     cout << convertStringArray(strComp) << endl;
}



//        [[0,1] [1,2] [2,3] [3,4]]
//        [[0,2] [1,3] [2,3] [3,4]]
//        [[0,3] [1,4] [2,3] [3,4]]
//        [[0,4] [1,0] [2,3] [3,4]]
