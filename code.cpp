#include "base.h"

bool cmp(int a, int b) {
    if (a == b) { return false; }
    string sa = to_string(a);
    string sb = to_string(b);
    int pa = 0, pb = 0;
    while (sa[pa] == sb[pb]) {
        pa++;
        pb++;
        if (pa == sa.length()) { pa = 0; }
        if (pb == sb.length()) { pb = 0; }
    }
    return sa[pa] > sb[pb];
}

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ans;
        if (nums[0] == 0) { return "0"; }
        for (int i = 0; i < nums.size(); i++) {
            ans += to_string(nums[i]);
        }
        return ans;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> v = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0};
    cout << solution->largestNumber(v) << endl;
    return 0;
}
