#include<bits/stdc++.h>

using namespace std;
class Queue {
  int * arr;
  int start, end, size, capacity;
  public:
    Queue() {
      arr= new int[15];
      start=end=-1;
      size=0;
    }

  Queue(int maxSize) {
    capacity= maxSize;
    arr= new int[maxSize];
    start=end=-1;
     size=0;
  }
  void push(int newElement) {
   if(size == capacity ) return;

   else{
    if(start==-1 && end == -1) {
        start= end=0;
    }
    arr[end%capacity]= newElement;
    end++;
    size++;
   }
  }
  int pop() {
    if (start == -1) {
      cout << "Queue Empty\nExiting..." << endl;
    }
    int popped= arr[start%capacity];
    if(size == 1){
        start=-1;
        end=-1;
    }
    else{
        start= (start+1)%capacity;
        size--;
    }
    return popped;
  }
  int top() {
    if (start == -1) {
      cout << "Queue is Empty" << endl;
      exit(1);
    }
    return arr[start];
  }
  int Size() {
    return size;
  }

};

int main() {
  Queue q(6);
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  cout << "The peek of the queue before deleting any element " << q.top() << endl;
  cout << "The size of the queue before deletion " << q.Size() << endl;
  cout << "The first element to be deleted " << q.pop() << endl;
  cout << "The peek of the queue after deleting an element " << q.top() << endl;
  cout << "The size of the queue after deleting an element " << q.Size() << endl;

  return 0;
}