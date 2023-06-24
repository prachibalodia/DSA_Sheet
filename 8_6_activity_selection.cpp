
//same as Q 8_1
//n meetings in a room
bool static comparator(pair<int,int>a, pair<int,int>b){
    return a.first<b.first; //sorting in ascending order
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    //optimal-> T= O(nlogn)+O(n), S= O(1)
      vector<pair<int, int>>v;
      int n= start.size();
      for (int i = 0; i < n; i++){
          v.push_back({finish[i],start[i]});
      }
      sort(v.begin(),v.end(),comparator);
      int limit= v[0].first;
      int maxi=0;
      for(int i=1;i<n;i++){
          if(v[i].second >= limit){
              limit= v[i].first;
              maxi++;
          }
      }
    return maxi;
}
