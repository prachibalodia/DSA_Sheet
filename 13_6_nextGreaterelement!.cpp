class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //brute force-> T= O(N^2)*logN + O(M)* logM , where N= size of nums2, M= size of nums1
        //S= O(N)
        // map<int, int>m;
        // for(int i=0;i<nums2.size();i++){
        //     if(i == nums2.size()-1){
        //         m[nums2[i]]= -1;
        //     }
        //     else{
        //         for(int j=i+1;j<nums2.size();j++){
        //             if(nums2[j] > nums2[i]){
        //                 m[nums2[i]]= nums2[j];
        //                 break;
        //             }
        //         }
        //         if(m.find(nums2[i]) == m.end()){
        //             m[nums2[i]]=-1;
        //         }
        //     }
        // }
        // vector<int>v;
        // for(auto i: nums1){
        //     if(m.find(i) != m.end()){
        //         v.push_back(m[i]);
        //     }
        // }
        // return v;

        //optimal-> T= O(N), S= O(N)
        //using stacks
        stack<int>s;
        map<int,int>m;
        int n= nums2.size();
        s.push(nums2[n-1]);
        m[nums2[n-1]]=-1;
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && (s.top() < nums2[i])){
                s.pop();
            }
            if(!s.empty())
            m[nums2[i]]= s.top();
            

            else{
                m[nums2[i]]=-1;
            }
            s.push(nums2[i]);
        }
        vector<int>v;
        for(auto i: nums1){
            v.push_back(m[i]);
        }
        return v;
    }
};