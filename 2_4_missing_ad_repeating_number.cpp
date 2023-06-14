#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	//brute force-> T= O(n^2), S= O(1)
	//by using two loops, and comparing
	// int r=-1, m=-1;
	// for(int i=1;i<=n;i++){
	// 	int c=0;
	// 	for(int j=0;j<n;j++){
	// 		if(i == arr[j]){
	// 			c++;
	// 		}
	// 	}
	// 	if(c==0) m=i;
	// 	else if(c==2) r= i;
	// 	if(r != -1 && m!= -1) break; 
	// } 
	// return {m,r};

	//better-> using map or hashmap-> T= O(n), S=O(n)
	// int r=-1, m=-1;
	// int hash[n+1]= {0};
	// for(int i=0;i<n;i++){
	// 	hash[arr[i]]++;
	// }

	// for(int i=1;i<=n;i++){
	// 	if(hash[i] == 0) m= i;
	// 	else if(hash[i] == 2) r=i;
	// 	if(m != -1 && r != -1) break;
	// }
	// return {m,r};
	

	//optimal-> using maths -> T= O(n), S= O(1)
	// long long sn= (n*(n+1))/2;
	// long long s2n= (n*(n+1)*(2*n+1))/6;
	// long long s1=0, s2=0;
	// for(int i=0;i<n;i++){
	// 	s1+= arr[i];
	// 	s2+= (long long)arr[i] * (long long)arr[i];
	// }

	// long long val1= sn-s1;
	// long long val2= s2n-s2;
	// val2= val2/val1;
	// long long m= (val1+val2)/2;
	// long long r= m-val1;
	// return {(int)m,(int)r};

	//optimal-> using xor -> T= O(N), S= O(1)

	int xr=0;
	for(int i=0;i<n;i++){
		xr^= arr[i];
		xr^= (i+1);
	}

	//finding the setbit
	int bitNo=0;
	while(1){
		if(xr & (1<<bitNo) !=0){
			break;
		}
		bitNo++;
	}
	int one=0, zero=0;
	//classifying the values into the pool of one and zero bit
	for(int i=0;i<n;i++){
		if(arr[i] & (1<<bitNo) != 0){
			one ^= arr[i];
		}
		else{
			zero^=arr[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(i & (1<<bitNo) != 0){
			one ^= i;
		}
		else{
			zero^=i;
		}
	}
	int c=0;
	for(int i=0;i<n;i++){
		if(arr[i]==zero) c++;
	}
	if(c==0) return {zero, one};
	return {one,zero};
}
