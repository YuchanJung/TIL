#include <iostream>
#include <algorithm>
using namespace std;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
const int inf = 99999;
int n, m;

void dfs(int graph[][100], int visited[][100], int memo[][100], int x, int y) {
    int i;
    for (i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (graph[nx][ny] == 0 && visited[nx][ny] == 0) {
            visited[nx][ny] = visited[x][y];
            if (memo[nx][ny] <= visited[nx][ny]) {
                cout << x << y << nx << ny << 'x' << endl; 
                continue;
            }
            memo[nx][ny] = visited[nx][ny];
            cout << nx << ny << memo[nx][ny] << endl;
            if (nx == n - 1 && ny == m - 1) {
                visited[nx][ny] = 0;
                return;
            }
            dfs(graph, visited, memo, nx ,ny);
            visited[nx][ny] = 0;
        }
        else if (graph[nx][ny] == 1 && visited[nx][ny] == 0) {
            visited[nx][ny] = visited[x][y] + 1;
            if (memo[nx][ny] <= visited[nx][ny]) {
                cout << nx << ny << "bx" << endl;
                continue;
            }
            memo[nx][ny] = visited[nx][ny];
            cout << nx << ny << memo[nx][ny] << 'b' << endl;
            dfs(graph, visited, memo, nx, ny);
            visited[nx][ny] = 0;
        }
    }
}

int main() {
    int i, j;
    int graph[100][100] = {0};
    int visited[100][100] = {0};
    int memo[100][100] = {0};
    fill(memo[0], memo[100], inf);
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
    visited[0][0] = 1;
    dfs(graph, visited, memo, 0, 0);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << memo[i][j] << ' ';
        }
        cout << endl;
    }
    cout << memo[n - 1][m - 1] << endl;
    return 0;
}
