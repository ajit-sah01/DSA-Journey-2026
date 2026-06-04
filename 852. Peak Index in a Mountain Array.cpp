class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        // /// Linear Serach
        // int n = arr.size();
        // int ans = arr[0];
        // for(int i =0; i<n ; i++ ){
        //     ans = max(ans, arr[i]);
        // }
        // for(int i =0; i<n  ; i++ ){
        //     if(arr[i] == ans){
        //         return i;
        //     }
        // }
        // return -1;

       //// Binary Search
        int st = 0;
        int end = arr.size() - 1;
        while (st < end)
        {
            int mid = st + (end - st) / 2;

            if (arr[mid] < arr[mid + 1])
            {
                st = mid + 1;
            }
            else
            {
                end = mid;
            }
        }

        return st;
    }
};
