class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //brute force-> T= O(nlogn)-> for sorting, S= O(1)
        // int n= nums.size();
        // sort(nums.begin(), nums.end());
        // return nums[n-k];

        //optimal-> T= O(nlogn)+O(klogn), S= O(n)
        //using priority queue
        int n= nums.size();
        priority_queue<int>pq; //would store in descendng order
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        int x= k-1;
        while(x--){
            pq.pop();
        }
        return pq.top();
    }
};