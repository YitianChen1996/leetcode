#include "base.h"

class Solution {
private:
	int accu;

public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) {
			return 0;
		}
		accu = 0;
		int im1 = 0;
		for (int i = 2; i < A.size(); i++) {
			if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
				im1++;
				accu += im1;
			} else {
				im1 = 0;
			}
		}
		return accu;
    }
};
