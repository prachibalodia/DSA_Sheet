class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //brute force-> T=O(N^2), S= O(N^2)
        //using another matrix, and copying the rows into cols starting from the last
        // int n= matrix.size();
        // vector<vector<int>>v;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         v[j][n-i-1]=matrix[i][j];
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         matrix[i][j]= v[i][j];
        //     }
        // }

        //optimal-> T=O(N^2), S= O(1)
        //first transpose the matrix and then reverse each row
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

    }
};