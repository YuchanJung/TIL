#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
const int inf = 1e9;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

tuple<int, int, int> bfs(int graph[][20], int visited[][20], queue<tuple<int, int>> &q, int baby_size, int n) {
    while (!q.empty()) {
        tuple<int, int> popitem = q.front();
        q.pop();
        int x = get<0>(popitem);
        int y = get<1>(popitem);
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (graph[nx][ny] <= baby_size && visited[nx][ny] == 0) {
                    visited[nx][ny] = visited[x][y] + 1;
                    if (graph[nx][ny] > 0 && graph[nx][ny] < baby_size) {
                        while (!q.empty()) {
                            tuple<int, int> tmp = q.front();
                            q.pop();
                            int tmp_x = get<0>(tmp);
                            int tmp_y = get<1>(tmp);
                            if (tmp_x < nx) {
                                nx = tmp_x;
                                ny = tmp_y;
                            }
                            else if (tmp_x == nx && tmp_y < ny) {
                                nx = tmp_x;
                                ny = tmp_y;
                            }
                        }
                        cout << nx << ny << visited[nx][ny] << endl;
                        return make_tuple(nx, ny, visited[nx][ny]);
                    }
                    q.push(make_tuple(nx, ny));
                }
            }
        }
    }
    return make_tuple(-1, -1, -1);
}

int main() {
    int n, i, j;
    int graph[20][20] = {0};
    int baby_size = 2;
    int time = 0;
    int baby_x, baby_y;
    cin >> n;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 9){
                baby_x = i;
                baby_y = j;
            }
        }
    }
    int eat_count = 0;
    while (true) {
        int visited[20][20] = {0};
        int eat_x = -1, eat_y = -1;
        int distance;
        queue<tuple<int, int>> q;
        q.push(make_tuple(baby_x, baby_y));
        visited[baby_x][baby_y] = 1;
        tuple<int, int, int> eat_info = bfs(graph, visited, q, baby_size, n);
        eat_x = get<0>(eat_info);
        eat_y = get<1>(eat_info);
        distance = get<2>(eat_info);
        if (eat_x == -1)
            break;
        graph[baby_x][baby_y] = 0;
        graph[eat_x][eat_y] = 9;
        baby_x = eat_x;
        baby_y = eat_y;
        eat_count++;
        time += distance - 1;
        if (eat_count == baby_size) {
            baby_size += 1;
            eat_count = 0;
        }
    }
    cout << time << endl;
}