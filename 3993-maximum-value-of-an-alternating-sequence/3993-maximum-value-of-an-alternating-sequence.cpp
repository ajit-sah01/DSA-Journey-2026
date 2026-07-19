class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        auto  movel = make_tuple( n , s , m  ) ; 

        if(n == 1 ){
            return s;
        }

        long long startup = 1LL * s + m + 1LL * ((n-2)/2) * (m-1);

        long long startdown = 1LL * s + 1LL * ((n-1)/2) * (m-1);

        return max(startup, startdown);
    }
};