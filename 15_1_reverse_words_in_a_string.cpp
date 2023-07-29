class Solution {
public:
    string reverseWords(string s) {
        //brute force-> T= O(2N), S= O(N)
        //using stack
        // string ans="";
        // stack<string>st;
        // string a="";
        // s+=' ';
        // for(auto i: s){
        //     if(i == ' '){
        //         if(a != ""){
        //             st.push(a);
        //         }
        //         a= "";
        //     }
        //     else{
        //         a+= i;
        //     }
        // }
        // while(st.size() >1){
        //     ans+= st.top()+ " ";
        //     st.pop();
        // }
        // ans+= st.top();
        // return ans;

        //optimal-> T= O(N), S=O(1)
        //without using a stack
        int i=0, j= s.size()-1;
        string ans="", temp="";
        while(i<=j){
            if(s[i] == ' '){
                if(temp != ""){
                if(ans != "") ans= temp + " "+ans;
                else ans = temp;
                }
                temp="";
            }
            else{
                temp+= s[i];
            }
            i++;
        }
        if(temp != ""){
            if(ans != "") ans= temp+ " " +ans;
            else ans= temp;
        }
        return ans;
    }
};