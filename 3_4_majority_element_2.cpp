class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // map<int, int> m;
        // for(int i=0;i<nums.size();i++){
        //     m[nums[i]]++;
        // }

        // vector<int> v;

        // for(auto x: m){
        //     if(x.second > (nums.size()/3))
        //     v.push_back(x.first);
        // }
        // return v;

        //brute force-2
        //T= O(NlogN), S= O(N)
        //  map<int, int> m;
        //  vector<int> v;
        //  int x= (nums.size()/3) +1 ;
        // for(int i=0;i<nums.size();i++){
        //     m[nums[i]]++;
        //     if(m[nums[i]] == x){
        //         v.push_back(nums[i]);
        //     }
        //     if(v.size()==2){
        //         break;
        //     }
        // }
        // return v;

        //optimal-> T= O(N), S= O(1)
        //moore's voting algorithm
        int c1=0, c2=0, el1=INT_MIN,el2=INT_MIN;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(c1 == 0 && el2!= nums[i]){
                c1=1;
                el1= nums[i];
            }
            else if(c2==0 && el1!= nums[i]){
                c2=1;
                el2= nums[i];
            }
            else if(el1==nums[i]){
                c1++;
            }
            else if(el2==nums[i]){
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }

        int x1=0, x2=0;
        for(int i=0;i<n;i++){
            if(el1 == nums[i]) x1++;
            if(el2 == nums[i]) x2++;
        }
        vector<int>v;
        int mini= (n/3)+1;
        if(x1>= mini) v.push_back(el1);
        if(x2>= mini) v.push_back(el2);
        sort(v.begin(), v.end());
        return v;
    }
};