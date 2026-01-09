#pragma GCC optimize("Ofast")
static const int fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    // We use a pointer and manual memory to stay fast but avoid stack-use-after-scope
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, (int)nums.size() - 1);
    }

private:
    // 'inline' suggests the compiler replace the call with the function body
    inline TreeNode* build(const vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        // Use mid-point calculation that avoids overflow
        int mid = left + (right - left) / 2;

        // Direct allocation
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = build(nums, left, mid - 1);
        root->right = build(nums, mid + 1, right);

        return root;
    }
};