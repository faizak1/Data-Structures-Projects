#include<stack>
#include<iostream>
using namespace std; 

//Implementation of a Queue Using Two Stacks

stack<int> st1, st2;

void enqueue(int n) {
    while (!st1.empty()) { 
        st2.push(st1.top()); 
        st1.pop(); 
    } 
    st1.push(n); 
    while (!st2.empty()) { 
        st1.push(st2.top()); 
        st2.pop(); 
    } 
} 
  
int dequeue() {
    if (st1.empty()) { 
        cout << "empty queue"; 
        return 0;
    } 
    int res = st1.top(); 
    cout << res << " is popped off the queue "<< endl; 
    st1.pop(); 
    return res; 
} 
  
int main() 
{ 
    enqueue(1); 
    enqueue(2); 
    enqueue(3); 
    enqueue(4); 
    enqueue(5); 
    enqueue(6);
    enqueue(7);
    
  
    cout << dequeue() << '\n'; 
    cout << dequeue() << '\n'; 
    cout << dequeue() << '\n'; 
    cout << dequeue() << '\n'; 
    cout << dequeue() << '\n'; 
    cout << dequeue() << '\n'; 
    cout << dequeue() << '\n'; 
  
    return 0; 
} 
