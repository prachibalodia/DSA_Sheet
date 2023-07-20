class Solution {
public:
    bool isSafe(int row, int col, vector<string>&board, int n){
        //we just need to check the left side-> upper diagonal, horizontal, lower diagonal
        //upper diagonal-> col--,row--
        int c= col, r=row;
        while(row>=0 && col>=0){
            if(board[row][col] == 'Q')return false;
            row--;
            col--;
        }
        //horizontally, col--
        col=c,row=r;
        while(col>=0){
            if(board[row][col]=='Q')return false;
            col--;
        }

        //lower diagonal, c--, r++
        row=r, col=c;
        while(row<n && col>=0){
            if(board[row][col] == 'Q') return false;
            col--;
            row++;
        }
        return true;
    }
    void solve(int col, vector<string>&board,vector<vector<string>>&ans, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        //brute force-> T= exponential-> O(N! * N)
        //S= O(N^2)
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;
    }
};