class Solution {
public:
    int romanToInt(string s) {
        //T= O(N), S= O(7)
        unordered_map<char,int>m;
        m.insert(make_pair('I',1));
        m.insert(make_pair('V',5));
        m.insert(make_pair('X',10));
        m.insert(make_pair('L',50));
        m.insert(make_pair('C',100));
        m.insert(make_pair('D',500));
        m.insert(make_pair('M',1000));

        int n= s.size();
        int sum=0, num;
        for(int i=0;i<n;i++){
            num=0;
            if(i == n-1 || m[s[i]]>= m[s[i+1]])
            {
                num= m[s[i]];
            }
            else{
                num= m[s[i+1]]-m[s[i]];
                i++;
            }
            sum+=num;
        }
        return sum;
    }
};