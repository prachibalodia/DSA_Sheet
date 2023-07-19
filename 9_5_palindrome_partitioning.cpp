class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--])return false;
        }
        return true;
    }
    void func(int index, string s, vector<vector<string>>&ans, vector<string>&path){
        int n= s.size();
        if(index == n){
            ans.push_back(path);
            return;
        }

        for(int i=index;i<n;i++){
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index, i-index+1));
                func(i+1, s, ans, path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        //optimal-> T= O(2^n)*O(n/2)*O(k), O(n/2) fro checking palindrome, O(k) to insert the combinations in ans data structure
        //S= O(k*x), k= avg size of each combination, x= no of combinations
        vector<vector<string>> ans;
        vector<string>path;
        func(0,s,ans,path);
        return ans;
    }
};