class MyLinkedList {
private:
    struct Node{
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {};
        Node(int x, Node* next) : val(x), next(next) {};
    };
    Node* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    } 
    
    int get(int index) {
        if(size < 0 || index >= size){
            return -1;
        }
        else{
            Node* curr = head;
            for(int i=0; i<index; i++){
                curr = curr->next;
            }
            return curr->val;
        }
    }
    
    void addAtHead(int val) {
        head = new Node(val, head);
        size += 1;
    }
    
    void addAtTail(int val) {
        if(size == 0){
            head = new Node(val, head);
            return;
        }
        Node* curr = head;
        Node* tail = new Node(val);
        for(int i=0; i<size-1; i++){
            curr=curr->next;
        }
        curr->next = tail;
        size += 1;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size){
            return;
        }
        Node* add = new Node(val);
        Node* curr = head;
        for(int i=0; i<index-1; i++){
            curr = curr->next;
        }
        Node* nextnext = curr->next;
        curr->next = add;
        add->next = nextnext;
        size += 1;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size){
            return;
        }
        Node* curr = head;
        for(int i=0; i<index-1; i++){
            curr = curr->next;
        }
        Node* next = curr->next;
        Node* newnext = next->next;
        curr->next = newnext;
        size -= 1;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */