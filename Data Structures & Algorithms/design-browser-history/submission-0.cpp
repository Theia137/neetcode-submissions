class BrowserHistory {
private:
    struct Node{
        string link;
        Node* next;
        Node* prev;
        Node(string homepage, Node* next, Node* prev) : link(homepage), next(next), prev(prev){};
    };
    Node* now;

public:
    BrowserHistory(string homepage) {
        now = new Node(homepage, nullptr, nullptr);
    }
    
    void visit(string url) {
        Node* prevpage = now;
        now = new Node(url, nullptr, prevpage);
        if(prevpage != nullptr){
            prevpage->next = now;
        }
    }
    
    string back(int steps) {
        for(int i=0; i<steps; i++){ 
            if(now->prev == nullptr){
                return now->link;
            }
            now = now->prev;
        }
        return now->link;
    }
    
    string forward(int steps) {
        for(int i=0; i<steps; i++){
            if(now->next == nullptr){
                return now->link;
            }
            now = now->next;
        }
        return now->link;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */