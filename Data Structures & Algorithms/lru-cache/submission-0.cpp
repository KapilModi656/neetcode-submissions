class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key,int _val){
            key = _key;
            val = _val;
            next=NULL;
            prev=NULL;
        }
        ~Node(){
            next=NULL;
            prev=NULL;
        }
    };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    map<int,Node*> mp;
    void addNode(Node* node){
        Node* next = head->next;
        head->next=node;
        node->next = next;
        node->prev = head;
        next->prev = node;
       
    }
    void deleteNode(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        
    }
    
    int size ;
    LRUCache(int capacity) {
        head->next=tail;
        tail->prev=head;
        size = capacity;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        Node* node = mp[key];
        deleteNode(node);
        addNode(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* node = mp[key];
            deleteNode(node);
            node->val = value;
            addNode(node);
            return;
       
        }
        else if(mp.size()==size){
            Node* lru = tail->prev;
            mp.erase(lru->key);
            deleteNode(lru);
            Node* node = new Node(key,value);
            addNode(node);
            mp[key] = node;
        }
        
        else{
            Node* node = new Node(key,value);
            addNode(node);
            mp[key]=node;
        }
    }
};
