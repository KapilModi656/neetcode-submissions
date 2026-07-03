class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int n=operations.size();
        
        for(int i=0;i<n;i++){
            
            
            if(operations[i]=="+"){
                int prev1=st.top();
                st.pop();
                int prev2=st.top();
                st.push(prev1);
                st.push(prev1+prev2);
            }
            else if(operations[i]=="D"){
                st.push(2*st.top());
               
            }
            else if(operations[i]=="C"){
                st.pop();
                
            }
            else{
                int a=stoi(operations[i]);
                st.push(a);
              
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