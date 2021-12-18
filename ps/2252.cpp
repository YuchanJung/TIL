#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int findIndex(const vector<int> &res, int item) {
    auto ret = std::find(res.begin(), res.end(), item);
    if (ret != res.end())
        return ret - res.begin();
    return -1;
}

int dfs(vector<int> &res, vector<vector<int>> &data, int visited[32001], int sn) {
    if (visited[sn] == 1)
        return findIndex(res, sn);
    int idx = 1e9;
    for (int i = 1; i < data[sn].size(); i++) {
        int snext = data[sn][i];
        idx = min(idx, dfs(res, data, visited, snext));
    }
    visited[sn] = 1;
    if (idx == 1e9) {
        res.push_back(sn);
        return res.size() - 1;
    }
    else {
        res.insert(res.begin() + idx, sn);
        return idx;
    }
}
void vPrint(vector<vector<int>> &data) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < data[i].size(); j++) {
            cout << data[i][j];
        }
        cout << endl;
    }
}

int main() {
    int i, j;
    cin >> n >> m;
    vector<vector<int>> data;
    vector<int> res;
    int visited[32001] = {0};
    /*
    vector<int> t = {1, 2, 3};
    t.insert(t.begin() + 1, 5);
    for (auto i : t) {
        cout << i;
    }
    cout << endl;
    */
    for (i = 0; i <= n; i++) { // n + 1 for indexing
        vector<int> v = {-1};
        data.push_back(v);
    }
    for (i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        data[a].push_back(b);
    }
    for (i = 1; i <= n; i++) {
        dfs(res, data, visited, i);
    }
    for (i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
}