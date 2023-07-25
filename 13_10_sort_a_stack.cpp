#include <bits/stdc++.h> 
void insertSorted(stack<int> &st, int num){
	if(st.empty() || st.top()< num){
		st.push(num);
		return;
	}
	int n= st.top();
	st.pop();
	insertSorted(st, num);
	st.push(n);
}
void sortStack(stack<int> &st)
{
	// Write your code here
	//T= O(N), S=O(1)
	if(st.empty()){
		return;
	}
	int num= st.top();
	st.pop();
	sortStack(st);
	insertSorted(st,num);
}