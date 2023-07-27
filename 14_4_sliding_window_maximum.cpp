class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //brute force-> gives TLE - T= O(n*k), S= O(n)
        // int n= nums.size();
        // int ans;
        // vector<int>v;
        // for(int i=0;i<=n-k;i++){
        //     ans=INT_MIN;
        //     for(int j=i;j<i+k;j++){
        //         ans= max(ans, nums[j]);
        //     }
        //     v.push_back(ans);
        // }
        // return v;

        //optimal-> T= O(N), S= O(k)
        //using a deque-> a double ended queue where the queue oprations(insertion/deletion) can be performed from both the ends;
        deque<int>q;
        vector<int>ans;
        int n= nums.size();
        for(int i=0;i<n;i++){

            //removing out of bound elements
            if(!q.empty() && q.front() == i-k) q.pop_front();
            
            //removing items which are smaller (we are storing in desc order)
            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();

            q.push_back(i);
            //pushing the answer
            if(i >= k-1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};