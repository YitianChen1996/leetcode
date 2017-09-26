#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    int slen1, slen2;

    int lookForward(string s, int index, char c) {//see how many continuous letter c
        int ans = 0;
        while (s[index] == c) {
            ans++;
            index++;
        }
        return ans;
    }

public:
    bool isMatch(string s, string p) {

        slen1 = s.length();
        slen2 = p.length();
        int p1 = 0, p2 = 0;
        while (1) {
            if (s[p1] == p[p2] && p2 + 1 <= slen2 - 1 && p[p2 + 1] != '*') {
                if (p1 == slen1 - 1 && p2 == slen2 - 1) {
                    return true;
                }
                p1++;
                p2++;
            } else if (s[p1] == p[p2] && p2 + 1 <= slen2 - 1 && p[p2 + 1] == '*') {

            }
        }
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> v;
    int n, a;
    cin >> n;
    for (int i = 0; i <= n - 1; i++) {
        cin >> a;
        v.push_back(a);
    }
    printf("%d", solution->jump(v));
    return 0;
}