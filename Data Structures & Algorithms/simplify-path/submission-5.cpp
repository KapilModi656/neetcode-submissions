class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        vector<string> components;
        stringstream ss(path);
        string component;
        while(getline(ss,component,'/')){
            if(component.empty()||component==".") continue;
            else if(component==".."){
                if(!components.empty()) components.pop_back();
            }
            else {
                components.push_back(component);
            }
        }
        if(components.size()==0) return "/";
        string ans="";
        for(string dir:components){
            ans+='/'+dir;
        }
        
        return ans;
    }
};