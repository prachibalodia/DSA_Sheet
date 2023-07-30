class Solution {
private:
int base= 1e6; //1 million or 10 lakhs or 10^6
public:
    int repeatedStringMatch(string a, string b) {
       if(a==b)return 1;
       int count=1;
       string source= a;
       while(source.size()<b.size()){
           count++;
           source+=a;
       }

       if(rabin_karp(source,b) != -1)return count;
       if(rabin_karp(source+a,b) != -1)return count+1;
       return -1;
    }

    //Rabin Karp algorithm is a pattern matching algo which searches for a pat in a given str
    //here the rabinkarp function return the index at which the target is found in source
    int rabin_karp(string source, string target){

        //Average case: T=O(m+n), S=O(m+n), Worst case: T= O(m*n), S= O(m+n)

        if(source == "" || target == "")return -1; 
        int power=1;
        int m= target.size();
        for(int i=0;i<m;i++){
            power= (power*31)%base;  //power becomes 31^m
        }

        //finding targethash-> hash for the target
        int targethash=0;
        for(int i=0;i<m;i++){
            targethash= (targethash*31+target[i])%base;
        }

        //finding the sourcehash-> hash for source while sliding over window
        int sourcehash=0, n= source.size();
        for(int i=0;i<n;i++){
            //adding the next consequent character to the window
            sourcehash= (sourcehash*31+source[i])%base;

            if(i<m-1)continue;
            
            //removing the char at the start of the window
            if(i>=m){
                sourcehash= (sourcehash- source[i-m]*power)%base;
            }

            if(sourcehash<0) sourcehash+=base;

            //when i == m-1
            if(targethash == sourcehash){
                if(source.substr(i-m+1,m) == target)return i-m+1;
            }
        }
        return -1;
    }
};