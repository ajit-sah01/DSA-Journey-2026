class Solution {
public:
    int singleNumber(vector<int>& A) {
        short ans = 0;

        for(int val : A){
            ans ^= val;
        }

        return ans;
    }
};