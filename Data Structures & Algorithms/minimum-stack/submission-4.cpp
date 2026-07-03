class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    int mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minst.empty()||mini>val){
            mini=val;
        }
        minst.push(mini);
    }
    
    void pop() {
        st.pop();
        minst.pop();
        if(minst.empty()) mini=INT_MAX;
        else mini=minst.top();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
