class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //brute force -> T= O(N^2), S=O(1)
        // int maxi=0;
        // int n= prices.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(prices[i]<prices[j]){
        //             maxi=max(maxi,prices[j]-prices[i]);
        //         }
        //     }
        // }
        // return maxi;

        //Optimal -> T= O(N), S= O(1)
        int n= prices.size();
        int maxi=0;
        int minPrice=INT_MAX;
        for(int i=0;i<n;i++){
            minPrice= min(minPrice, prices[i]);
            maxi= max(maxi, prices[i]-minPrice);
        }
        return maxi;
    }
};