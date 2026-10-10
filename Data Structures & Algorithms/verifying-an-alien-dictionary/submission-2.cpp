class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> mp;
        int j=1;
        for(int i=0;i<order.size();i++){
            mp[order[i]]=j;
            j++;
        }
        for(int i=1;i<words.size();i++){
            string w1=words[i-1],w2=words[i];
            int mini = min(w1.size(),w2.size());
            bool matched=false;
            for(int j=0;j<mini;j++){
                if(w1[j]!=w2[j]){
                    if(mp[w1[j]]>mp[w2[j]]){
                        return false;
                    }
                    matched=true;
                    break;
                }
            }
            if(!matched&&w1.size()>w2.size()) return false;
        }
        return true;
    }
};