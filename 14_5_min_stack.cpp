//brute force-> T= O(N), S= O(N), since we are using a vector
// class MinStack {
// public:
// vector<int>v;
//     MinStack() {
//     }
    
//     void push(int val) {
//         v.push_back(val);
//     }
    
//     void pop() {
//         v.pop_back();
//     }
    
//     int top() {
//         int n= v.size();
//         return v[n-1];
//     }
    
//     int getMin() {
//         int mini=INT_MAX;
//         for(int i=0;i<v.size();i++){
//             mini= min(mini, v[i]);
//         }
//         return mini;
//     }
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(val);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */

//optimal-1 -> T= O(1), S= O(2N)
class MinStack {
public:
    stack<pair<int,int>>s;
    MinStack() {
    }
    
    void push(int val) {
        int mini;
        if(s.empty()){
            mini=val;
        }
        else{
            mini= min(val, s.top().second);

        }
        s.push({val, mini});       
    }
    
    void pop() {
       s.pop();
    }
    
    int top() {
       return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */