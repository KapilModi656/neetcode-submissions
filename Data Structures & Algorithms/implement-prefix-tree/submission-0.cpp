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
    void insertUtil(TrieNode* root,string word){
        if(word.length()==0) {
            root->isTerminal=true;
            return;
        }
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child,word.substr(1));

    }
    
    void insert(string word) {
        insertUtil(root,word);
    }
    bool searchUtil(TrieNode* root,string word){
        if(word.size()==0&&root->isTerminal!=true) return false;
        else if(word.size()==0) return true;
        int index = word[0]-'a';
        if(root->children[index]==NULL) return false;
        return searchUtil(root->children[index],word.substr(1));
    }
    bool search(string word) {
        return searchUtil(root,word);
    }
    bool startsUtil(TrieNode* root,string word){
        if(word.size()==0) return true;
        int index = word[0]-'a';
        if(root->children[index]==NULL) return false;
        
        return startsUtil(root->children[index],word.substr(1));
    }
    bool startsWith(string prefix) {
        return startsUtil(root,prefix);
    }
};
