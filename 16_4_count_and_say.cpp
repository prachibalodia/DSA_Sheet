class Solution {
public:
    string countAndSay(int n) {
        //brute force-> T= O(n*m) where m is the size of string, S= O(1)

        if(n==1)return "1";
        if(n==2) return "11";
        string s="11";
        int count;
        for(int i=3;i<=n;i++){
            string t="";
            count=1;
            s+="&"; //since we are always adding s[j-1] to our resultant string and not j
            for(int j=1;j<s.length();j++){
                if(s[j] != s[j-1]){
                    t= t+ to_string(count);
                    t+= s[j-1];
                    count=1;
                }
                else{
                    count++;
                }
            }
            s= t;
        }
        return s;
    }
};