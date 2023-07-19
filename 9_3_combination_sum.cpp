class Solution {
public:
    
    void recursion(int index, vector<int>c, int target, vector<int>ds,vector<vector<int>>&ans){
        int n= c.size();
        //base case
        if(index==n){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        //pick up element
        if(c[index]<=target){
            ds.push_back(c[index]);
            recursion(index, c,target-c[index], ds,ans);
            ds.pop_back(); //removing the element as a backtrack step, so that it can proceed further to other elements
        }
        //not pick
        recursion(index+1, c,target, ds,ans);
        }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        //optimal->T= O(2^target)*k, S= k*x, where k is the average length of combinations, and x is no of combinations
        vector<int>ds;
        vector<vector<int>>ans;
        recursion(0,candidates,target,ds,ans);
        return ans;
    }
};