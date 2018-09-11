bool cmp(int a, int b) {
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
    string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), cmp);
		string ans;
		for (int i = 0; i < nums.size(); i++) {
			ans += to_string(nums[i]);
		}
		return ans;
    }
};
