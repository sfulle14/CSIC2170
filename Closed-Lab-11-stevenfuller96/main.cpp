#include <iostream>
#include <fstream>
//#include <iomanip>
#include <cassert>
#include <string>
using namespace std;

void ReadData(ifstream& myIn, string books[], int& len);
void Insert(string books[], int& len, string title, int position);
int LinearSearch(string books[],int& len,string title);


const int SIZE = 50;

int main() {
  //variable declaration
  string fileName;
  string books[SIZE];
  int len=0;
  string title;
  int position;
  bool exists = false;
  int index = 0;

  //asking user for file name to open
  cout << "Enter the data file name: ";
  cin >> fileName;
  
  //load data from file
  ifstream myIn(fileName.c_str());
  assert(myIn); 

  //calling function that reads and sorts data
  ReadData(myIn, books, len);

  //printing out the array of books
  cout << "Books in the collection: " << endl;
  for(int i=0; i < len; i++){
    cout << i + 1 <<" : " << books[i]<< endl;
  }
  
  //loop the list books until told to stop
  do{
    cin.ignore();
    
    cout << "Please enter the title to add to the collection: ";
    getline(cin, title);

    index = LinearSearch(books, len, title);
    
    if(index >=0){
      cout << "The book is already in the collection. Insertion not carried out.\n";
      cin.ignore();
    }
    else{
      cout << "Please enter the location to add the new book: ";
      cin >> position;

      Insert(books, len, title, position);
    }

  
    cout << "\nAfter insertion ...\n";
    cout << "Books in the collection: " << endl;
    //printing out the array of books
    for(int i=0; i < len; i++){
      cout << i + 1 <<" : " << books[i]<< endl;
  }

    }while(title != "");


  return 0;
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
  }
  return;
}

//fucntion to add the new book to its position
void Insert(string books[],int& len, string title, int position){
  if(position < len){
    for(int i = len; i >= position; i--){
      books[i]=books[i-1];
    }
    books[position-1]= title;
  
    len++;
  }
}


int LinearSearch(string books[],int& len,string title){
  int index = 0;
  int position = -1;
  bool found = false;

  while (index < len && !found){
    if(books[index] == title){
      found = true;
      position = index;
    }
    index++;
  }
  return position;
}