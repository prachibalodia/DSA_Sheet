class Solution {
public:
    bool isValid(string str) {
        //optimal-> T= O(N), S= O(N)
        stack<int>s;
        int n= str.size();
        for(auto i: str){
            if(i == '(' || i == '{' || i == '['){
                s.push(i);
            }
            else{
                if(s.empty())return false;
                int t= s.top();
                if((t == '(' && i == ')')|| (t == '{' && i == '}') || (t == '[' && i == ']')){
                    s.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(s.size() == 0)return true;
        return false;
    }
};