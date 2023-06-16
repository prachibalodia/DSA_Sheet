class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       //brute force T= O(N^4), S= O(no of quads)*2-> 1 for set, and other for temp vector
       //by using four loops-> T=O(n^4), S= O(no of unique quads)*2
    //     set<vector<int>>s;
    //     int n= nums.size();
    //    for(int i=0;i<n;i++){
    //        for(int j=i+1;j<n;j++){
    //            for(int k=j+1;k<n;k++){
    //                for(int l= k+1;l<n;l++){
    //                    if(nums[i]+nums[j]+nums[k]+nums[l] == target){
    //                        vector<int> temp= {nums[i],nums[j],nums[k],nums[l]};
    //                        sort(temp.begin(), temp.end());
    //                        s.insert(temp);
    //                    }
    //                }
    //            }
    //        }
    //    }
    //    vector<vector<int>>v(s.begin(),s.end());
    //    return v;

    //better-> hashing-> T= O(n^3)*O(log(unique ele)), S= O(unique ele)*2 +O(n)
    // set<vector<int>>s;
    // int n= nums.size();
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         set<int> hash;
    //         for(int k=j+1;k<n;k++){
    //             int sum=nums[i]+nums[j]+nums[k];
    //             int fourth= target-(sum);
    //             if(hash.find(fourth) != hash.end()){
    //                 vector<int> t={nums[i],nums[j],nums[k],fourth};
    //                 s.insert(t);
    //             }
    //             hash.insert(nums[k]);
    //         }
    //     }
    // }
    // vector<vector<int>>v(s.begin(),s.end());
    // return v;

    //optimal-> using 4 pointers-> T= O(N^3)+O(NlogN), S= O(no of unique ele) ..temp thing is considered linear
    set<vector<int>>s;
    sort(nums.begin(),nums.end());
    int n= nums.size();
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && nums[j]==nums[j-1]) continue;

            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum== target){
                    vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                    s.insert(temp);
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1])k++;
                    while(k<l && nums[l]==nums[l+1])l--;
                }
                else if(sum<target) k++;
                else l--;
            }
            
        }
    }
    vector<vector<int>>v(s.begin(),s.end());
    return v;
    }
};