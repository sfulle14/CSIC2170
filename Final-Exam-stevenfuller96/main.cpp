#include <fstream>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

//declaring a struct to hold the client data
struct ClientType
{
  string name;
  string pet;
  float balance;
};

typedef ClientType ItemType;
struct NodeType; 
typedef NodeType * NodePtr;

//declaring a struct to use for the linked list
struct NodeType
{
  ItemType data;
  NodePtr  next;
};

//function declaration
void BuildList(NodePtr& head, ItemType aClient);
void DisplayList(NodePtr head);
void ReleaseList(NodePtr & head);

int main() {
  //declare variables
  ifstream myIn;
  ClientType aClient;
  NodePtr head = NULL;


  //open data file
  myIn.open("clients.dat");
  assert(myIn);

  //loops throught the data file and adds the info to the linked list
  while(myIn >> aClient.name){
    myIn >> aClient.pet;
    myIn >> aClient.balance;

    BuildList(head, aClient);
    
  }

  //prints out the information in the linked list
  DisplayList(head);

  //closes the data file
  myIn.close();

  //releases the memory of the linked list
  ReleaseList(head);
  
  return 0;
}


//addes the data to the list in sorted order
void BuildList(NodePtr& head, ItemType aClient){
  NodePtr cur, prev;
  NodePtr newPtr;

  newPtr = new NodeType;
  newPtr->data = aClient;
  newPtr->next = NULL;

  if(head==NULL || (head != NULL && aClient.name < head->data.name)){
    newPtr->next = head;
    head=newPtr;
  }
  else{
    prev = NULL;
    cur=head;

    while(cur != NULL && cur->data.name < aClient.name){
      prev = cur;
      cur = cur->next;
    }

    newPtr->next = cur;
    prev->next = newPtr;
  }

  return; 
}

//displays the data that is in the list
void DisplayList(NodePtr head){
  NodePtr cur;

  cur = head;
  while(cur != NULL){
    cout << cur->data.name << " " << cur->data.pet << " " << cur->data.balance << endl;
    cur = cur->next;
  }
  
}

//deallocates the memory of all the nodes in the list
void ReleaseList(NodePtr & head) {
  NodePtr cur = head;
  while (cur != NULL) {
    head = head->next;

    cur->next = NULL;
    delete cur;

    cur = head;
  }
}