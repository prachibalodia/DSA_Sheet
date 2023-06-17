class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //brute force-> T= O(N)+O(NlogN), S= O(1), O(N) if using merge sort
        //also array is being distorted
        //sorting and then comaring along with a counter
        // sort(nums.begin(),nums.end());
        // int n= nums.size();
        // int prev= nums[0];
        // int c=1;
        // int maxi=1;
        // for(int i=1;i<n;i++){
        //     if(prev+1 == nums[i]){
        //         c++;
        //     }
        //     else if(prev != nums[i]){
        //         c=1;
        //     }
        //     prev= nums[i];
        //     maxi= max(maxi, c);
        // }
        // return maxi;

        //optimal-> T= O(n)+O(n)+O(n), S= O(N)-> 
        // unordered set takes O(1) time to search
        //using a hash set
        set<int> s;
        int ans=0;
        for(auto i: nums){
            s.insert(i);
        }

        for(auto i:nums){
            if(!s.count(i-1)){
                int c=1;
                int curr=i;
                while(s.count(curr+1)){
                    c++;
                    curr= curr+1;
                }
                ans= max(c,ans);
            }
        }
        return ans;
   }
};