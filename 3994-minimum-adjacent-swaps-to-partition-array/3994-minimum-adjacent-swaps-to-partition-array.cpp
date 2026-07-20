class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const int MOD = 1'000'000'007;

        /// make a vector 
        vector <int> ferlomia = nums;

        long long  grater = 0;
        long long mid = 0 ;
        long long ans = 0;

        for(int x : ferlomia){
            if(x<a){
                ans += mid + grater;
            }else if(x <= b){
                ans += grater;
                mid++;
            }else{
                grater++;
            }
            ans %= MOD;
        }

        return (int) (ans % MOD);

        
    }
};