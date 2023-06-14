#include<vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	//Brute force-> T= O(n+m)+O(n+m), S= O(n+m)
	//adding all the elements in a sorted order by comparing each element
	//and then ultimately adding elements back into both the arrays
	// int m= a.size();
	// int n= b.size();
	// vector<long long>c(m+n,0);
	// int i=0,j=0;
	// int ind=0;
	// while(i<m && j<n)
	// {
	// 	if(a[i]<=b[j]){
	// 		c[ind]= a[i];
	// 		i++;
	// 		ind++;
	// 	}
	// 	else{
	// 		c[ind++]=b[j++];
	// 	}
	// }

	// while(i<m){
	// 	c[ind++]= a[i++];
	// }
	// while(j<n){
	// 	c[ind++]=b[j++];
	// }

	// //putting elements back in the original array
	// for(int x=0;x<m+n;x++){
	// 	if(x<m){
	// 		a[x]= c[x];
	// 	}
	// 	else{
	// 		b[x-m]=c[x];
	// 	}
	// }

	//optimal 1-> T= O(min(n,m))+O(mlogm)+O(nlogn), S= O(1)
	//here we use two pointers one at the end of first array and the other at the start of the second array
	//and then we swap
	int m= a.size();
	int n= b.size();

	int left=m-1, right=0;
	while(left>=0 && right < n){
		if(a[left]>b[right]){
			swap(a[left], b[right]);
			left--; right++;
		}
		else{
			break;
		}
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

}