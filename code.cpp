#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <string>

using namespace std;

class SnakeGame {
private:

    // 0 empty box
    // 1 food
    // 2 body
    vector<vector<int> > grid;
    int gridWidth, gridHeight;
    deque<pair<int, int> > snakeBody;
    queue<pair<int, int> > foodsQueue; // front is shown on the grid

    bool validNewHead(const pair<int , int> &newHead) const {
        if (newHead.first < 0 || newHead.first >= gridHeight) {
            return false;
        }
        if (newHead.second < 0 || newHead.second >= gridWidth) {
            return false;
        }
        if (grid[newHead.first][newHead.second] == 2 && newHead != snakeBody.back()) {
            return false;
        }
        return true;
    }

    int moveOneStep(const char dir) {
        pair<int, int> curHead = snakeBody.front();
        pair<int, int> newHead = curHead;
        switch (dir) {
            case 'U' :
                newHead.first = curHead.first - 1;
                break;
            case 'L' :
                newHead.second = curHead.second - 1;
                break;
            case 'R' :
                newHead.second = curHead.second + 1;
                break;
            case 'D' :
                newHead.first = curHead.first + 1;
                break;
        }
        if (!validNewHead(newHead)) {
            return -1;
        }
        if (grid[newHead.first][newHead.second] == 0 || grid[newHead.first][newHead.second] == 2) { //newHead is empty
            grid[snakeBody.back().first][snakeBody.back().second] = 0;
            snakeBody.pop_back();
            snakeBody.push_front(newHead);
            grid[newHead.first][newHead.second] = 2;
        } else if (grid[newHead.first][newHead.second] == 1) { //newHead is food
            grid[newHead.first][newHead.second] = 2;
            foodsQueue.pop();
            if (!foodsQueue.empty()) {
                grid[foodsQueue.front().first][foodsQueue.front().second] = 1;
            }
        } 
        return snakeBody.size();
    }

public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int> > food) {
        vector<int> temp;
        gridWidth = width;
        gridHeight = height;
        for (int i = 0; i <= width - 1; i++) {
            temp.push_back(0);
        }
        for (int i = 0; i <= height - 1; i++) {
            grid.push_back(temp);
        }
        snakeBody.push_back(make_pair(0, 0));
        grid[0][0] = 2;
        for (int i = 0; i <= (int) food.size() - 1; i++) {
            foodsQueue.push(food[i]);
        }
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        for (int i = 0; i <= (int) direction.length() - 1; i++) {
            int tempLen = moveOneStep(direction[i]);
            if (tempLen == -1) {
                return -1;
            }
        }
        return snakeBody.size();
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */

int main() {
    int row, col, foodNum, x, y;
    string dir;
    vector<pair<int, int> > foods;
    cin >> row >> col;
    cin >> foodNum;
    for (int i = 1; i <= foodNum; i++) {
        cin >> x >> y;        
        foods.push_back(make_pair(x, y));
    }
    cin >> dir;
    SnakeGame *obj = new SnakeGame(col, row, foods);
    int ans1 = obj->move(dir);
    cout << ans1 << endl;
    return 0;
}






