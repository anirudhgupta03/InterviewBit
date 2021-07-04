//Ref: https://www.youtube.com/watch?v=Xc4sICC8m4M&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&t=0s
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
