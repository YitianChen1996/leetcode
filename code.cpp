#include "base.h"

class Solution {
private:
	unordered_map<char, int> dnaToIndex;
	unordered_map<int, int> encodeToFreq;
	vector<string> ans;
	int base[10];

	void init(const string &s) {
		dnaToIndex['A'] = 0;
		dnaToIndex['C'] = 1;
		dnaToIndex['G'] = 2;
		dnaToIndex['T'] = 3;
		int b = 1;
		for (int i = 0; i < 10; i++) {
			base[i] = b;
			b *= 4;
		}
	}

public:
    vector<string> findRepeatedDnaSequences(string s) {
		init(s);
		if (s.length() <= 10) { return ans; }
		int curEncode = 0;
		for (int i = 0; i < 10; i++) {
			curEncode += dnaToIndex[s[i]] * base[9 - i];
		}
		encodeToFreq[curEncode] = 1;
		for (int beginIndex = 1; beginIndex <= s.length() - 10; beginIndex++) {
			curEncode -= (dnaToIndex[s[beginIndex - 1]] * base[9]); // remove the left most one
			curEncode *= 4; // right shift
			curEncode += (dnaToIndex[s[beginIndex + 9]] * base[0]); // move in the right most one
			auto iter = encodeToFreq.find(curEncode);
			if (iter == encodeToFreq.end()) {
				encodeToFreq.insert(make_pair(curEncode, 1));
			} else if (iter->second == 1) { // the string begin at beginIndex first repeated. Record it in the answer.
				ans.push_back(s.substr(beginIndex, 10));
				iter->second++;
			} else {
				iter->second++;
			}
		}
		return ans;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<string> ans;
	ans = solution->findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
