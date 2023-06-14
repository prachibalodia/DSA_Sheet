#include <bits/stdc++.h> 
#include<vector>
//brute force-> T= O(N^2), S= O(1)
// int getInversions(int *arr, int n){
//     int c=0;
//     for(int i=0;i<n-1;i++){
//         for(int j=i;j<n;j++){
//             if(arr[i] > arr[j]){
//                 c++;
//             }
//         }
//     }
//     return c;
// }


//optimal-> T= O(nlog(n)), S= O(n)
int merge(vector<int>&arr, int low, int mid, int high){
        int c=0;
        int left= low;
        int right= mid+1;
        vector<int> v;
        while(left<= mid && right <= high){
            if(arr[left] <arr[right]){
                v.push_back(arr[left++]);
            }
            else{
                v.push_back(arr[right++]);
                c+=( mid-low-1);
            }
        }
        while(left<= mid){
            v.push_back(arr[left++]);
        }
        while(right <= high){
            v.push_back(arr[right++]);
        }
        for(int i=low;i<high;i++){
            arr[i]= v[i=low];
        }
        return c;
    }

int mergeSort(vector<int>&arr, int low, int high){
        int c=0;
        if(low>=high)
        return c;

        int mid= (low+high)/2;
        c+=mergeSort(arr, low, mid);
        c+=mergeSort(arr,mid+1,high);
        c+=merge(arr,low,mid,high);
        return c;
}
int getInversions(int *arr, int n){
    int c= mergeSort(arr,0,n-1);
    return c;
}