//brute force -> T= O(n^3), S= O(1)
class Solution {
public:

    void changeRows(vector<vector<int>>& matrix,int i,int m,int n){
        for(int j=0;j<n;j++){
            if(matrix[i][j] != 0)
            matrix[i][j]=-1;
        }
    }
    void changeCols(vector<vector<int>>& matrix,int j,int m,int n){
        for(int i=0;i<m;i++){
            if(matrix[i][j] != 0)
            matrix[i][j]=-1;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        //brute force
        int m= matrix.size();
        int n= matrix[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    changeRows(matrix,i,m,n);
                    changeCols(matrix,j,m,n);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == -1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};


//Better -> T= O(n^2), S= O(n+m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       //better
       int m= matrix.size();
       int n= matrix[0].size();
       vector<int>row(m,0);
       vector<int>col(n,0);
        
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(matrix[i][j] == 0){
                   row[i]=1;
                   col[j]=1;
               }
           }
       }

       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(row[i] == 1 || col[j]==1){
                   matrix[i][j]=0;
               }
           }
       }
    }
};

//best -> T= O(n^2), S= O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       //best -> taking hte row and col array inside the matrix itself
       int m= matrix.size();
       int n= matrix[0].size();
       //int row[m]= matrix[0][..]
       //int col[n]= matrix[..][0]
       int col0=1;
       //step 1: marking 1st row and 1st col
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j !=0){
                        matrix[0][j]=0;
                    }
                    else
                    col0=0;
                }
            }
        }
        //step 2: marking (1,1) to (m-1)(n-1) to zeros accordingly
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j] !=0){
                if(matrix[0][j] ==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
        if(col0 ==0){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};