class Solution {
 public:
  long long countOperationsToEmptyArray(vector<int>& nums) {
    const int n = nums.size();
    long ans = n;
    unordered_map<int, int> x; // store original index

    for (int i=0; i<n; ++i)
      x[nums[i]] = i; // enter original indices into map

    ranges::sort(nums); // sort array

    for (int i=1; i<n; ++i) 
      if (x[nums[i]] < x[nums[i-1]])
      // check if original index of current element is less than original index of prev element
        ans += n - i;

    return ans;
  }
};