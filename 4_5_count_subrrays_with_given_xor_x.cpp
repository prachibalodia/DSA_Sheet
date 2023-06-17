class Solution {
public:
int countSubarrays(vector<int>&arr,int x){

    //brute force-> T= O(N^3), S= O(1)
    // int c=0;
    // int n= arr.size();
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         int xor=0;
    //         for(int k=i;k<=j;k++){
    //             xor^= arr[k];
    //         }
    //         if(xor == x) c++;
    //     }
    // }
    // return c;

    //better-> T=O(N^2), S= O(1)
    int c=0;
    int n= arr.size();
    for(int i=0;i<n;i++){
        int xor=0;
        for(int j=i;j<n;j++){
            xor^= arr[k];
            if(xor == x) c++;
        }
    }
    return c;
    }
}