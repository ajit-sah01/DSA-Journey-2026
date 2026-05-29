class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        short n = numbers.size();

        //     // BurtForce Approch O(n^2)
        //    for(int i =0 ; i<n ; i++){
        //     for(int j =0; j<n ; j++){
        //         if(numbers[i]+numbers[j] == target){
        //             return {i+1, j+1};
        //         }
        //     }
        //    }
        //    return {-1,-1};

        // optimal Aproch By Two Pointer
        short st = 0, end = n - 1;
        while (st < end)
        {
            short mid = st + (end - st) / 2;
            int sum = (numbers[st]) + (numbers[end]);
            if (sum == target)
            {
                return {st + 1, end + 1};
            }
            else if (sum < target)
            {
                st++;
            }
            else
            {
                end--;
            }
        }
        return {-1, -1};
    }
};