//Ref: https://www.youtube.com/watch?v=Xc4sICC8m4M&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&t=0s
//Method - 1
struct node{
    int mykey;
    int myval;
    struct node* next;
    struct node* prev;
    node(int key, int val){
        mykey = key;
        myval = val;
    }
};


int cap = 0;
unordered_map<int,struct node*> mymap;

struct node* head = new node(-1,-1); 
struct node* last = new node(-1,-1);

LRUCache::LRUCache(int capacity) {
    mymap.clear();
    cap = capacity;
    head -> next = last;
    last -> prev = head;
}
void addnode(node* newnode){
    node* temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
}

void deletenode(node* delnode){
    node* delprev = delnode -> prev;
    node* delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
}
int LRUCache::get(int key) {
    if(mymap.find(key) == mymap.end()){
        return -1;
    }
    node* resnode = mymap[key];
    int res = resnode -> myval;
    mymap.erase(key);
    deletenode(resnode);
    addnode(resnode);
    mymap[key] = head -> next;
    return res;
}

void LRUCache::set(int key, int value) {
    if(mymap.find(key) != mymap.end()){
        node* existingnode = mymap[key];
        mymap.erase(key);
        deletenode(existingnode);
    }
    
    if(mymap.size() == cap){
        mymap.erase(last->prev->mykey);
        deletenode(last->prev);
    }
    
    addnode(new node(key, value));
    mymap[key] = head -> next;
}

//Method - 2
//Ref: https://www.youtube.com/watch?v=JxtmaAFfVBo
struct Node{
    int key, value;
    Node* prev, *next;
    Node(){
        prev = NULL;
        next = NULL;
    }
};

Node* head, *tail;
int cap;
unordered_map<int,Node*> cache;

void add(Node* node){
    Node* nbr = head -> next;
    node -> next = nbr;
    node -> prev = head;
    nbr -> prev = node;
    head -> next = node;
}

void remove(Node* node){
    Node* prevnbr = node -> prev;
    Node* nextnbr = node -> next;
    prevnbr -> next = nextnbr;
    nextnbr -> prev = prevnbr;
    node -> next = NULL;
    node -> prev = NULL;
}

void moveToFront(Node* node){
    remove(node);
    add(node);
}

LRUCache::LRUCache(int capacity) {
    cache.clear();
    head = new Node();
    tail = new Node();
    head -> next = tail;
    tail -> prev = head;
    cap = capacity;
}

int LRUCache::get(int key) {
    if(cache.find(key) == cache.end()){
        return -1;
    }
    else{
        Node* node = cache[key];
        int val = node -> value;
        moveToFront(node);
        return val;
    }
}

void LRUCache::set(int key, int value) {
    if(cache.find(key) == cache.end()){
        Node* curr = new Node();
        curr -> key = key;
        curr -> value = value;
        if(cache.size() == cap){
            Node* LRU_Node = tail -> prev;
            cache.erase(LRU_Node -> key);
            remove(LRU_Node);
        }
        cache[key] = curr;
        add(curr);
    }
    else{
        Node* node = cache[key];
        node -> value = value;
        moveToFront(node); 
    }
}
