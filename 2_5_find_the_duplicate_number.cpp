class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //brute force-> T= O(NlogN + N), S= O(1)
        //sorting the array nums, and comparing element at i and i+1
        // sort(nums.begin(), nums.end());
        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i]==nums[i+1])
        //         return nums[i];
        // }
        // return 0;

        //better->using hashing-> T= O(n), S= O(n)
        // int n= nums.size();
        // vector<int> hash(n,0);
        // for(int i=0;i<n;i++){
        //     hash[nums[i]]++;
        //     if(hash[nums[i]] >1)
        //     return nums[i];
        // }
        // return 0;

        //optimal-> using linked list cycle method
        //uses tortoise method of slow and fast pointers
        //T= O(n), S= O(1)

        int slow= nums[0];
        int fast= nums[0];
        do{
            slow= nums[slow];
            fast= nums[nums[fast]];
        }while(slow!=fast);

        fast= nums[0];
        while(slow!=fast){
            slow= nums[slow];
            fast= nums[fast];
        }
        return slow;
    }
};