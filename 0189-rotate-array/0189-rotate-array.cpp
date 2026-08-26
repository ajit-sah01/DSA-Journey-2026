class Solution {
	public: void rotate(vector < int > & nums, int k) {
        ///// Time and Space O(n)
		// int n = nums.size();
		// vector < int > ans(n);
		// for(int i = 0; i < n; i++) {
		// 	ans[(i + k) % n] = nums[i];
		// }
		// nums = ans;




        /////// Time O(n) And Space is O(1)
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
	}
};