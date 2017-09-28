#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
private:
    map<string, int> m, tm;
    int wordsvlen, wlen, slen;

    void init(vector<string> &words) {
        wordsvlen = (int) (words.size());
        wlen = (int) (words[0].length());
        for (int i = 0; i <= wordsvlen - 1; i++) {
            if (m.find(words[i]) == m.end()) {
                m.insert(pair<string, int>(words[i], 1));
            } else {
                m[words[i]]++;
            }
        }
    }

public:
    vector<int> findSubstring(string s, vector<string> &words) {
        init(words);
        slen = (int) s.length();
        for (int i = 0; i <= slen - wlen * wordsvlen; i++) {
            tm = m;
            for (int j = 0; j <= wordsvlen - 1; j++) {
                if (tm.find(s.substr(i + j * wlen, i + (j + 1) * wlen - 1)) != tm.end()) {

                }
            }
        }
    }
};

int main() {
    Solution *solution = new Solution();
    map<string, int> m;
    int n;
    string s;
    cin >> n;
    for (int i = 0; i <= n - 1; i++) {
        cin >> s;
        if (m.find(s) == m.end()) {
            m.insert(pair<string, int>(s, 1));
        } else {
            m[s]++;
        }
    }
    while (1) {
        cin >> s;
        cout << m[s] << endl;
    }
    return 0;
}