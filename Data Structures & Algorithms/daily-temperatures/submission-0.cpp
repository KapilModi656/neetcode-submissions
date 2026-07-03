class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()){
                int a=st.top();
                if(temperatures[a]<temperatures[i]){
                    ans[a]=i-a;
                    st.pop();
                }
                else{
                    break;
                }
            }
            st.push(i);
        }
        return ans;

    }
};
