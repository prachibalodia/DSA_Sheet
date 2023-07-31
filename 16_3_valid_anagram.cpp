class Solution {
public:
    bool isAnagram(string s, string t) {
        //approach 1
        //brute force-> Using Maps -> T= O(n+m), S= O(n+m)
        // unordered_map<int,int>m1,m2;
        // for(auto i:s){
        //     m1[i]++;
        // }
        // for(auto i:t){
        //     m2[i]++;
        // }
        // return m1==m2;

        //approach 2
        //string+sorting-> T=O(2*nlogn), S=O(1)
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s==t;

        //approach 3
        //hash table-> T=O(N), S=O(1), as an array of 26 chars is considered as constant
        //similarly we can do using maps asw
        if(s.size() != t.size())return false;
        int arr[26]={0};
        int n= s.size();
        for(int i=0;i<n;i++){
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        for(int i=0;i<26;i++){
            if(arr[i] !=0)return false;
        }
        return true;
    }
};