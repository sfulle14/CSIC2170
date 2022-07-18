#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <string>
using namespace std;

// declare the user defined functions here
void ComputeStatistics(ifstream& myIn, int& counter, int& smallest, int& largest, float& floatAverage);
void DisplayResults(int& counter, int& smallest, int& largest, float& floatAverage);

int main() {
  //variable declaraction
  string fileName;
  int counter;
  int smallest;
  int largest;
  float floatAverage;

  //asking user for file name to open
  cout << "Enter the data file name: ";
  cin >> fileName;
  
  //load data from file
  ifstream myIn(fileName.c_str());
  assert(myIn);  

  //function call
  ComputeStatistics(myIn, counter, smallest, largest, floatAverage);
  DisplayResults(counter, smallest, largest, floatAverage);

  myIn.close();
  return 0;
}

// define the user defined function below 
void ComputeStatistics(ifstream& myIn, int& counter, int& smallest, int& largest, float& floatAverage){
  //declare variables
  counter = 1;
  smallest = 0;
  largest = 0;
  int temp, testValue;
  floatAverage = 0.0;
  int sum=0;

  //get the first value in the file
  myIn >> smallest;
  sum+=smallest;

  //loop through all the values in the file
  while(myIn >> testValue){
    counter++;
    sum+=testValue;
    if(smallest > testValue){
      temp = smallest;
      smallest = testValue;
      if(temp > largest){
        largest = temp;
      }
    }
    else if (testValue > largest){
      largest = testValue;
    }
  }
  //calculate the average
  floatAverage = static_cast<float>(sum)/counter;
  return;
}

//this function will print our the results of the calculations
void DisplayResults(int& counter, int& smallest, int& largest, float& floatAverage){
  cout << "Total of " << counter<<" numbers."<< endl;
  cout << "The largest number is " << largest << endl;
  cout << "The smallest number is " << smallest << endl; 
  cout << "The average number is " << floatAverage << endl;
  return ;
}
