class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int states = minutesToTest / minutesToDie + 1;

        int pigs = 0;
        long long combinations = 1;

        while (combinations < buckets) {
            combinations *= states;
            pigs++;
        }

        return pigs;
    }
};