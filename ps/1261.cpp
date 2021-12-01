#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int bx[4] = {0, 0, -1, 1};
const int by[4] = {-1, 1, 0, 0};

int bfs(int graph[][100], int visited[][100][2], queue<tuple<int, int>> &q, int n, int m) {
    while (!q.empty()) {
        tuple<int, int> popitem = q.front();
        q.pop();
        int x = get<0>(popitem);
        int y = get<1>(popitem);
        for (int i = 0; i < 4; i++) {
            int nx = x + bx[i];
            int ny = y + by[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < m) {
                if (visited[nx][ny][0] == 0) {
                    visited[nx][ny][0] = 1;
                    if (graph[nx][ny] == 1)
                        visited[nx][ny][1] = visited[x][y][1] + 1;
                    else
                        visited[nx][ny][1] = visited[x][y][1];
                    if (nx == n - 1 && ny == m - 1)
                        return visited[nx][ny][1];
                    q.push(make_tuple(nx, ny));
                }
            }
        }
    }
}

int main() {
    int n, m;
    int i, j;
    int graph[100][100] = {0};
    int visited[100][100][2] = {0};
    queue<tuple<int, int>> q;
    cin >> m >> n;
    for (i = 0; i < n; i++) {
        string a;
        cin >> a;
        for (j = 0; j < a.size(); j++) {
            graph[i][j] = a[j] - '0';
        }
    }
    /*
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << graph[i][j];
        }
        cout << endl;
    }
    */
    q.push(make_tuple(0, 0));
    visited[0][0][0] = 1;
    cout << bfs(graph, visited, q, n, m) << endl;
    return 0;
}
