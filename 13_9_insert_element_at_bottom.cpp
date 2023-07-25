#include <bits/stdc++.h> 
void insertAtBottom(stack<int>& myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }

    int temp= myStack.top();
    myStack.pop();
    insertAtBottom(myStack,x);
    myStack.push(temp); //backtrack
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    insertAtBottom(myStack, x);
    return myStack;
}
