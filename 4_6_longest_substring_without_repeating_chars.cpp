class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //brute force
        //generating all the substrings, and storing the length of the max unique sized
        // int n= s.size();
        // set<int> st;
        // if(n==0) return 0;
        // int maxi= INT_MIN;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(st.find(s[j]) != st.end()){
        //             maxi= max(maxi, j-i);
        //             break;
        //         }
        //         st.insert(s[j]);
        //     }
        // }
        // return maxi;

        //better-> T= O(2N), S= O(N)
        //sliding window approach
        //here, l and r are at 0 in the start
        //as r moves, if any dup is found, then
        //l will start moving until the dup is no longer there

        // set<int> st;
        // int maxi=INT_MIN;
        // int n= s.size();
        // int l=0;
        // for(int r=0;r<n;r++){
        //     if(st.find(s[r]) != st.end()){ //if a dup is found
        //     while(l<r && st.find(s[r]) != st.end()){
        //         st.erase(s[l]);
        //         l++;
        //     }
        //     }
        //     st.insert(s[r]);
        //     maxi= max(maxi, r-l+1);
        // }
        // return maxi;

        //optimal-> T= O(N), S= O(N)
    
        int l=0, r=0,maxi=INT_MIN,len=0;
        set<int> st;
        int n= s.size();
        if(n==0) return 0;
        while(r<n){
            auto it= st.find(s[r]);
            if(it == st.end()){
                len= r-l+1;
                maxi = max(maxi, len);
                st.insert(s[r]);
                r++;
            }
            else{
                st.erase(s[l]);
                l++;
            }
        }
        return maxi;
    }
};