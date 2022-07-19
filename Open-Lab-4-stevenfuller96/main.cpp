#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
using namespace std;

//user defined fuctions
int ReadData(fstream& myIn, string className[], int boxes[]);
int FindWInner(string claseName[], int boxes[], int numClasses);
void DisplayResults(string className[], int boxes[], int numClasses);
int LinearSearch(string names[], int size, string name);

//constant variables
int const SIZE = 50;

int main() {
  //declare variables
  string className[SIZE];
  int boxes[SIZE];
  string fileName;
  int numClasses = 0;

  //ask user for file
  cout << "Enter the file name: ";
  cin >> fileName;

  //open file
  fstream myIn(fileName.c_str());
  assert(myIn);

  numClasses = ReadData(myIn, className, boxes);

  DisplayResults(className, boxes, numClasses);

  //close file
  myIn.close();
  return 0;
}

int ReadData(fstream& myIn, string className[], int boxes[]){
  int size=0;
  string name;
  int quantity;
  int index = 0;
  
    while (myIn >> name >> quantity) {
	    index = LinearSearch(className, size, name);
	    if (index>=0) {
		    boxes[index] += quantity;
	    }
	    else {
		    className[size] = name;
		    boxes[size] = quantity;
		    size ++;
	    }
    }

  return size;
}

int FindWInner(string className[], int boxes[], int numClasses){
  int temp = 0;
  int num = 0;
  
  for (int i = 0; i < numClasses; i++){
    if(boxes[i] > temp){
      temp = boxes[i];
      num = i;
    }
  }

  return num;
}

void DisplayResults(string className[], int boxes[], int numClasses){
  int winner;
  
  cout << "The final results are: " << endl;
  for(int i =0; i < numClasses; i++){
    cout << className[i] << " " << boxes[i]<< endl;
  }

  winner = FindWInner(className, boxes, numClasses);

  cout << "The winner is " << className[winner] << " sold " << boxes[winner] << " boxes.\n";

  return ;
}


int LinearSearch(string names[], int size, string name){
  int index = 0;
  int position = -1;
  bool found = false;

  while (index < size && !found){
    if(names[index] == name){
      found = true;
      position = index;
    }
    index++;
  }
  return position;
}
