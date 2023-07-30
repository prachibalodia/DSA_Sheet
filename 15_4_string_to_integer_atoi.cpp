class Solution {
public:
    int myAtoi(string s) {
        //T= O(log10N) because we are just dealing with integers with base 10, S= O(1)
        int i=0;
        double num=0;
        int pos=0, neg=0;
        int n= s.size();
        while(s[i] == ' ')i++;

        if(s[i] == '+'){
            pos++;
            i++;
        }
        else if(s[i] == '-'){
            neg++;
            i++;
        }

        while(i<n && s[i]>='0' && s[i]<= '9'){
            num= num*10+(s[i]-'0');
            i++;
        }
        if(neg>0){
            num=-1*num;
        }
        num= (num>INT_MAX)? INT_MAX:num;
        num= (num<INT_MIN)? INT_MIN:num;
        return (int)num;
    }
};