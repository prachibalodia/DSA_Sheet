class Solution {
public:
    string intToRoman(int num) {
        //brute force->T= O(N*K),S= O(N)
        // string s="";
        // vector<pair<int, string>>v= {{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90,"XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};
        // int n= v.size();
        // for(int i=n-1;i>=0;i--){
        //     while(num >= v[i].first){
        //         s+= v[i].second;
        //         num-=v[i].first;
        //     }
        // }
        // return s;


        //optimal-> T=O(1), S=O(30)=O(1)
        string ones[]= {"", "I", "II","III","IV","V","VI","VII","VIII","IX"};
        string tens[]= {"", "X", "XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[]= {"", "C", "CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]= {"", "M", "MM","MMM"};

        return ths[num/1000]+ hrns[(num%1000)/100] + tens[(num%100)/10] + ones[(num%10)];
    }
};