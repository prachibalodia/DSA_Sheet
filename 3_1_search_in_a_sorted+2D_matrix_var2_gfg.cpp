class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //if a given matrix has row as well as cols sorted
        
        //Approach 2-> using two pointers 
        int m= matrix.size();
        int n= matrix[0].size();
        int i=0, j=n-1;
        while(i<m && j>=0){
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] < target){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};