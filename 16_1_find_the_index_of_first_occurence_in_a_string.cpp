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
    //approach 1
    //Rabin_Karp Algorithm-> T= O(n+m), S= O(n+m)
    //    int base= 1e6;
    //    int power= 1;
    //    int m= needle.size();
    //    for(int i=0;i<m;i++){
    //        power= (power*31)%base;
    //    }

    //    //hashcode for target
    //    int tc=0;
    //    for(int i=0;i<m;i++){
    //        tc= (tc*31+needle[i])%base;
    //    }

    //    //hashcode for source
    //    int sc=0;
    //    int n= haystack.size();
    //    for(int i=0;i<n;i++){
    //        sc= (sc*31+haystack[i])%base;

    //        if(i<m-1)continue;

    //        if(i>=m){
    //            sc= (sc- haystack[i-m+1]*power)%base;
    //        }

    //        if(sc<0)sc+=base;

    //        if(sc == tc){
    //            if(haystack.substr(i-m+1,m) == needle) return i-m+1;
    //        }
    //    }
    //    return -1;

    
    //approach 2
    //sliding window approach->T= O(N), S=O(1)
    //sliding window reduces the complexity of brute force from O(n^2 or 3) to O(n)

    // int nInd=0,n= haystack.size(),m= needle.size();
    // for(int i=0;i<n;i++){
    //     if(haystack[i] == needle[nInd]){
    //         nInd++;
    //     }
    //     else{
    //         //moving the sliding window to one char forward
    //         i= i-nInd;
    //         nInd=0;
    //     }

    //     if(nInd == m){
    //         return i-nInd+1;
    //     }
    // }
    // return -1;

    //approach 3
    //we can use find function from C++ stl
    //find()-> T= O(N), S=O(1)

    // if(haystack.size()>0){
    //     return haystack.find(needle);
    // }
    // return -1;

    //approach 4-> KMP Algo
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