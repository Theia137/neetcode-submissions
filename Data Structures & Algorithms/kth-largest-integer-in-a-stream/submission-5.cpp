class KthLargest {
public:
    vector<int> pq;
    int cap;

    KthLargest(int k, vector<int>& nums) {
        this -> cap = k;
        pq.push_back(0);
        for(int elem : nums){
            pq.push_back(elem);
            heapify(pq, cap);
        }
    }
    
    int add(int val) {
        pq.push_back(val);
        heapify(pq, cap);
        return pq[1];
    }

    void heapify(vector<int>& pq, int cap){
        if(pq.size() <= cap+1){
            heapifyup(pq, pq.size()-1);
        }
        else{
            if(pq[1] < pq[cap+1]){
                pq[1] = pq[cap+1];
                pq.pop_back();
                heapifydown(pq, 1);
            }   
            else{
                pq.pop_back();
            }
        }
    }

    void heapifyup(vector<int>&pq, int index){
        while(index > 1){
            int pidx = index/2;
            if(pq[pidx] > pq[index]){
                swap(pq[pidx], pq[index]);
                index = pidx;
            }
            else{
                break;
            }
        }
    }

    void heapifydown(vector<int>&pq, int index){
        while(index <= cap){
            int left = index*2;
            int right = index*2+1;
            int minidx = index;
            if(left<=cap && pq[left] < pq[minidx]){
                minidx = left;
            }
            if(right<=cap && pq[right] < pq[minidx]){
                minidx = right;
            }
            if(minidx == index){
                break;
            }
            else{
                swap(pq[index], pq[minidx]);
                index = minidx;
            }
        }
    }
};
