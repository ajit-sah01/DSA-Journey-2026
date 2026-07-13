class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
         vector<int> ans;

        for (int start = 1; start <= 9; start++) {

            int num = 0;

            for (int digit = start; digit <= 9; digit++) {

                num = num * 10 + digit;

                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};