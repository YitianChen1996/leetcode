#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <map>

using namespace std;

class HitCounter {
private:
    deque<pair<int, int>> window; // timestamp -> number map
    int hitCount;

    void clearWindow(int lastTime) {
        while (!window.empty() && window.front().first <= lastTime - 300) {
            hitCount -= window.front().second;
            window.pop_front();
        }
        if (window.empty()) {
            hitCount = 0;
        }
    }

public:
    /** Initialize your data structure here. */
    HitCounter() {
        window.clear();
        hitCount = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (window.empty()) {
            window.push_back(make_pair(timestamp, 1));
            hitCount++;
            return;
        }
        if (window.back().first == timestamp) {
            window.back().second++;           
            hitCount++;
        } else {
            window.push_back(make_pair(timestamp, 1));
            hitCount++;
        }
        clearWindow(window.back().first);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        clearWindow(timestamp);
        return hitCount;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */

int main() {
    HitCounter *counter = new HitCounter();
    counter->hit(1);
    counter->hit(2);
    counter->hit(3);
    cout << counter->getHits(4) << endl;
    counter->hit(300);
    cout << counter->getHits(300) << endl;
    cout << counter->getHits(301) << endl;
    cout << counter->getHits(599) << endl;
    cout << counter->getHits(600) << endl;
    cout << counter->getHits(602) << endl;
    return 0;
}




