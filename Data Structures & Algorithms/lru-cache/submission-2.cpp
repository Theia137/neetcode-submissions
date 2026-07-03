class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    list<int> container;
    unordered_map<int, int> maptainer;   
    int size = 0;
    int cap;
    
    int get(int key) {
        if(maptainer.find(key) != maptainer.end()){
            auto iit = find(container.begin(), container.end(), key);
            container.splice(container.end(), container, iit);
            return maptainer[key];
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto it = maptainer.find(key);
        if(it != maptainer.end()){
            maptainer[key] = value;
            auto iit = find(container.begin(), container.end(), key);
            container.splice(container.end(), container, iit);
        }
        else{
            if(size < cap){
                maptainer.insert({key, value});
                container.push_back(key);
                size += 1;
            }
            else{
                maptainer.insert({key, value});
                container.push_back(key);
                maptainer.erase(container.front());
                container.pop_front();
            }   
        }
    }
};
