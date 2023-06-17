//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        //brute force-> T= O(N^2), S= O(N)
        // int maxi=0;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+= A[j];
        //         if(sum==0){
        //             maxi= max(maxi, j-i+1);
        //         }
        //     }
        // }
        // return maxi;
        
        //optimal-> T= O(N)+O(NlogN), S= O(N)
        //algo based on
        //---------s----------
        //--------------------
        //--s--|------0-------
        map<int, int> m;
        int maxi=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+= A[i];
            if(sum == 0){
                maxi= i+1;
            }
            else{
                if(m.count(sum)){
                    maxi = max(maxi, i- m[sum]);
                }
                else{
                    m[sum]=i;
                }
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends