class Solution {
public:
//~ right rotate
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        k %= sz;
        reverse(nums.begin(), nums.end()-k);
        reverse(nums.end()-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
