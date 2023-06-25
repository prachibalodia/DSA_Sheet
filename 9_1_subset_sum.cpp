//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void recursion(int index, int sum, vector<int>arr, int n, vector<int>&ans){
        if(index==n){
            ans.push_back(sum);
            return;
        }
        
        //if we have to select the particular index in sum
        recursion(index+1, sum+arr[index], arr,n,ans);
        
        //if we proceed without selecting the particular index in sum
        recursion(index+1,sum,arr,n,ans);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        //brute force-> T= O((2^n)-1)*O(n)+O(2^nlog2^n), S= O(2^n)
        //using power set to generate all the substrings-> using bit manipulation
        // vector<int>v;
        // int p= pow(2,N);
        // for(int i=0;i<=p-1;i++){
        //     int sum=0;
        //     for(int j=0;j<N;j++){
        //         if(i & (1<<j))
        //         {
        //             sum+= arr[j];
        //         }
        //     }
        //     v.push_back(sum);
        // }
        // sort(v.begin(),v.end());
        // v[0]=0;
        // return v;
        
        //optimal-> T= O(2^n)+O(2^nlog2^n), S= O(2^n)
        //using recursion
        vector<int>ans;
        recursion(0,0,arr,N,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends