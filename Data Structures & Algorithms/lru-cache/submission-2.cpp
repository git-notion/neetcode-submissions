struct Node {
    int key,value;           // Field to store data
    Node* next,* prev;         // Pointer to the next node
    Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};
class LRUCache {
public:
    int c;
    unordered_map<int,Node*>u;
    Node* head,* last;
    LRUCache(int capacity) {
        c=capacity;
        last =new Node(-1,-1);
        head=new Node(-1,-1);
        head->next=last;
        last->prev=head;
    }
    
    int get(int k) {
        if(u.find(k)==u.end()){
            return -1;
        }
        Node* t=u[k];
        Node* end=last->prev;
        if (t->next == last)
            return t->value;
        t->prev->next=t->next;
        t->next->prev=t->prev;
        end->next=t;
        t->prev=end;
        t->next=last;
        last->prev=t;
        return t->value;
    }
    
    void put(int k, int v) {
        if(u.find(k)!=u.end()){
            Node* t=u[k];
            t->value=v;
            Node* end=last->prev;
            if (t->next == last)
                return;
            t->prev->next=t->next;
            t->next->prev=t->prev;
            end->next=t;
            t->prev=end;
            t->next=last;
            last->prev=t;
            return;
        }

        if(c==0){
            Node* fr=head->next;
            head->next=fr->next;
            fr->next->prev=head;
            u.erase(fr->key);
            delete fr;
            c++;
        }
        last->prev->next=new Node(k,v);
        last->prev->next->next=last;
        last->prev->next->prev=last->prev;
        last->prev=last->prev->next;
        u[k]=last->prev;
        c--;
    }
};
