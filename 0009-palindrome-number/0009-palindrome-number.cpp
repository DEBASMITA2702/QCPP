class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long num = 0, x1 = x;
        while (x1 != 0){
            num = (num * 10) + (x1 % 10);
            x1 /= 10;
        }
        if(x == num) return true;
        else return false;
    }
};