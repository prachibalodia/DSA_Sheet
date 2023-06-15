class Solution {
public:
    // int recursion(int i, int j,int m, int n){
    //     if(i== m-1 && j== n-1)
    //     return 1;
    //     if(i>=m || j>=n)
    //     return 0;
    //     else
    //     return recursion(i+1, j,m,n)+ recursion(i,j+1,m,n);
    // }

    //  int DP(int i, int j,int m, int n,vector<vector<int>>&dp){
    //     if(i== m-1 && j== n-1)
    //     return 1;
    //     if(i>=m || j>=n)
    //     return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     else
    //     return dp[i][j]= DP(i+1, j,m,n,dp)+ DP(i,j+1,m,n,dp);
    // }

    int uniquePaths(int m, int n) {
        //brute force-> recursion-> T= O(2^m*n), S= O(2^m*n)
        // return recursion(0,0,m,n);

        //better-> using dp-> T= O(m*n), S= O(m*n)
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return DP(0,0,m,n,dp);

        //optimal-> using combinations-> T= O(m-1) or O(n-1), S=O(1)
        int N= m+n-2;
        int r= m-1;
        double ans=1;
        for(int i=1;i<=r;i++){
            ans= ans* (N-r+i)/i;
        }
        return (int)ans;
    }
};