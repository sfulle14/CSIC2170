// fill in the blank area 
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

typedef string ItemType;

struct NodeType;
typedef NodeType* NodePtr;

struct NodeType {
   ItemType data;
   NodePtr next;
};

//function declaration
void BuildList(ifstream & myIn, NodePtr & head);
void DislayList(NodePtr head);
bool IsPresent(NodePtr head, string item);

int main()
{
  //variable  declaration
    ifstream myIn;
    NodePtr  head=NULL;  // the pointer points to the beginning of the list
  string item;
  bool present = false;
    
    myIn.open("grocery.dat");
    assert(myIn);

    // call the function "BuildList" to read data from the data file and construct the list
  BuildList(myIn, head);


    // call the function "DisplayList" to display the list
  DislayList(head);


    cout << "Enter an item to search for:";
  cin >> item;
    // call the function "IsPresent" to determine if the item is in the list
  present = IsPresent(head, item);
    // If the item is in the list, 
    //     display a message "Item is found in the list"
    // else
    //     display a message "The item is not in the list"
  if(present){
    cout << "Item is found in the list"<< endl;
  }
  else{
    cout << "The item is not in the list" << endl;
  }

  //closing the file
    myIn.close();

    return 0;
}

// Define the function "BuildList" here. 
// Write a "while" loop to read items from the data file, one item at a time.
// For each item read, add it at the end of the list.
// The loop terminates when the end of the data file is reached.
void BuildList(ifstream & myIn, NodePtr & head)
{
  string item;
  NodePtr newPtr;
  NodePtr tail;
  
  while(myIn >> item){
    //setup for insertion
    newPtr = new NodeType;
    if (newPtr != NULL){
      newPtr -> data = item;
      newPtr -> next = NULL;
    }

    //add if it is the first node
    if(head == NULL){
      head = newPtr;
      tail = newPtr;
    }
    else{  //add to end of the list
      tail -> next = newPtr;
      tail = tail -> next;
    }
  }
}

// Define the function "DisplayList" here.
void DislayList(NodePtr head)
{
  NodePtr cur=head;

  while (cur != NULL){
    cout << cur -> data <<endl;
    cur = cur -> next;
  }
  cout << endl;
}

// Define the function "IsPresent" here. This function returns true if the item to search for is 
// in the list, otherwise it returns false
bool IsPresent(NodePtr head, string item)
{
  bool found = false;
  NodePtr cur = head;

  while (cur != NULL){
    if(cur-> data == item){
      found = true;
    }
    cur = cur-> next;
  }

  return found;
}