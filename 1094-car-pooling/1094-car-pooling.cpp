class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> difference(1001,0);

        for(auto &x : trips){
            int p=x[0] , from = x[1] , to= x[2];
            difference[from] += p;
            difference[to] -= p; 
        }

        int curr = 0;
        for(int i=0; i<=1000;i++){
            curr += difference[i];

            if(curr > capacity){
                return false;
            }
        }

        return true;
    }
};