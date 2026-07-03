class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto it = max_element(piles.begin(), piles.end());
        int low = 1;
        int high = *it;
        int ans = high;
        
        while(low <= high){
            int mid = (low+high)/2;
            int cc = check(piles, mid, h);
            if(cc > 0){
                low = mid+1;
            }
            else if(cc <= 0){
                ans = min(mid, ans);
                high = mid-1;
            }
        }
        return ans;
    }

    int check(vector<int>& piles, int k, int h){
        int time = 0;
        for(int elem : piles){
            time += ceil((double)elem/k);
        }
        if(time == h){
            return 0;
        }
        else if(time < h){
            return -1;
        }
        else if(time > h){
            return 1;
        }
    }
};
