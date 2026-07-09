class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n=operations.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            string ch = operations[i];
            if(ch=="+"){
                int a = st.top();
                st.pop();
                int b=st.top();
                st.push(a);
                st.push(a+b);
            }
            else if(ch=="D"){
                int a = st.top();
                st.push(2*a);
            }
            else if(ch=="C"){
                st.pop();
            }
            else{
                int a = stoi(ch);
                st.push(a);
            }
        }
        int sumi = 0;
        while(!st.empty()){
            sumi+=st.top();
            st.pop();
        }
        return sumi;
    }
};