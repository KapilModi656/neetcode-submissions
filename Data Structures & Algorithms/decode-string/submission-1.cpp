class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==']'){
                string a="";
                while(!st.empty()&&st.top()!='['){
                    a=st.top()+a;
                    st.pop();
                }
                if(!st.empty()) st.pop();
                if(!st.empty()){
                    string b="";
                    while(!st.empty()&&st.top()>='0'&&st.top()<='9'){
                        b=st.top()+b;
                        st.pop();
                    }
                    int c=stoi(b);
                    for(int i=0;i<c;i++){
                        for(int j=0;j<a.size();j++){
                            st.push(a[j]);
                        }
                    }

                }
            }
            else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};