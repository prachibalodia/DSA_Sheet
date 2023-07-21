class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //brute force 1 -> T= O(2N), S= O(N)
        //using map
        // unordered_map<int,int>m;
        // for(auto i:nums){
        //     m[i]++;
        // }
        // for(auto i:m){
        //     if(i.second == 1) return i.first;
        // }
        // return -1;

        //brute force 2 ->T= O(n), S= O(1)
        //using xor
        // int x=0;
        // for(auto i:nums){
        //     x^= i;
        // }
        // return x;

        //brute force-> T= O(N), S=O(1)
        //if there exists dups in a sorted array, then nums[i]== nums[i+1] or nums[i-1]
        //we just need to check this condition while iterating
        // int n= nums.size();
        // if(n==1) return nums[0];
        // for(int i=0;i<n;i++){
        //     if(i==0){
        //         if(nums[i+1] != nums[i]) return nums[i];
        //     }
        //     else if(i==n-1){
        //         if(nums[i] != nums[i-1]) return nums[i];
        //     }
        //     else{
        //         if(nums[i]!= nums[i-1] && nums[i]!= nums[i+1])return nums[i];
        //     }
        // }
        // return -1;

        //optimal-> T= O(logN), S= O(1)
        //using binary search-> ans odd even concept
        int n= nums.size();
        if(n==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-2] != nums[n-1]) return nums[n-1];

        int s= 1, e= n-2;
        while(s<=e){
            int mid= (s+e)/2;
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]) return nums[mid];
            else if(((mid%2) ==1 && nums[mid] == nums[mid-1]) || ((mid%2)==0 && nums[mid] == nums[mid+1])) s= mid+1;
            else{
                e= mid-1;
            }
        }
        return -1;
    }
};