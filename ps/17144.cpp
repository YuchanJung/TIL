#include <iostream>
#include <deque>
#include <vector>
#include <tuple>

using namespace std;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
const int order[] = {0, 1, 2, 3};
const int reverse[] = {0, 3, 2, 1};


int main() {
    int i, j;
    int r, c, t;
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
    }
    // debugging
    /*
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    */
    
}