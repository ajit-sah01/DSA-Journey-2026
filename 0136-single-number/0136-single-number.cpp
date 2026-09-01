class Solution {
public:
    int singleNumber(vector<int>& A) {
        int ans = 0;

        for(int val : A){
            ans ^= val;
        }

        return ans;
    }
};