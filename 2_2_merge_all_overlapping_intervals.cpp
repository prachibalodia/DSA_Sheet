#include<vector>
#include<bits/stdc++.h>
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	//brute force-> O(NlogN)+O(2N), S= O(N)
	//standing at a single point and checking if others can be merged with it
	// int n=arr.size();
	// sort(arr.begin(), arr.end());
	// vector<vector<int>> ans;
	// for(int i=0;i<n;i++){
	// 	int start= arr[i][0];		
	// 	int end= arr[i][1];

	// 	if(!ans.empty() && end <= ans.back()[1]){
	// 		continue;
	// 	}

	// 	for(int j=i+1;j<n;j++){
	// 		if(arr[j][0] <= end){
	// 			end= max(end, arr[j][1]);
	// 		}
	// 		else{
	// 			break;
	// 		}
	// 	}
	// 	ans.push_back({start,end});
	// }
	// return ans;

	//optimal-> T= O(NlogN)+O(N), S= O(N)
	int n= arr.size();
	sort(arr.begin(), arr.end());
	vector<vector<int>>ans;
	for(int i=0;i<n;i++){
		if(ans.empty() || ans.back()[1] < arr[i][0]){
			ans.push_back(arr[i]);
		}
		else{
			ans.back()[1]= max(ans.back()[1],arr[i][1]);
		}
	}
	return ans;
	
}