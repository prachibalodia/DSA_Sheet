class Solution {
public:
    vector<int> lps(string s){
        int i=1, j=0;
        int m= s.size();
        vector<int>pi(m);
        pi[0]=0;
        while(i<m){
            if(s[i] == s[j]){
                pi[i++]= ++j;
            }
            else if(j>0){
                j=pi[j-1];
            }
            else{
                pi[i++]=0;
            }
        }
        return pi;
    }

    int strStr(string haystack, string needle) {

        //KMP Algorithm-> T=O(N+M), S=O(M), N= size of string, M= size of pattern
        if(needle.length()==0)return 0;

        vector<int>pi= lps(needle);
        int i=0, j=0, n= haystack.size();

        //i iterates in string-> haystack and j iterates in pattern-> needle
        //i never backtracks, only the j backtracks in the pattern using pi array

        while(i<n){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }

            if(j==needle.size()) return i-j;

            if(i<n && haystack[i] != needle[j]){
                if(j>0) j= pi[j-1];
                else i++;
            }
        }
        return -1;
    }
};

