class FreqStack {
public:
    map<int,stack<int>> mp;
    map<int,int> freq;
    int max_freq=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        max_freq = max(max_freq,freq[val]);
        mp[freq[val]].push(val);
    }
    
    int pop() {
        int val = mp[max_freq].top();
        mp[max_freq].pop();
        if(mp[max_freq].empty()) max_freq--;
        freq[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */