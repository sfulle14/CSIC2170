#include <iostream>
#include <fstream>
//#include <iomanip>
#include <cassert>
#include <string>
using namespace std;

// declare all user defined functions here
void Swap(int &a, int &b);
void ReadData(ifstream& myIn, string books[], int& len);
int BinarySearch(string array[], int size, string value);
int LinearSearch(string names[], int size, string toFind);

const int SIZE = 50;

int main() {
  //variable declaration
  string fileName;
  string books[SIZE];
  int len=0;
  string title;
  int position;

  //asking user for file name to open
  cout << "Enter the data file name: ";
  cin >> fileName;
  
  //load data from file
  ifstream myIn(fileName.c_str());
  assert(myIn); 

  //calling function that reads and sorts data
  ReadData(myIn, books, len);

  //printing out the sorted data
  for(int i=0; i < len; i++){
    cout << i + 1 <<" : " << books[i]<< endl;
  }

  //had to add igonre because it was skipping getline()
  cin.ignore();
  
  //loop the list books until told to stop
  do{
    cout << "Enter the book title: ";
    
    getline(cin, title);

    if(title != ""){
      //position = BinarySearch(books, len, title);
      position =  LinearSearch(books, len, title);
      if(position == -1){
      cout <<"The book is not in the collection" <<endl<<endl;
      }
      else{
        cout << "The book is at location "<< position + 1 << endl<< endl;
      }
    }
    
    
  }while(title != "");
  

  return 0;
}

// define user defined function below
//swap function for sorting
void Swap(string &a, string &b){
  string temp = a;
  a=b;
  b=temp;

  return;
}

//function that reads in and sorts the data
void ReadData(ifstream& myIn, string books[], int& len){
  int minIndex;
  string minValue;
  string title;

  while(len < SIZE && getline(myIn,books[len])){
    len++;
  }
  
  for (int start = 0; start < (len-1); start++){
    minIndex = start;
    minValue = books[start];
    for(int index = start+1; index < len; index++){
      if(books[index]< minValue){
        minValue = books[index];
        minIndex = index;
      }
    }
    Swap(books[minIndex],books[start]);
  }
  return;
}

//function that searches for the asked for book
int BinarySearch(string array[], int size, string value){
  int first = 0;
  int last = size - 1;
  int middle;
  int position = - 1;
  bool found = false;
  
  while(!found && first <= last){
    middle = (first+last)/2;
    if (array[middle]== value){
      found = true;
      position = middle;
    }
    else if(array[middle]>value){
      last=middle-1;
    }
    else{
      first=middle+1;
    }
  }
  return position;
}

int LinearSearch(string names[], int size, string toFind)
{
   int position = -1;
   bool found=false;
   int index;

   index=0;
   while (!found && index < size)
   {
       if (names[index] == toFind)
       {
           found = true;
           position = index;
       }

       index++;
   }

   return position;
}