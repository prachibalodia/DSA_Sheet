class Solution {
public:
    vector<int> generateRows(int n){
        long long ans=1;
        vector<int> v;
        v.push_back(ans);
        for(int i=1;i<n;i++){
            ans*= (n-i);
            ans/= (i);
            v.push_back(ans);
        }
        return v;
    }
    vector<vector<int>> generate(int numRows) {
        //O(n^2)
       vector<vector<int>>ans;
       for(int i=1;i<=numRows;i++){
           ans.push_back(generateRows(i));
       }
       return ans;
    }
};