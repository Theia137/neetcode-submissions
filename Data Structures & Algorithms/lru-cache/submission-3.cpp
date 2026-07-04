class LRUCache {
public:
    int capacity;
    int size = 0;
    unordered_map<int, pair<int, list<int>::iterator>> container;
    list<int> order;

    LRUCache(int capacity) {
        this->capacity = capacity;    
    }
    
    int get(int key) {
        auto it = container.find(key);
        if(it != container.end()){
            order.erase(container[key].second);
            order.push_back(key);
            container[key].second = --order.end();
            return container[key].first;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto it = container.find(key);
        if(it != container.end()){
            order.erase(container[key].second);
            order.push_back(key);
            container[key] = {value, --order.end()};
        }
        else{
            if(size < capacity){
                order.push_back(key);
                container[key] = {value, --order.end()};
                size += 1;
            }
            else{
                container.erase(order.front());
                order.pop_front();
                order.push_back(key);
                container[key] = {value, --order.end()};
            }
        }
    }
};
