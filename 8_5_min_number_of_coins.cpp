#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // optimal-> T= O(amount), S= O(1)
    vector<int> deno={1,2,5,10,20,50,100,500,1000}; //denominations
    int n=9;
    vector<int>v;
    for(int i=n-1;i>=0;i--){
        while(amount>=deno[i]){
            amount-=deno[i];
            v.push_back(deno[i]);
        }
    }
    return v.size();
}
