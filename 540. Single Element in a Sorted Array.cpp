#include <vector>
#include <cstddef>
#include <iostream>
using namespace std;

const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;

void *operator new(size_t size)
{
    constexpr std::size_t alignment = alignof(std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char *aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}
void operator delete(void *ptr, unsigned long) {}
void operator delete(void *ptr) {}
void operator delete[](void *ptr) {}
// i paseted seen in asw other person

class Solution
{
public:
    int singleNonDuplicate(vector<int> &A)
    {
        int n = A.size();
        if (n == 1)
            return A[0];

        //    // o(n) approch
        //     for (int i = 1; i < n; i++){
        //        if (A[i - 1] != A[i] && A[i] != A[i + 1])
        //        {
        //           return A[i];
        //         }
        //      }
        //     return -1;



        //     // edge cases but spce O(n)
        //      if (n == 1)
        //     return A[0];
        //   if (A[0] != A[1])
        //     return A[0];
        //     if (A[n - 1] != A[n - 2])
        //     return A[n - 1];

        //    for (int i = 1; i < n - 1; i++)
        // {
        //     if (A[i] != A[i - 1] && A[i] != A[i + 1])
        //     {
        //         return A[i];
        //     }
        // }
        // return -1;



        
        //// O(log n ) approch
        int st = 0, end = n - 1;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;

            if (mid == 0 && A[0] != A[1])
                return A[mid];

            if (mid == n - 1 && A[n - 1] != A[n - 2])
                return A[mid];

            if (A[mid - 1] != A[mid] && A[mid] != A[mid + 1])
                return A[mid];

            if (mid % 2 == 0) // even
            {
                if (A[mid - 1] == A[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    st = mid + 1;
                }
            }
            else
            { // odd
                if (A[mid - 1] == A[mid])
                {
                    st = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};