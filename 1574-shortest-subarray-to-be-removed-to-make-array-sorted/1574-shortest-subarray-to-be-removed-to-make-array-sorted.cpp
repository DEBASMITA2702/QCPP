class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size() , left = 0 , right = n-1;

        while(left+1 < n && arr[left] <= arr[left+1]){
            left++;
        }
        if(left == n-1) return 0;
        
        while(right-1 >=0 && arr[right] >= arr[right-1]){
            right--;
        }

        int answer = min(n-left-1 , right);
        int i=0, j=right;

        while(i<=left && j<n){
            if(arr[i] <= arr[j]){
                answer = min(answer, j-i-1);
                i++;
            }
            else{
                j++;
            }
        }
        return answer;
    }
};