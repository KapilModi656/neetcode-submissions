class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            string ch = tokens[i];
            if(ch=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(a+b);
            }
            else if(ch=="-"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b-a);
            }
            else if(ch=="*"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(a*b);
            }
            else if(ch=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b/a);
            }
            else{
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};
