#include <iostream>

using namespace std;

class Node {
public: 
  int data;
  Node *next;
};

class Stack {
private:
  Node *head;
public: 
  Stack() {head = NULL;}
void push(int x);
int pop();
void display();
};


void Stack::push(int x) {
  Node *t = new Node;
  if(t==NULL) {
    cout<<"Stack is full";
  } else {
    t->data=x;
    t->next=head;
    head=t;
  }
  
}

int Stack::pop() {
  int x = -1;
  if(head==NULL) {
    cout<<"Stack is empty";
  } else {
    x=head->data;
    Node *t = head;
    head = head->next;
    delete t;
  }
  return x;
}

void Stack::display() {
  Node *p = head;
  while(p != NULL) {
    cout<<p->data<<" ";
    p = p->next;
  }
  cout<<endl;
}

int main() {
  Stack stk;

  stk.push(10);
  stk.push(20);
  stk.display();
    
  //std::cout << "Hello World!\n";
}