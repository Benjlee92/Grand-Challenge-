#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <cstdio>
#include <set>
#include <iterator>
// Returns a pointer to a newly created 2d array the array2D has size [height x width]
using namespace std;

int convertedArray[28][28];




int patternSort(int x)
{
     int array[28][2];
     int countOccur = 0;
     // empty set container
     set <int, greater <int> > set1;

     // insert elements in random order
     for(int i = 0; i < 8; i++){
          for (int j = 0; j < 28; j++){
                    if(convertedArray[j][0] == i){
                         countOccur++;
                    }
          }

     }
     // set1.insert(40);
     // set1.insert(30);
     // set1.insert(60);
     // set1.insert(20);
     // set1.insert(50);
     // set1.insert(50); // only one 50 will be added to the set
     // set1.insert(10);
     //
     // // printing set set1
     // set <int, greater <int> > :: iterator itr;
     // cout << "\nThe set set1 is : ";
     // for (itr = set1.begin(); itr != set1.end(); ++itr)
     // {
     //      cout << '\t' << *itr;
     // }
     // cout << endl;
     //
     // // assigning the elements from set1 to set2
     // set <int> set2(set1.begin(), set1.end());
     //
     // // print all elements of the set set2
     // cout << "\nThe set set2 after assign from set1 is : ";
     // for (itr = set2.begin(); itr != set2.end(); ++itr)
     // {
     //      cout << '\t' << *itr;
     // }
     // cout << endl;
     //
     // // remove all elements up to 30 in set2
     // cout << "\nset2 after removal of elements less than 30 : ";
     // set2.erase(set2.begin(), set2.find(30));
     // for (itr = set2.begin(); itr != set2.end(); ++itr)
     // {
     //      cout << '\t' << *itr;
     // }
     //
     // // remove element with value 50 in set2
     // int num;
     // num = set2.erase (50);
     // cout << "\nset2.erase(50) : ";
     // cout << num << " removed \t" ;
     // for (itr = set2.begin(); itr != set2.end(); ++itr)
     // {
     //      cout << '\t' << *itr;
     // }
     //
     // cout << endl;
     //
     // //lower bound and upper bound for set set1
     // cout << "set1.lower_bound(40) : "
     // << *set1.lower_bound(40) << endl;
     // cout << "set1.upper_bound(40) : "
     // << *set1.upper_bound(40) << endl;
     //
     // //lower bound and upper bound for set set2
     // cout << "set2.lower_bound(40) : "
     // << *set2.lower_bound(40) << endl;
     // cout << "set2.upper_bound(40) : "
     // << *set2.upper_bound(40) << endl;

     return x;

}

void convertStringArray(const std::string& str)
{

     // These are used to convert the individual extracted char into an int to be
     // added to the tempArray
     int tempVal;
     int tempVal2;
     int temp2DArray [28][28];
     char temp ;
     //This is used to keep track of which row to add the temp array into the
     //the final twoD convertedArray
     int arrayRowCounter = 0;
     //This is used to keep track of which columb in which the value needs to be
     //inserted into the tempArray
     int arrayColumbCounter = 0;
     int tempArray[2] = {};
     tempArray[0] = -1;
     tempArray[1] = -1;
     int errornum = 0;
     int iteration = 0;

     for (int i = 0; i < str.length(); i++){
          if (str[i] == '[' && str[i+1] == '['){
               //convert the char to an int and store in the tempVals
               char a = str[i+2];
               const char *a2 = &a;
               char b = str[i+4];
               const char *b2 = &b;
               tempVal = atoi(a2);
               tempVal2 = atoi(b2);
               //Add the tempVals into the tempArray and increment the arrayColumbCounter by 2
               tempArray[arrayColumbCounter] = tempVal;
               arrayColumbCounter++;
               tempArray[arrayColumbCounter] = tempVal2;
               arrayColumbCounter++;
               //Add the tempArray to the convertedArray at row = arrayRowCounter
               convertedArray[arrayRowCounter][0] = tempArray[0];
               convertedArray[arrayRowCounter][1] = tempArray[1];
               arrayRowCounter++;
               //Reset the arrayColumbCounter
               arrayColumbCounter = 0;
               //Reset the tempArray to be empty for the next iteration
               tempArray[0] = -1;
               tempArray[1] = -1;
               i += 6;

          }
          else if (str[i] == ']' && str[i+1] == ']'){
               cout << "We have exited at line 58." << endl;
          }
          else if (str[i] == '['){
               //convert the char to an int and store in the tempVals
               char a = str[i+1];
               const char *a2 = &a;
               char b = str[i+3];
               const char *b2 = &b;
               tempVal = atoi(a2);
               tempVal2 = atoi(b2);
               //Add the tempVals into the tempArray and increment the arrayColumbCounter by 2
               tempArray[arrayColumbCounter] = tempVal;
               arrayColumbCounter++;
               tempArray[arrayColumbCounter] = tempVal2;
               arrayColumbCounter++;
               //Add the tempArray to the convertedArray at row = arrayRowCounter
               convertedArray[arrayRowCounter][0] = tempArray[0];
               convertedArray[arrayRowCounter][1] = tempArray[1];
               arrayRowCounter++;
               //Reset the arrayColumbCounter
               arrayColumbCounter = 0;
               //Reset the tempArray to be empty for the next iteration
               tempArray[0] = -1;
               tempArray[1] = -1;
               i+=5;

          }
          else {

          }
     }
}

int main()
{
     string str = "[[0,1], [0,2], [0,3], [0,4], [0,5], [0,6], [0,7], [1,2], [1,3], [1,4], [1,5], [1,6], [1,7], [2,3], [2,4], [2,5], [2,6], [2,7], [3,4], [3,5], [3,6], [3,7], [4,5], [4,6], [4,7], [5,6], [5,7], [6,7]]";
     convertStringArray(str);


     // print contents of the arraytwoD
     cout << "Array contents:" << endl;

     for (int h = 0; h < 28; h++)
     {
          for (int w = 0; w < 28; w++)
          {
               cout << convertedArray[h][w];
          }
          cout << endl;
     }
     patternSort(5);

     return 0;
}
