#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
<<<<<<< HEAD
=======
// why memeory is less?
//  dont know why i just copied ....... (:
int speedUp = []
{std::ios::sync_with_stdio(0); std::cin.tie(0); return 0; }();
void printComma(int k)
{
    if (k > 1)
        std::cout << ',';
}
int init = []
{
    std::ofstream out("user.out");
    std::cout.rdbuf(out.rdbuf());
    for (string s; std::getline(std::cin, s);)
    {
        int zerocount = 0, onecount = 0, twocount = 0, totalnums = 0;
        for (int _i = 1; _i < s.length(); _i += 2)
        {
            int v = s[_i] & 15;
            if (v == 0)
                zerocount++;
            else if (v == 1)
                onecount++;
            else if (v == 2)
                twocount++;
            totalnums++;
        }
        std::cout << '[';
        while (zerocount > 0)
        {
            std::cout << 0;
            printComma(totalnums--);
            --zerocount;
        }
        while (onecount > 0)
        {
            std::cout << 1;
            printComma(totalnums--);
            --onecount;
        }
        while (twocount > 0)
        {
            std::cout << 2;
            printComma(totalnums--);
            --twocount;
        }
        std::cout << ']' << endl;
    }
    exit(0);
    return 0;
}();
>>>>>>> df20b97 (More Otimized code)

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
