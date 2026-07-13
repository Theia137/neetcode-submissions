class DynamicArray {
public:
    vector<int> arr;
    int size = 0;
    int cap;

    DynamicArray(int capacity) {
        this->cap = capacity;
        arr.resize(cap);
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(getSize() == getCapacity()){
            resize();
        }
        arr[size] = n;
        size += 1;
    }

    int popback() {
        int ans = arr[size-1];
        size -= 1;
        return ans;
    }

    void resize() { 
        cap *= 2;
        arr.resize(cap);
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return cap;
    }
};
