#include <iostream>
#include <vector>
using namespace std;




class Solution {
public:
    int firstBadVersion(int n) {
        int st = 1;
        int end = n;
        
        while (st < end) {
            // Standard way to find mid while preventing (st + end) overflow
            int mid = st + (end - st) / 2;
            
            if (isBadVersion(mid)) {
                // If mid is bad, the first bad version is mid or to the st
                end = mid  ;
            } else {
                // If mid is good, the first bad version is strictly to the end
                st = mid + 1;
            }
        }
        
        // After the loop, st == end, pointing to the first bad version
        return st;
    }
};