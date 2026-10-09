class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        while(!q2.empty()) q1.push(q2.front()),q2.pop();
        queue<int> temp;
        q2=q1;
        q1=temp;
    }
    
    int pop() {
        int a=q2.front();
        q2.pop();
        return a;
    }
    
    int top() {
        
        return q2.front();
    }
    
    bool empty() {
        if(q1.empty()&&q2.empty()) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */