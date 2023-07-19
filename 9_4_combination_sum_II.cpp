class Solution {
public:
    // void bruteForce(int index, vector<int>c, int target,  set<vector<int>>&ans, vector<int>ds){
    //     int n= c.size();
    //     if(index==n){
    //         if(target==0){
    //             // sort(ds.begin(),ds.end());
    //             ans.insert(ds);
    //         }
    //         return;
    //     }

    //     if(c[index]<=target){
    //         ds.push_back(c[index]);
    //         bruteForce(index+1, c,target-c[index],ans,ds);
    //         ds.pop_back();
    //     }
    //     bruteForce(index+1, c,target,ans,ds);
    // }

    void optimal(int index, vector<int>c,int target, vector<vector<int>>&ans, vector<int>ds){
        if(target ==0){
            ans.push_back(ds);
            return;
        }
        int n= c.size();
        for(int i=index;i<n;i++){
            if(i>index && c[i]==c[i-1])continue;
            if(c[i] > target)break;
            ds.push_back(c[i]);
            optimal(i+1, c, target-c[i], ans,ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //bryte force-> memory limit exceeds
        //pick and not pick method
        //T= O(2^t)*k*log(size of set), S= O(x*k*(size of set))
        // sort(candidates.begin(),candidates.end());
        //  set<vector<int>>ans;
        //  vector<int>ds;
        //  bruteForce(0,candidates,target,ans,ds);
        //  vector<vector<int>>v;
        //  for(auto i:ans){
        //      v.push_back(i);
        //  }
        //  return v;

        //optimal-> T= O(2^n)*k, S=O(k*x), where k= average length of combinations, x= no of        combinations
        //using the index trick to remove duplicates
        sort(candidates.begin(),candidates.end());
        vector<int>ds;
        vector<vector<int>>ans;
        optimal(0,candidates, target, ans,ds);
        return ans;
    }
};