#include <bits/stdc++.h> 
class data{
    public:
    int val;
    int apos; //array position
    int vpos; //value position in the array

    data(int va, int a, int v){
        val=va;
        a= apos;
        v= vpos;
    }
};

struct mycomp{
    bool operator()(data a1, data b1){
        return a1.val>b1.val;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here.
    //brute force-> T= O(kxlogkx), where x is the avg size of each array
    //storing all in a vector, and then sorting the vector
    // vector<int>ans;
    // for(int i=0;i<k;i++){
    //     for(int j=0;j<kArrays[i].size();j++){
    //         ans.push_back(kArrays[i][j]);
    //     }
    // }
    // sort(ans.begin(),ans.end());
    // return ans;

    //better-> T= O(nklognk), S= O(nk)
    //using pq 
    // priority_queue<int, vector<int>,greater<int>>pq;
    // for(int i=0;i<k;i++){
    //     for(int j=0;j<kArrays[i].size();j++){
    //         pq.push(kArrays[i][j]);
    //     }
    // }
    // vector<int>v;
    // int n= pq.size();
    // while(n--){
    //     v.push_back(pq.top());
    //     pq.pop();
    // }
    // return v;

    //optimal
    //using priority queue

    priority_queue<data, vector<data>, mycomp>pq;
    for(int i=0;i<k;i++){
        data d(kArrays[i][0],i,0);
        pq.push(d);
    }
    vector<int>ans;
    while(!pq.empty()){
        data curr= pq.top(); pq.pop();
        int a= curr.apos;
        int v= curr.vpos;
        ans.push_back(curr.val);
        if(v+1 < kArrays[a].size()){
            data d(kArrays[a][v+1],a,v+1);
            pq.push(d);
        }
    }
    return ans;
}
