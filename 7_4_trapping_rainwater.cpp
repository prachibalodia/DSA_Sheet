class Solution {
public:
    int trap(vector<int>& height) {
        //brute force -> T= O(n^2), S= O(1)
        //by calculating the water trapped using min(leftmax, rightmax)-a[i]

        // int water=0;
        // int n= height.size();
        // for(int i=0;i<n;i++){
        //     int j=i;
        //     int leftMax= INT_MIN, rightMax= INT_MIN;
        //     while(j>=0){
        //         leftMax= max(leftMax, height[j]);
        //         j--;
        //     }
        //     j=i;
        //     while(j<n){
        //         rightMax= max(rightMax, height[j]);
        //         j++;
        //     }
        //     water+= min(leftMax, rightMax)- height[i];
        // }
        // return water;

        //better-> T= O(N)+O(N)+O(N), S= O(N)+O(N)
        //by using prefix sum method
        // int n= height.size();
        // int prefix[n], suffix[n];
        // prefix[0]= height[0];
        // for(int i=1;i<n;i++){
        //     prefix[i]= max(prefix[i-1], height[i]);
        // }

        // suffix[n-1]= height[n-1];
        // for(int i= n-2;i>=0;i--){
        //     suffix[i]= max(suffix[i+1], height[i]);
        // }

        // int water=0;
        // for(int i=0;i<n;i++){
        //     water+= min(prefix[i], suffix[i])- height[i];
        // }
        // return water;

        //optimal->T= O(N), S= O(1)
        //using two pointers approach

        int n= height.size();
        int left=0, right= n-1,maxLeft=0, maxRight=0;
        int water=0;
        while(left<=right){
            if(height[left]<=height[right])
            {
                if(height[left]>=maxLeft) maxLeft= height[left];
                else
                water+= maxLeft- height[left];
                left++;
            }
            else{
                if(height[right]>= maxRight) maxRight= height[right];
                else
                    water+= maxRight-height[right];
                    right--;
            }
        }
        return water;
    }
};