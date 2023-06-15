class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //brute force -> using hashing, T= O(NlogN)+O(N), S= O(N)
        //ordered map is implemented using tress, and hence every insertion takes O(logN) time
        //unordered map is implemented internally using hashing hence take only O(N) time
        // int x= nums.size()/2;
        // map<int,int> m;
        // for(int i=0;i<nums.size();i++){
        //     m[nums[i]]++;
        // }

        // for(auto i: m){
        //     if(i.second > x){
        //         return i.first;
        //     }
        // }
        // return -1;

        //optimal
        //moore's voting algorithm-> T= O(N) , S= O(1)
        int el, c=0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(c==0){
                c=1;
                el= nums[i];
            }
            else if(nums[i] == el){
                c++;
            }
            else{
                c--;
            }
        }
        // int c2=0;
        // for(int i=0;i<n;i++){
        //     if(el== nums[i]){
        //         c2++;
        //     }
        // }
        // if(c2> (n/2))return el;
        // return -1;
        return el;
    }
};