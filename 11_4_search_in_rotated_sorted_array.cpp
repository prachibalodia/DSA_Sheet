class Solution {
public:
    int search(vector<int>& nums, int target) {
        //brute force-> linear search-> T= O(N), S= O(1)
        // int n= nums.size();
        // for(int i=0;i<n;i++){
        //     if(nums[i] == target) return i;
        // }
        // return -1;

        //brute force-> using maps->T= O(2N), S= O(N)
        // unordered_map<int,int>m;
        // int n= nums.size();
        // for(int i=0;i<n;i++){
        //     m[nums[i]]=i;
        // }
        // for(auto i:m){
        //     if(i.first == target)return i.second;
        // }
        // return -1;

        //optimal-> binary search-> T= O(logN), S= O(1)

        int n= nums.size();
        int s= 0, e= n-1;
        while(s<=e){
            int mid= (s+e)/2;
            if(nums[mid]==target)return mid;

            else if(nums[s]<=nums[mid]){  //if left part is sorted
                if(nums[s]<= target && target<= nums[mid]) e= mid-1; //element found
                else s= mid+1;  //element not found
            }
            else{ //if right part is sorted
                if(nums[mid]<=target && target<= nums[e]) s= mid+1; //element found
                else e= mid-1;  //element not found
            }
        }
        return -1;
    }
};