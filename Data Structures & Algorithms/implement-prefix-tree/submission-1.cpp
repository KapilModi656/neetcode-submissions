class PrefixTree {
public:
    class TrieNode{
        public:
        char val;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char ch){
            val=ch;
            for(int i=0;i<26;i++) children[i]=NULL;
            isTerminal=false;
        }
    };
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode('a');
    }
    void insertUtil(TrieNode* root,string word,int i){
        int n=word.size();
        if(i==n) {
            root->isTerminal=true;
            return;
        }
        int index = word[i]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[i]);
            root->children[index] = child;
        }
        insertUtil(child,word,i+1);

    }
    
    void insert(string word) {
        insertUtil(root,word,0);
    }
    bool searchUtil(TrieNode* root,string word,int i){
        int n=word.size();
        if(i==n&&root->isTerminal!=true) return false;
        else if(i==n) return true;
        int index = word[i]-'a';
        if(root->children[index]==NULL) return false;
        return searchUtil(root->children[index],word,i+1);
    }
    bool search(string word) {
        return searchUtil(root,word,0);
    }
    bool startsUtil(TrieNode* root,string word,int i){
        int n=word.size();
        if(i==n) return true;
        int index = word[i]-'a';
        if(root->children[index]==NULL) return false;
        return startsUtil(root->children[index],word,i+1);
    }
    bool startsWith(string prefix) {
        return startsUtil(root,prefix,0);
    }
};
