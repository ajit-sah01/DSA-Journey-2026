#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // // // This is O(n^2) sooo bad
        //    int n = nums.size();
        //    for(int i =0;i<n;i++){
        //      for(int j = 0; j<n-1;j++){
        //         if(nums[j] > nums[j+1]){
        //             swap(nums[j], nums[j+1]);
        //         }
        //      }
        //    }

        // // by Using STL but this is bad Approch
        // sort(nums.begin(),nums.end());

        // //// O(n) approch
        //    int n = nums.size();
        //     int count0 = 0, count1 = 0, count2 = 0;
        //     //// O(n)
        //     for (int i = 0; i < n; i++)
        //     {
        //         if (nums[i] == 0)
        //             count0++;
        //         else if (nums[i] == 1)
        //             count1++;
        //         else
        //             count2++;
        //     }
        //     int idx = 0;
        //     for (int i = 0; i < count0; i++)
        //     {
        //         nums[idx++] = 0;
        //     }
        //     for (int i = 0; i < count1; i++)
        //     {
        //         nums[idx++] = 1;
        //     }
        //     for (int i = 0; i < count2; i++)
        //     {
        //         nums[idx++] = 2;
        //     }

        // // dutch national Plag Algorithm
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};