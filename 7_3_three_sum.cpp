class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //brute force-> T= O(n^3), S= O(unique elements)
        // int n= nums.size();
        // set<vector<int>>s;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k= j+1;k<n;k++){
        //             int sum= nums[k];
        //             sum+= nums[j];
        //             sum+= nums[i];
        //             if(sum== 0){
        //                 vector<int> t= {nums[i],nums[j],nums[k]};
        //                 sort(t.begin(),t.end());
        //                 s.insert(t);
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>>v;
        // for(auto x : s){
        //     v.push_back(x);
        // }
        // return v;

        //optimal-> T= O(n^2), S= O(3* no of unique triplets)
        //two pointers approach
        vector<vector<int>>v;
        set<vector<int>>s;
        sort(nums.begin(),nums.end());
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int j=i+1, k=n-1;
            while(j<k){
                int sum= nums[i];
                sum+= nums[j];
                sum+= nums[k];
                if(sum == 0){
                    vector<int> t= {nums[i], nums[j], nums[k]};
                    sort(t.begin(),t.end());
                    s.insert(t);
                    k--;
                    j++;
                    if(j<k && nums[j]==nums[j-1])j++;
                    if(j<k && nums[k]==nums[k+1])k--;
                }
                else if(sum >0)k--;
                else j++;
            }
        }
        for(auto x: s){
            v.push_back(x);
        }
        return v;
    }
};