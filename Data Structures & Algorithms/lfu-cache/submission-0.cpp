class LFUCache {
public:
    class Node{
        public:
        int key,val,freq;
        Node* next;
        Node* prev;
        Node(int _key,int _val){
            key = _key;
            val = _val;
            freq = 1;
            next=NULL;
            prev=NULL;
        }
        ~Node(){
            next=NULL;
            prev=NULL;
        }
    };
    class List{
        public:
        Node* head = new Node(-1,-1);
        Node* tail = new Node(-1,-1);
        int size;
        List(){
            
            head->next = tail;
            tail->prev = head;
            size=0;
        }
        void addNode(Node* node){
            Node* next=head->next;
            head->next = node;
            node->next = next;
            next->prev = node;
            node->prev = head;
            size++;
        }
        void deleteNode(Node* node){
            Node* next = node->next;
            Node* prev = node->prev;
            prev->next = next;
            next->prev = prev;
            size--;
        }

    };
    int size;
    int capacity;
    map<int,Node*> mp;
    map<int,List*> freq;
    LFUCache(int cap) {
        capacity=cap;
        size=0;
    }
    void update(Node* node){
        int f = node->freq;
        List* l = freq[f];
        l->deleteNode(node);
        if(l->size==0){
            freq.erase(f);
        }
        node->freq +=1;
        if(!freq.count(node->freq)){
            freq[node->freq] = new List();
        }
        freq[node->freq]->addNode(node);
    }
    int get(int key) {
        if(!mp.count(key)) return -1;
        Node* node = mp[key];
        update(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* node =mp[key];
            node->val = value;
            update(node);
            return;
        }
        if(size==capacity){
            List* start = (*freq.begin()).second;
            Node* lruNode = start->tail->prev;
            mp.erase(lruNode->key);
            start->deleteNode(lruNode);
            delete lruNode;
            size--;
        }
        Node* node = new Node(key,value);
        mp[key] = node;
        if(!freq.count(1)){
            freq[1] = new List();
        }
        freq[1]->addNode(node);
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */