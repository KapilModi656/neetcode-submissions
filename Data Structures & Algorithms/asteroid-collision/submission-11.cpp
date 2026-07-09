class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();
        st.push(asteroids[0]);
        for(int i=1;i<n;i++){
            int a = asteroids[i];
            int s = a/abs(a);
            if(st.empty()){
                st.push(a);
                continue;
            }
            int top = st.top();
            int g = top/abs(top);
            if(s>=g){
                st.push(a);
            }
            else{
                if(abs(a)==abs(top)){
                    st.pop();
                    continue;
                }
                while(!st.empty()&&st.top()>0&&abs(a)>st.top()){
                    st.pop();
                }
                if(!st.empty()&&st.top()>0&&abs(a)==st.top()){
                    st.pop();
                }
                else if(st.empty()||st.top()<0) st.push(a);
            }
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};