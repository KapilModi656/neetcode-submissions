class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n=words.size();
        unordered_map<char,int> mp;
  
        for(int i=0;i<26;i++){
            mp[order[i]]=i;
           
        }
        for(int i=0;i<n-1;i++){
            string w1=words[i];
            string w2=words[i+1];
            for(int j=0;j<w1.size();j++){
                if(j>=w2.size()){
                    return false;
                }
                if(mp[w1[j]]>mp[w2[j]]) return false;
                else if(mp[w1[j]]<mp[w2[j]]) break;
            }
        }
        return true;

    }
};