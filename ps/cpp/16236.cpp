#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
const int inf = 1e9;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

tuple<int, int, int> bfs(int graph[][20], int visited[][20], queue<tuple<int, int, int>> &q, int baby_size, int n) {
    while (!q.empty()) {
        tuple<int, int, int> popitem = q.front();
        q.pop();
        int x = get<0>(popitem);
        int y = get<1>(popitem);
        int dis = get<2>(popitem);
        if (graph[x][y] > 0 && graph[x][y] < baby_size) {
            while (!q.empty()) {
                tuple<int, int, int> tmp = q.front();
                q.pop();
                int tmp_x = get<0>(tmp);
                int tmp_y = get<1>(tmp);
                int tmp_dis = get<2>(tmp);
                if (dis != tmp_dis)
                    return make_tuple(x, y, dis);
                if (graph[tmp_x][tmp_y] > 0 && graph[tmp_x][tmp_y] < baby_size) {
                    if (tmp_x < x) {
                        x = tmp_x;
                        y = tmp_y;
                    }
                    else if (tmp_x == x && tmp_y < y) {
                        x = tmp_x;
                        y = tmp_y;
                    }
                }
            }
            return make_tuple(x, y, dis);
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (graph[nx][ny] <= baby_size && visited[nx][ny] == 0) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push(make_tuple(nx, ny, visited[nx][ny]));
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
    int eat_x, eat_y;
    int distance;
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
        eat_x = eat_y = -1;
        queue<tuple<int, int, int>> q;
        q.push(make_tuple(baby_x, baby_y, 0));
        visited[baby_x][baby_y] = 1;
        tuple<int, int, int> eat_info = bfs(graph, visited, q, baby_size, n);
        eat_x = get<0>(eat_info);
        eat_y = get<1>(eat_info);
        distance = get<2>(eat_info);
        if (eat_x == -1)
            break;
        // cout << eat_x << eat_y << distance << endl;
        graph[baby_x][baby_y] = 0;
        graph[eat_x][eat_y] = 0;
        baby_x = eat_x;
        baby_y = eat_y;
        eat_count++;
        time += distance - 1;
        if (eat_count == baby_size && baby_size < 7) {
            baby_size += 1;
            eat_count = 0;
        }
    }
    cout << time << endl;
}