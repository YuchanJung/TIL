#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001
using namespace std;
int n, m;
int res[MAX], degree[MAX];
vector<int> vorder[MAX];

void topology_sort() {
    int i;
    queue<int> q;
    for (i = 1; i <= n; i++) {
        if (degree[i] == 0) q.push(i);
    }
    for (i = 1; i <= n; i++) {
        int popitem = q.front();
        q.pop();
        res[i] = popitem;
        for (auto item : vorder[popitem]) {
            if(--degree[item] == 0) q.push(item);
        }
    }
    for (i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
}




int main() {
    int i, j;
    cin >> n >> m;
    for (i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        vorder[a].push_back(b);
        degree[b]++;
    }
    topology_sort();
}