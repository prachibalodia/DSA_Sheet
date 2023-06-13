class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //brute force -> O(n!)*O(n)
        //1. generate all the permutations using recursion -> O(n!)
        //2. linear search for our given num (provided that we have it sorted) ->O(n)
        //3. return the next index

        //optimal-> using c++ built-in stl
        // next_permutation(nums.begin(), nums.end());

        //implementing the optiomal stl concept

        int n= nums.size();
        int ind=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }

        //edge case
        if(ind == -1){
            reverse(nums.begin(), nums.end());
        }
        else{
        for(int i=n-1;i>ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }

        reverse(nums.begin()+ind+1, nums.end());
        }
    }
};