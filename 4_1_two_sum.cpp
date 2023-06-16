class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //brute force -> T= O(n^2), S= O(1)
        // vector<int> v;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]+nums[j] == target){
        //             v.push_back(i);
        //             v.push_back(j);
        //             break;
        //         }
        //     }
        // }
        // return v;

        //Optimal-> usng hashing-> T= O(nlogn), S=O(n)
        map<int, int> m;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(m.find(target-nums[i]) != m.end()){
                v.push_back(i);
                v.push_back(m[target-nums[i]]);
                break;
            }
                m[nums[i]]=i;
        }
        return v;

        //optimal-> T= O(N)+O(NlogN), S= O(1)
        //using two pointers approach by sorting the aray, but in that case we'll need to store the indices values in our case of probele, adding on to space
        //two pointers is a good approach if we want to determine if the target exists or not-> yes or no
        
        // int left= 0;
        // int right= nums.size()-1;
        // sort(nums.begin(),nums.end());
        // while(left<right){
        //     if((nums[left]+nums[right]) ==target) return true;
        //     else if((nums[left]+nums[right]) < target)left++;
        //     else right--;
        // }
        // return false;
    }
};