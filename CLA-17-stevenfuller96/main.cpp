#include "slist.h"

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

const int MAX_SIZE = 100;

int main() {
  int size=0;
  BookType aBook;
  ifstream myIn;
  SortedList myList;
  BookType item;
  
  
  myIn.open("books.dat");
  assert(myIn);
  
  while (size < MAX_SIZE && getline(myIn, aBook.title)){
		getline(myIn, aBook.author);

		myIn >> aBook.publicationYear;
		myIn.ignore(100, '\n');

		// You are required add code below 
    // to add the book into the list and update "size"
    myList.Insert(aBook);
    size++;
  }

  //print out the list of books
  myList.Reset();
  cout << "The list of books are: \n\n";
  for(int i = 0; i < myList.GetLength(); i++){
    aBook = myList.GetNextItem();
    cout << "Title:  " << aBook.title << endl;
    cout << "Author: " << aBook.author<< endl;
    cout << "Publication Year: " << aBook.publicationYear<< endl << endl;
  }

  //ask user for a book
  cout << "Please enter the name of an author: ";
  getline(cin, item.author);
  cout << endl;

  // First, add code here to "reset" the iterator for the list object
  myList.Reset();
  
// Then, apply a "for" loop to go through the entire list item by item:
  for(int i =0; i < myList.GetLength(); i++){
  // First, retrieve the next item
    if(aBook.author == item.author){
      cout << "Title:  " << aBook.title << endl;
      cout << "Author: " << aBook.author<< endl;
      cout << "Publication Year: " << aBook.publicationYear<< endl << endl;
      
      if(myList.HasNext()){
        aBook = myList.GetNextItem();
      }     
    }
    else if(myList.HasNext()) {
      aBook = myList.GetNextItem();
    }
  }


  myIn.close();
  return 0;
}