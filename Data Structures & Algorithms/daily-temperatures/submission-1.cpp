class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n=temperatures.size();
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            int node=temperatures[i];
            while(!st.empty()&&node>=st.top().first){
                st.pop();
            }
            if(!st.empty()){
                int j=st.top().second;
                ans[i]=j-i;
            }
            st.push({temperatures[i],i});
        }
        return ans;

    }
};
