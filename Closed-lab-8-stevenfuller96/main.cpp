#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <string>
#include <cmath>
using namespace std;

// declare the two functions here
float ComputeMean( int values[20], int len);
float ComputeSdv(int values[20], int len);

//globaly declare the size of the array
const int SIZE = 20;

int main() {
  //variable declaraction
  string fileName;
  int values[SIZE];
  int len=0;
  float mean;
  float stdDev;

  
  //asking user for file name to open
  cout << "Enter the data file name: ";
  cin >> fileName;
  
  //load data from file
  ifstream myIn(fileName.c_str());
  assert(myIn); 

  //find the length of the array
  while(len < SIZE && myIn>>values[len]){
    len+=1;
  }

  //call the functions
  mean = ComputeMean(values, len);
  stdDev = ComputeSdv(values, len);

  //print out the calculated data
  cout << "The values read are: ";
  for (int i=0; i < len; i++){
    cout <<  values[i] << " ";
  }
  cout << endl;
  cout << setprecision(2) << fixed;
  cout << "The mean is " << mean << ". ";
  cout << setprecision(2) << fixed;
  cout << "The standard deviation is " << stdDev << ".";
  
  return 0;
}

// define the two functions below

float ComputeMean(int values[SIZE], int len){
  //variable declaration
  float sum = 0.0;
  float mean=0.0;
  
  //sum up the values in the array
  for (int i=0; i < len; i++){
    sum += values[i];
  }
  
  //find the mean of the values in the array
  mean = sum / len;
  
  return mean;
}

float ComputeSdv(int values[20], int len){
  //variable declaration
  float standardDeviation = 0.0;
  float mean;
  float sum=0.0;

  //call ComputeMean to get the mean value
  mean = ComputeMean(values, len);

  //calculate standard deviation
  for (int i=0; i< len; i++){
    sum += ((values[i]-mean)* (values[i]-mean));
  }
  standardDeviation = sqrt(sum / len);

  return standardDeviation;
}
