class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        vector<int> left(n),right(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            left[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()){
                int top = st.top();
                if(heights[top]>=heights[i]){
                    st.pop();
                }
                else{
                    break;
                }
            }
            right[i] = st.empty()?n:st.top();
            st.push(i);
        }
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,heights[i]*(right[i]-left[i]-1));
        }
        return maxi;
    }
};
