class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //brute force-> T= O(nlogn)+O(n), S= O(n)
        // set<int> s;
        // for(int i=0;i<nums.size();i++){
        //    s.insert(nums[i]);
        // }
        // int n= s.size();
        // nums.clear();
        // for(auto i: s){
        //     nums.push_back(i);
        // }
        // return n;

        //optimal-> T= O(N), S=O(1)
        //using two pointers approach
        int j=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] != nums[j]){
                nums[j+1]= nums[i];
                j++;
            }
        }
        return j+1;
    }
};