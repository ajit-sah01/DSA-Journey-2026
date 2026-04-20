#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        // int MaxIndex  = 0;
        // // O(n) Apprioch hite my mide under 1 min
        // for(int i =0 ; i< arr.size(); i++){
        //     MaxIndex = max(MaxIndex , arr[i]);
        // }
        // for(int i =0 ; i< arr.size(); i++){
        //     if(arr[i] == MaxIndex){
        //         return i ;
        //     }
        // }
        //  return -1;

                // int MaxIndex  = 0;
        // // more short
        // for(int i = 1 ; i<arr.size() ; i++){
        //     if(arr[MaxIndex] < arr[i]){
        //          MaxIndex = i;
        //     }
        // }
        //  return MaxIndex;

        //// O(log n)
        int st = 1, end = arr.size() - 1;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            else if (arr[mid - 1] < arr[mid])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;
    }
};