// class Solution
// {
// public:
    // //// Brutforce Appocch
    // vector<vector<int>> threeSum(vector<int> &nums)
    // {
    //     int n = nums.size()  ;
    //     set<vector<int>> s;      // set unique Triplets Store
    //     vector<vector<int>> ans; // set unique Triplets Store
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = i + 1; j < n; j++)
    //         {
    //             for (int k = j + 1; k < n; k++)
    //             {
    //                 if ((nums[i] + nums[j] + nums[k]) == 0)
    //                 {
    //                     vector<int> trip = {nums[i],
    //                                         nums[j],
    //                                         nums[k]};
    //                     sort(trip.begin(), trip.end());
    //                     if (s.find(trip) == s.end())
    //                     {
    //                         s.insert(trip);
    //                         ans.push_back(trip);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }
// };




// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {
//         int n = nums.size();

//         set<vector<int>> uniqueTrip;


//         for (int i = 0; i < n; i++)
//         {
//             int tar = -nums[i];
//             set<int> s;

//             for (int j = i + 1; j < n; j++)
//             {
//                 int third = tar - nums[j];
//                 if (s.find(third) != s.end())
//                 {
//                     vector<int> trip = {nums[i], nums[j], third};
//                     sort(trip.begin(), trip.end());
//                     uniqueTrip.insert(trip);
//                 }
//                 s.insert(nums[j]);
//             }
//         }
//         vector<vector<int>> ans(uniqueTrip.begin(), uniqueTrip.end());
//         return ans;
//     }
// }




// better Appooch but silii TLE Time Com O(n * lon n) Otimized
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0)
                {
                    j++;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    // Found triplet
                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    // Skip duplicate j values
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                }
            }
        }

        return ans;
    }
};