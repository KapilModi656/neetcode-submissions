class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            bool flag=true;
            if(!st.empty()&&st.top()>0&&asteroids[i]<0){
                while(!st.empty()&&st.top()>0){
                    int top=st.top();
                    if(abs(top)==abs(asteroids[i])){
                        flag=false;
                        st.pop();
                        break;
                    }
                    else if(abs(top)<abs(asteroids[i])){
                        st.pop();
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
            }
            if(flag) st.push(asteroids[i]);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};