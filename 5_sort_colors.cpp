class Solution {
public:
    void sortColors(vector<int>& nums) {
        //brute force
        //any sorting algo
        //merge sort -> T=O(NlogN), S= O(N)

        //better-> T= O(2N), S=O(1)
        // int n= nums.size(), c1=0,c2=0,c3=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==0)c1++;
        //     else if(nums[i]==1)c2++;
        //     else c3++;
        // }

        // for(int i=0;i<c1;i++){
        //     nums[i]=0;
        // }
        // for(int i=c1;i<c2+c1;i++){
        //     nums[i]=1;
        // }
        // for(int i=c2+c1;i<c3+c2+c1;i++){
        //     nums[i]=2;
        // }

        //optimal -> T=O(N), S=O(1)
        int n= nums.size();
        int low=0, mid=0, high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};