#include "base.h"

class Solution {
private:
	vector<vector<double>> grid;
	unordered_map<string, int> stringToIndex;

	int getIndex(const string &s) {
		auto iter = stringToIndex.find(s);
		if (iter == stringToIndex.end()) {
			stringToIndex.insert(make_pair(s, stringToIndex.size()));
			return (int) stringToIndex.size() - 1;
		} else {
			return iter->second;
		}
	}

	void init(const vector<pair<string, string>> &equations, const vector<double>& values) {
		/* In the first pass, we just want to build up the map and find out how many different string in the input */
		for (int k = 0; k < equations.size(); k++) {
			getIndex(equations[k].first);
			getIndex(equations[k].second);
		}
		/* For the second pass, build up the graph */
		vector<double> temp;
		temp.assign(stringToIndex.size(), -1.0);
		grid.assign(stringToIndex.size(), temp);
		for (int k = 0; k < equations.size(); k++) {
			int row = getIndex(equations[k].first);
			int col = getIndex(equations[k].second);
			grid[row][col] = values[k];
			grid[col][row] = 1.0 / values[k];
		}
		for (int k = 0; k < stringToIndex.size(); i++) {
			grid[k][k] = 1.0;
		}
	}

	void dfs(const int source, int curIndex, const int dest, double accuProduct, vector<bool> &visited) {
		visited[curIndex] = true;
		if (visited[dest]) { return; }
		if (grid[curIndex][dest] > 0.0) {
			grid[source][dest] = accuProduct * grid[curIndex][dest];
			visited[dest] = true;
			return;
		}
		if (curIndex == dest) {
			grid[source][dest] = accuProduct;
			visited[dest] = true;
			return;
		}
		grid[source][curIndex] = accuProduct;
		for (int i = 0; i < stringToIndex.size(); i++) {
			if (grid[curIndex][i] > 0.0 && !visited[i]) {
				dfs(source, i, dest, accuProduct * grid[curIndex][i], visited);
			}
		}
	}

public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        init(equations, values);
		vector<double> ans;
		for (int i = 0; i < queries.size(); i++) {
			vector<bool> visited;
			visited.assign(stringToIndex, false);
			int source = getIndex(queries[i].first);
			int dest = getIndex(queries[i].second);
			dfs(source, source, dest, 1.0, visited);
			ans.push_back(grid[source][dest]);
		}
		return ans;
    }
};
