#include <iostream>
#include <deque>
#include <vector>
#include <tuple>

using namespace std;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

void dc(int matrix[][101], int x, int y, int d, int g, deque<tuple<int, int>> &deq) {
    // 0
    int i, j;
    int t_matrix[101][101] = {0};
    int nx = x + dx[d], ny = y + dy[d];
    t_matrix[x][y] = matrix[x][y] = 1;
    t_matrix[nx][ny] = matrix[nx][ny] = 1;
    // 1 ~ g
    for (i = 1; i <= g; i++) {
        vector<tuple<int, int>> c;
        int visited[101][101] = {0};
        visited[nx][ny] = 1;
        deq.push_back(make_tuple(nx, ny));
        while (!deq.empty()) {
            tuple<int, int> popitem = deq.front();
            deq.pop_front();
            int _x = get<0>(popitem);
            int _y = get<1>(popitem);
            for (j = 0; j < 4; j++) {
                int _nx = _x + dx[j], _ny = _y + dy[j];
                if (_nx < 0 || _nx > 100 || _ny < 0 || _ny > 100)
                    continue;
                if (t_matrix[_nx][_ny] == 1 && visited[_nx][_ny] == 0) {
                    visited[_nx][_ny] = 1;
                    c.push_back(make_tuple(nx - (ny - _ny), ny + (nx - _nx)));
                    deq.push_back(make_tuple(_nx, _ny));
                }
            }
        }
        for (auto item : c) {
            int __x = get<0>(item), __y = get<1>(item);
            t_matrix[__x][__y] = 1;
            matrix[__x][__y] = 1;
        }
        // nx, ny = nx - (ny - y), ny + (nx - x);
        int tmp = nx;
        nx -= (ny - y);
        ny += (tmp - x);
    }
}

int main() {
    int n, i, j, k;
    int matrix[101][101] = {0};
    cin >> n;
    for (i = 0; i < n; i++) {
        int x, y, d, g;
        deque<tuple<int, int>> deq;
        cin >> x >> y >> d >> g;
        dc(matrix, y, x, d, g, deq);
    }
    int res = 0;
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            if (matrix[i][j] && matrix[i][j + 1] && matrix[i + 1][j] && matrix[i + 1][j + 1])
                res++;
        }
    }
    cout << res << endl;
}