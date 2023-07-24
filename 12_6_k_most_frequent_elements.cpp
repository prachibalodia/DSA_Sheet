class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //wrong interpretation of the question-> .if you think you have to return       elements occuring k or more than k times-> you're wrong baby girl
        // map<int,int>m;
        // for(auto i: nums){
        //     m[i]++;
        // }
        // vector<int>v;
        // for(auto i: m){
        //     if(i.second >=k){
        //         v.push_back(i.first);
        //     }
        // }
        // return v;

        //optimal->T= O(nlogn)+O(klogk), S= O(n)+O(n)
        //you basically have to return first k elements which occur most frequently
        unordered_map<int,int>m;
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(auto i:nums){
            m[i]++;
        }

        for(auto i: m){
            pq.push(make_pair(i.second, i.first));
        }

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;        
    }
};