#include <iostream>

using namespace std;

class Queue {
private:
  int front;
  int rear;
  int size;
  int *Q;

public:
  Queue() {
    front = rear = -1;
    size = 10;
    Q = new int[size];
  }
  Queue(int size) {
    front = rear = -1;
    this->size = size;
    Q = new int[this->size];
  }

  void enqueue(int x);
  int dequeue();
  void display();
};

void Queue::enqueue(int x) {
  if ((rear + 1) % size == front - 1) {
    printf("Queue is full");
  } else {
    rear=(rear + 1) % size;
    Q[rear] = x;
  }
}

int Queue::dequeue() {

  int x = -1;
  if (rear == front) {
    printf("Queue is empty");
  } else {
     front=(front + 1) % size;
    x = Q[front + 1];
   
  }
  return x;
}

void Queue::display() {
  int i;
  i = front + 1;

  while(i != (rear + 1 % size)) {
    printf("%d", Q[i]);
    i=(i + 1) %  size;
  }

}

int main() {

  Queue q(5);

  q.enqueue(2);
  q.enqueue(4);



  q.display();
}