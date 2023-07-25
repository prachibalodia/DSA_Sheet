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
void reverseStack(stack<int> &st) {
    // Write your code here
    //T= O(N),S=O(1)
    if(st.empty()){
        return;
    }
    int temp = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, temp);
    }