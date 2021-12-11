#include <iostream>
#include <deque>
#include <vector>
#include <tuple>

using namespace std;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
int r, c, t;

void clean(int matrix[][50], deque<tuple<int, int, int>> &deq, int x, int y, int m1, int m2) {
    int nx, ny;
    nx = ny = -1;
    if ((y == 0 && x > 0 && x < m1) || (y == c - 1 && x > m2 && x <= r - 1)) {
        nx = x - 1;
        ny = y;
    }
    else if ((x == 0 || x == r - 1) && y < c - 1) {
        nx = x;
        ny = y + 1;
    }
    else if ((x == m1 || x == m2) && y > 1) {
        nx = x;
        ny = y - 1;
    }
    else if ((y == 0 && x > m2 && x < r -1) || (y == c - 1 && x >= 0 && x < m1)) {
        nx = x + 1;
        ny = y;
    }
    // cout << nx << ny << endl;
    if (nx != -1) {
        matrix[x][y] = matrix[nx][ny];
        matrix[nx][ny] = 0;
        clean(matrix, deq, nx, ny, m1, m2);
    }
}


int main() {
    int i, j;
    int matrix[50][50] = {0};
    vector<int> machine;
    deque<tuple<int, int, int>> deq;
    cin >> r >> c >> t;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == -1)
                machine.push_back(i);
            else if (matrix[i][j] > 4)
                deq.push_back(make_tuple(i, j, matrix[i][j]));
        }
    }
    for (int time = 0; time < t; time++) {
        while (!deq.empty()) {
            tuple<int, int, int> p = deq.front();
            deq.pop_front();
            int x = get<0>(p);
            int y = get<1>(p);
            int m = get<2>(p);
            for (i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                    continue;
                if (matrix[nx][ny] == -1)
                    continue;
                matrix[nx][ny] += m / 5;
                matrix[x][y] -= m / 5;
            }
        }
        clean(matrix, deq, machine[0] - 1, 0, machine[0], machine[1]);
        clean(matrix, deq, machine[1] + 1, 0, machine[0], machine[1]);
        // debugging
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (matrix[i][j] > 4) {
                    deq.push_back(make_tuple(i, j, matrix[i][j]));
                }
            }
        }
        /*
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
        */
    }
    int res = 0;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            res += matrix[i][j];
        }
    }
    cout << res + 2 << endl;
}