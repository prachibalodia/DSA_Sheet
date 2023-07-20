class Solution {
public:
    // void bruteForce(vector<int>nums, vector<vector<int>>&ans, vector<int>&ds, int freq[]){
    //     int n= nums.size();
    //     if(ds.size()==n){
    //         ans.push_back(ds);
    //         return;
    //     }
    //     for(int i=0;i<n;i++){
    //         if(!freq[i]){
    //             ds.push_back(nums[i]);
    //             freq[i]=1;
    //             bruteForce(nums,ans,ds,freq);
    //             freq[i]=0;
    //             ds.pop_back();
    //         }
    //     }
    // }
    
    void optimal(int index, vector<int>nums,vector<vector<int>>&ans){
        int n= nums.size();
        if(index==n){
            ans.push_back(nums);
            return;
        }

        for(int i=index;i<n;i++){
            swap(nums[index], nums[i]);
            optimal(index+1, nums,ans);
            swap(nums[index], nums[i]); //backtracking
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        //brute force->T= O(n!*n), S= O(n), for the extra space of frequency array used
        //usng an extra space map or frequency array
        // vector<vector<int>>ans;
        // vector<int>ds;
        // int n= nums.size();
        // int freq[n];
        // for(int i=0;i<n;i++)freq[i]=0;
        // bruteForce(nums,ans,ds,freq);
        // return ans;

        //optimal->T= O(n*n!), S= O(1)
        //using technique of swapping
        vector<vector<int>>ans;
        optimal(0,nums,ans);
        return ans;
    }
};