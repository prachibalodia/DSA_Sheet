class Solution {
public:
    int compareVersion(string version1, string version2) {
        //two pointers approach-> O(n1+n2), S=O(1)
        int i=0, j=0;
        int n1= version1.size(), n2= version2.size();
        int num1,num2;

        while(i<n1 || j<n2){  //in case of '.' the while loop wont execute and hence i or j wont increment

        num1=0, num2=0; //we are checking both the nums after each dot

        while(i<n1 && version1[i] != '.'){
            num1= num1*10 + (version1[i]-'0');
            i++;
        }
        while(j<n2 && version2[j] != '.'){
            num2= num2*10 + (version2[j]-'0');
            j++;
        }

        if(num1<num2) return -1;
        if(num1>num2) return 1;
        
        i++;
        j++;
        }
        return 0;
    }
};