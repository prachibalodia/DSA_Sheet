// int exp(int base, int p){
//   int ans= 1;
//   int b= base;
//   while(p>0){
//     if(p%2){
//       p--;
//       ans=ans*b;
//     }
//     else {
//       p/=2;
//       ans=ans*ans;
//     }
//   }
//   return ans;
// }

int exp2(int mid, int n, int m){
  long long ans=1;
  for(int i=1;i<=n;i++){
    ans= ans*mid;
    if(ans > m)return 2;
  }
  if(ans == m) return 1;
  return 0;
}
int NthRoot(int n, int m) {
  //brute force-> O(M*log(n)), S= O(1)
  //  for(int i=1;i<m/4;i++){ //m/4 to optimize the complexity
  //    long long val= exp(i,n);
  //    if(val == m*1ll) return i;
  //    else if(val > m*1ll) break;
  //  }
  //  return -1;

  //optimal->T= O(log(m))* log(n), S= O(1)
  //using binary search

  int s=1, e=m;
  while(s<=e){
    int mid= (s+e)/2;
    int val= exp2(mid, n,m);
    if(val == 1)return mid;
    else if(val == 0) s=mid+1;
    else e= mid-1;
  }
  return -1;
}
