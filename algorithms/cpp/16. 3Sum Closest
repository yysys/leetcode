class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int ans = 1e9+7;
		for (int i = 0; i < nums.size() - 2; i++) {
			int j = i + 1;
			int k = nums.size() - 1;
			while (j < k) {
				int delta = nums[i] + nums[j] + nums[k] - target;
				if (abs(delta) < abs(ans)) ans = delta;
				if (delta > 0) k--;
				else j++;
			}
		}
		return target + ans;
	}
};
