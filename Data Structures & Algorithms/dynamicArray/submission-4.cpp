class DynamicArray {
public:
    int* arr;
    int size;
    int cap;

    DynamicArray(int capacity) {
        this->cap = capacity;
        this->size = 0;
        arr = new int[cap];
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
        int *newarr = new int[cap*2];
        for(int i=0; i<cap; i++){
            newarr[i] = arr[i];
        }
        cap *= 2;
        delete [] arr;
        arr = newarr;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return cap;
    }
};
