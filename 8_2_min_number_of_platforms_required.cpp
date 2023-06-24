//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	//brute force-> T=O(n^2), S= O(1)
    // 	int maxi=0;
    // 	for(int i=0;i<n;i++){
    // 	    int c=1;
    // 	    for(int j=i+1;j<n;j++){
    // 	        if((arr[i]>=arr[j] && dep[j]>=arr[i]) || (arr[i]<=arr[j] && dep[i]>=arr[j])){
    // 	            c++;
    // 	        }
    // 	        maxi= max(maxi,c);
    // 	    }
    // 	}
    // 	return maxi;
    	
    	//optimal-> T= O(nlogn)*2 + O(n)*2, S= O(1)
    	//the concept says we dont need to map arr and dep of each train
    	//all we need is vacant platform whichever train it may be
    	//step 1: sorting the arrays arr and dep
    	//step 2: using two pointer approach to keep a track of arrived and departed trains
    	
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int i=1,j=0;
    	int c=1; //platform needed
    	int maxi=1;
    	while(i<n && j<n){
    	    if(arr[i] <= dep[j]) {
    	        c++;
    	        i++;
    	    }
    	    else if(arr[i] > dep[j])
    	    {
    	        c--;
    	        j++;
    	    
    	    }
    	    maxi=max(maxi,c);
    	}
    return maxi;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends