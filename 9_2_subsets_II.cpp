class Solution {
public:
    // void bruteForce(vector<int>nums,int index, vector<int>res, set<vector<int>>&s){
    //     int n= nums.size();
    //     if(index == n){
    //         sort(res.begin(),res.end());
    //         s.insert(res);
    //         return;
    //     }

    //     //picking an element
    //     res.push_back(nums[index]);
    //     bruteForce(nums,index+1,res,s);

    //     //not picking up an element
    //     res.pop_back();
    //     bruteForce(nums,index+1,res,s);
    // }

    void optimal(int index, vector<vector<int>>&ans, vector<int>ds, vector<int>nums){
        ans.push_back(ds);
        int n= nums.size();
        for(int i=index;i<n;i++){
            if(i!=index && nums[i]==nums[i-1])continue;
            ds.push_back(nums[i]);
            optimal(i+1,ans,ds,nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //brute force-> T= O(2^n)* O(k*log(x)) to insert every subset of size k in the set
        //using a set
        //S= O(k*2^n)
        //pick and not pick method
        // set<vector<int>>s;
        // vector<int>res;
        // vector<vector<int>>v;
        // bruteForce(nums,0,res,s);
        // for(auto i: s){
        //     v.push_back(i);
        // }
        // return v;

        //optimal->T= O(2^N)*k, k is the average length of each subset
        //S= O(2^N)*k
        //using a simple vector data set
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end()); //since we want all the dups to be together
        optimal(0,ans,ds,nums);
        return ans;
    }
};