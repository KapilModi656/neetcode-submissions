class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int n=operations.size();
        int prev1=0;
        int prev2=0;
        for(int i=0;i<n;i++){
            
            
            if(operations[i]=="+"){
                st.push(prev1+prev2);
                prev2=prev1;
                prev1=st.top();
            }
            else if(operations[i]=="D"){
                st.push(2*prev1);
                prev2=prev1;
                prev1=2*prev1;
            }
            else if(operations[i]=="C"){
                st.pop();
                prev1=prev2;
                if(!st.empty()){
                    int b=st.top();

                    st.pop();
                    if(!st.empty()){
                        prev2=st.top();
                    }
                    else{
                        prev2=0;
                    }
                    
                    st.push(b);
                }
                else{
                    prev2=0;
                }
                
            }
            else{
                int a=stoi(operations[i]);
                st.push(a);
                prev2=prev1;
                prev1=a;
            }
        }
        int sumi=0;
        while(!st.empty()){
            int top=st.top();
            st.pop();
            sumi+=top;
        }
        return sumi;
    }
};