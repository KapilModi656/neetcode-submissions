class Solution {
public:
    void generate(string s,vector<string>& ans,int open,int close){
        if(open==0&&close==0){
            ans.push_back(s);
        }
        if(open>0){
            generate(s+'(',ans,open-1,close);
        }
        if(close>open){
            generate(s+')',ans,open,close-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string> ans;
        int open=n;
        int close=n;
        generate(s,ans,open,close);
        return ans;
    }
};
