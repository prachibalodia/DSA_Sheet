class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        //binary search on a 2D matrix
        //in log(m*n) time and linear space without using any extra vector
        if(!matrix.size()) return false;
        int m= matrix.size();
        int n= matrix[0].size();
        int low=0, high= (m*n)-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(matrix[mid/n][mid%n]==target){
                return true;
            }
            else if((matrix[mid/n][mid%n]) >target){
                high= mid-1;
            }
            else
            low= mid+1;
        }
        return false;

    }
};