//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // void solve_brute(int i, int j, vector<vector<int>> &m, int n, vector<string>&ans, string move, vector<vector<int>> &visited){
    //     if(i == n-1 && j== n-1){
    //         ans.push_back(move);
    //         return;
    //     }
        
    //     //downward--> i+1
    //     if(i+1 <n && !visited[i+1][j] && m[i+1][j] == 1){
    //         visited[i][j]=1;
    //         solve_brute(i+1,j,m,n,ans,move+"D",visited);
    //         visited[i][j]=0;
    //     }
        
    //     //Left--> j-1
    //     if(j-1 >=0 && !visited[i][j-1] && m[i][j-1] == 1){
    //         visited[i][j]=1;
    //         solve_bryte(i,j-1,m,n,ans,move+"L",visited);
    //         visited[i][j]=0;
    //     }
        
    //     //right--> j+1
    //     if(j+1 <n && !visited[i][j+1] && m[i][j+1] == 1){
    //         visited[i][j]=1;
    //         solve_brute(i,j+1,m,n,ans,move+"R",visited);
    //         visited[i][j]=0;
    //     }
        
    //     //upward--> i-1
    //     if(i-1 >=0 && !visited[i-1][j] && m[i-1][j] == 1){
    //         visited[i][j]=1;
    //         solve_brute(i-1,j,m,n,ans,move+"U",visited);
    //         visited[i][j]=0;
    //     }
        
    // }
    
    void solve_optimal(int i, int j, vector<vector<int>> &m, int n, vector<string>&ans, string move, vector<vector<int>> &visited,int di[], int dj[]){
        if(i== n-1 && j== n-1) {
            ans.push_back(move);
            return;
        }
        
        string dir= "DLRU";
        
        for(int k=0;k<4;k++){
            int nexti= i+di[k];
            int nextj= j+dj[k];
            
            if(nexti >= 0 && nextj >= 0 && nexti<n && nextj<n && !visited[nexti][nextj] && m[nexti][nextj]==1){
                visited[i][j]=1;
                solve_optimal(nexti,nextj,m,n,ans,move+dir[k],visited,di,dj);
                visited[i][j]=0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        //T= O(4^m*n), S= O(m*n)
        vector<string> ans;
        string move="";
        vector<vector<int>> visited(n,vector<int>(n,0));
        
        //brute force->
        // if(m[0][0] == 1) solve_brute(0,0,m,n,ans,"",visited);
        
        //
        //optimal
        int di[]={+1,0,0,-1};
        int dj[]={0,-1,+1,0};
        if(m[0][0] == 1) solve_optimal(0,0,m,n,ans,"",visited,di,dj);
        
        return  ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends