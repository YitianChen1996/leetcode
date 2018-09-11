#include "base.h"

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
    }
};

int main() {
	Solution *solution = new Solution();
	vector<int> v = {1, 2, 3, 0, 1, 2, 3, 4};
	cout << solution->numberOfArithmeticSlices(v) << endl;
	return 0;
}
