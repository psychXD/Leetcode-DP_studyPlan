https://leetcode.com/problems/wiggle-subsequence/?source=submission-noac
int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
        return n;
    }
    vector<int> diffs(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        diffs[i] = nums[i + 1] - nums[i];
    }
  bool allZeros = all_of(diffs.begin(), diffs.end(), [](int diff) { return diff == 0; });
    if (allZeros) {
        return 1;
    }
    vector<int> lis(n - 1, 1);
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 0; j < i; ++j) {
            if ((diffs[i] > 0 && diffs[j] < 0) || (diffs[i] < 0 && diffs[j] > 0)) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    int maxLen = 1;
    for (int len : lis) {
        maxLen = max(maxLen, len);
    }
    return maxLen + 1;
}
