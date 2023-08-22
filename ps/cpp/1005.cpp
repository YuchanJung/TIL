#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 1001
using namespace std;
int n, m, w, t;
int degree[MAX], cost[MAX], memo[MAX];
vector<int> v[MAX];
// int res[MAX]

void topology_sort() {
    int i;
    queue<int> q;
    for (i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            memo[i] = cost[i];
            q.push(i);
        }
    }
    for (i = 1; i <= n; i++) {
        int popitem = q.front();
        q.pop();
        // res[i] = popitem;
        for (auto item : v[popitem]) {
            int tmp = memo[popitem] + cost[item];
            if (tmp > memo[item]) memo[item] = tmp;
            if(--degree[item] == 0) q.push(item);   
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int i;
    cin >> t;
    for (int _t = 0; _t < t; _t++) {
        cin >> n >> m;
        for (i = 1; i <= n; i++) {
            cin >> cost[i];
            degree[i] = memo[i] = 0;
            v[i].clear();
        }
        for (i = 0; i < m; i ++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            degree[b]++;
        }
        cin >> w;
        topology_sort();
        cout << memo[w] << endl;
    }
}