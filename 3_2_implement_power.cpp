class Solution {
public:

//bryte force-> recursion or loop -> T= O(n), S= O(1)
// double power(double x, int n){
//     if(n==0){
//             return 1;
//         }
//         return x* power(x,n-1);
// }
//     double myPow(double x, int n) {
//     // return pow(x,n);
//      if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
//      if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        
//         double p;
//         if(n>0){
//             p= power(x,n);
//         }
//         else{
//             n= abs(n);
//             p= 1.0/power(x,n);
//         }      
//         return p;
//     }

        //optimal-> T= O(logN), S= O(1)
        double myPow(double x, int n) {
            long long nn= n;  //because int will overflow in case of neg to pos
            double ans= 1.0;
            if(nn<0) nn= nn* (-1);

            while(nn){
                if(nn%2 ==0){
                    nn=nn/2;
                    x= x*x;
                }
                else{
                    nn= nn-1;
                    ans= ans*x;
                }
            }

            if(n<0) ans= (double)(1.0)/(double)(ans);
            return ans;
        }
};