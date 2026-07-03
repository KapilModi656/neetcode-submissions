class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n=words.size();
        vector<int> ans(n,0);
        map<char,int> mp;
        for(int i=0;i<26;i++){
            mp[order[i]]=i+1;
        }
        for(int i=0;i<n-1;i++){
            string w1 = words[i];
            string w2 = words[i+1];
            int m=w1.size();
            for(int j=0;j<m;j++){
                if(j>=w2.size()) return false;
                if(mp[w1[j]]<mp[w2[j]]){
                    break;
                }
                else if(mp[w1[j]]>mp[w2[j]]) return false;
            }
        }
        return true;

    }
};