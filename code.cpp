#include "base.h"

class Solution {
private:
	void moveToNextNotLess(auto &iter3, const vector<int> &nums, int aim) {
		if (iter3 == nums.end()) { return; }
		while (*iter3 < aim && iter3 != nums.end()) {
			iter3++;
		}
	}

public:
    int triangleNumber(vector<int>& nums) {
		int ans = 0;
		if (nums.size() < 3) { return 0; }
		sort(nums.begin(), nums.end());
		auto iter_firstNonZero = nums.begin();
		while (*iter_firstNonZero == 0) {
			iter_firstNonZero++;
		}
		if (nums.end() - iter_firstNonZero < 3) { return 0; }

		for (auto iter1 = iter_firstNonZero; iter1 != nums.end() - 2; iter1++) {
			auto iter2 = iter1 + 1;
			auto iter3 = lower_bound(iter2, nums.end(), *iter1 + *iter2);
			for (iter2 = iter1 + 1; iter2 != nums.end() - 1; iter2++) {
				moveToNextNotLess(iter3, nums, *iter1 + *iter2);
				int temp = iter3 - iter2 - 1;
				if (iter3 == nums.end()) {
					ans += (1 + temp) * temp / 2;
					break;
				} else {
					ans += temp;
				}
			}
		}
		return ans;
    }
};

int main() {
	Solution *solution = new Solution();
	vector<int> v = {0, 101, 1001, 2};
	cout << solution->triangleNumber(v) << endl;
	return 0;
}
