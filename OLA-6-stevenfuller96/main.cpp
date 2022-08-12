#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// declare structs
struct Items {
  string description;
  int amount;
};
typedef Items ItemType;
struct NodeType;
typedef NodeType* NodePtr;

struct NodeType {
  ItemType data;
  NodePtr next;
};


struct Operations {
  string operation;
  string description;
  int amount;
};
typedef Operations OperationsType;


// function declaration
void SortedInsert(NodePtr& head, ItemType aPart);
void Insert (NodePtr& head, OperationsType aPart); // TODO
void Remove(NodePtr& head, OperationsType aPart); // TODO
void Display(NodePtr head);
void ReleaseList(NodePtr & head);

// declare global variables

int main() {
  // declare valriables
  Items partsList;
  Operations addList;
  fstream myIn;
  fstream myParts;
  string operation;
  string part;
  int num;
  NodePtr  head=NULL;

  // open files
  myIn.open("inventory.dat");
  assert(myIn);
  myParts.open("operations.dat");
  assert(myParts);

  while(getline(myIn, partsList.description)){
    myIn >> partsList.amount;
    myIn.ignore();
    
    SortedInsert(head, partsList);
  }

  cout << "Warehouse inventory before the operations\n";
  
  Display(head);
  
  while(myParts >> addList.operation){
    getline(myParts, addList.description);
    myParts >> addList.amount;
    

    if(addList.operation == "Add"){
      Insert(head, addList);
    }
    else if(addList.operation == "Remove"){
      Remove(head, addList);
    }
    myParts.ignore();
  }

  cout << "\n\nWarehouse inventory after the operations\n";
  Display(head);

  
  // close the file
  myIn.close();
  myParts.close();
  return 0;
}

void SortedInsert(NodePtr& head, ItemType aPart)
{
    NodePtr cur, prev;
    NodePtr newPtr;

    // create a node to be inserted
    newPtr = new NodeType;
    newPtr->data = aPart;  // aggregated assignment for struct type
    newPtr->next = NULL;

    // case 1: insert at the beginning of the list 
    if (head==NULL || (head != NULL && aPart.description < head->data.description))  
    {
       newPtr->next = head; // remember here: head is equal to NULL
       head = newPtr;
    }
    else // case 2: insert in the middle of at the end of the list
    {
       prev=NULL;
       cur=head;

       // look for the right place for insertion
       while (cur != NULL && cur->data.description < aPart.description)
       {
            prev = cur;
            cur = cur->next;
       }
       
       newPtr->next = cur;
       prev->next = newPtr;
    } // end else
 
    return;
}


void ReleaseList(NodePtr & head) {
  NodePtr cur = head;
  while (cur != NULL) {
    head = head->next;

    cur->next = NULL;
    delete cur;

    cur = head;
  }
}

void Insert (NodePtr& head, OperationsType aPart){
  NodePtr cur = head;
  while(cur != NULL){
    if(cur->data.description == aPart.description){
      cur->data.amount += aPart.amount;
    }
    cur = cur->next;
  }
}

void Remove(NodePtr& head, OperationsType aPart){
  NodePtr cur =head;
  while(cur != NULL){
    if(cur->data.description == aPart.description){
      cur->data.amount -= aPart.amount;
    }
    cur = cur->next;
  }
}

void Display(NodePtr head)
{
    NodePtr cur;

  cout << "Part" << setw(20) << right << "Quantity" << left << setw(20) << endl
       << endl;
  // print the list
  cur = head;
  while (cur!=NULL)
  {
    cout << cur->data.description << cur->data.amount << left <<  setw(20) << endl;
    cur = cur->next;
    }
}