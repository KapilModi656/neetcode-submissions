class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int maxi=0;
        for(int i=0;i<heights.size();i++){
            if(st.empty()||st.top().second<=heights[i]){
                st.push({i,heights[i]});
            }
            else{
                int start=i;
                while(!st.empty()&&st.top().second>heights[i]){
                    start=st.top().first;
                    maxi=max(maxi,(i-st.top().first)*st.top().second);
                    st.pop();
                }
                st.push({start,heights[i]});
            }
        }
        int n=heights.size();
        while(!st.empty()){
            maxi=max(maxi,(n-st.top().first)*st.top().second);
            st.pop();
        }
        return maxi;
    }
};
