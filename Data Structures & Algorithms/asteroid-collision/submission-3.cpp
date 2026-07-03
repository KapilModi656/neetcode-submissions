class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto asteroid : asteroids){
            bool flag=true;
            if(asteroid<0){
                while(!st.empty()&&st.top()>0){
                    if(st.top()<abs(asteroid)){
                        st.pop();
                    
                    }
                    else if(st.top()==abs(asteroid)){
                        st.pop();
                        flag=false;
                        break;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
                
                if(flag) st.push(asteroid);
            }
            else{
                st.push(asteroid);
            }
                
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