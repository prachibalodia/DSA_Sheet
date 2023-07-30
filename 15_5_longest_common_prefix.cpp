class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //T= O(N)+O(k*N) where k is the size of the min length string
        //S= O(1)
        int min= INT_MAX;
        string str="";

        for(int i=0;i<strs.size();i++){
            if(strs[i].size()<min){
                min= strs[i].size();
                str= strs[i];
            }
        }

        int count=0;
        for(int i=0;i<min;i++){
            for(int j=0;j<strs.size();j++){
                if(str[i] != strs[j][i]){
                    return str.substr(0,count);
                }
            }
            count++;
        }
        return str.substr(0,count);
    }
};