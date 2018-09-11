#include "base.h"

class Solution {
private:
	vector<unordered_map<long long, int>> dp; //diff -> how many I can add in the next diff
	int ans;

	void solveDP(const vector<int> &A) {
		unordered_map<long long, int> temp;
		dp.push_back(temp);
		temp.insert(make_pair((long long) A[1] - (long long) A[0], 1));
		dp.push_back(temp);
		ans = 0;

		for (int i = 2; i < A.size(); i++) {
			temp.clear();
			for (int j = i - 1; j >= 0; j--) {
				long long diff = (long long) A[i] - (long long) A[j];
				auto iter1 = dp[j].find(diff);
				int passToNext;
				if (iter1 != dp[j].end()) {
					ans += iter1->second;
					passToNext = iter1->second + 1;
				} else {
					passToNext = 1;
				}
				auto iter2 = temp.find(diff);
				if (iter2 == temp.end()) {
					temp.insert(make_pair(diff, passToNext));
				} else {
					temp[diff] += passToNext;
				}
			}
			dp.push_back(temp);
		}
	}

public:
    int numberOfArithmeticSlices(vector<int>& A) {
		if (A.size() < 3) {
			return 0;
		}
		solveDP(A);
		return ans;
    }
};

int main() {
	Solution *solution = new Solution();
	vector<int> v = {1, 2, 3, 0, 1, 2, 3, 4};
	cout << solution->numberOfArithmeticSlices(v) << endl;
	return 0;
}
