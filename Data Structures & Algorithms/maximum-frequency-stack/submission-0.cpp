using ll=long long;
class FreqStack {
public:
    stack<ll> st;
    unordered_map<ll,ll> mp;
    FreqStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        mp[val]++;
    }
    
    int pop() {
        ll maxi=0;
        for(auto it:mp){
            maxi=max(maxi,it.second);
        }
        stack<ll> st2;
        ll ans=0;
        while(!st.empty()){
            ll a=st.top();
            if(mp[a]==maxi){
                st.pop();
                mp[a]--;
                ans=a;
                break;
            }
            else{
                st.pop();
                st2.push(a);
            }
        }
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
        return ans;

    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */