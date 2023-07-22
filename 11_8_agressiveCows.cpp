bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last = stalls[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; //place next cow.
            last = stalls[i]; //update the last location.
        }
        if (cntCows >= cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) {
    //brute force-> linear search
    //T= O(nlogn)+O(n*n), S+O(1)
    // int n = stalls.size(); //size of array
    // //sort the stalls[]:
    // sort(stalls.begin(), stalls.end());

    // int limit = stalls[n - 1] - stalls[0];
    // for (int i = 1; i <= limit; i++) {
    //     if (canWePlace(stalls, i, k) == false) {
    //         return (i - 1);
    //     }
    // }
    // return limit;

    //optimal->binary search
    //T= O(nlogn)+O(log(limit))*n, S+O(1)
    sort(stalls.begin(),stalls.end());
    int n= stalls.size();
    int s=1, e= stalls[n-1]-stalls[0];
    while(s<=e){
        int mid= (s+e)/2;
        if(canWePlace(stalls, mid, k) == true){
             s= mid+1;
        }
        else{
            e= mid-1;
        }
    }
    return e;
}
