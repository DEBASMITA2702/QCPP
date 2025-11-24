class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());

        int total = 0 , left = 0, right = piles.size() - 1;

        while(left < right){
            right--;
            total += piles[right];
            right--;
            left++;
        }

        return total;
    }
};