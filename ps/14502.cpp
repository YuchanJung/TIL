#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
int n, m;
int cnt = 0;

void spread(int matrix[][8], int visited[][8], int x, int y){
    int nx, ny;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i]; // 두 줄 이어서 쓰면 쓰레기값 나옴
        // cout << nx << ny << endl;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (visited[nx][ny] == 0 && matrix[nx][ny] == 0) {
            // cout << nx << ny << endl;
            visited[nx][ny] = 1;
            cnt++;
            spread(matrix, visited, nx, ny);
        }
    }
}

int main() {
    int i, j;
    int matrix[8][8] = {0};
    vector<tuple<int, int>> virus;
    vector<int> v;
    vector<int> ind{1, 1, 1};
    vector<vector<int>> combinations;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 2)
                virus.push_back(make_tuple(i, j));
            else if (matrix[i][j] == 0)
                v.push_back(i * m + j + 1);
        }
    }
    for (i = 0; i < v.size() - 3; i++) {
        ind.push_back(0);
    }
    sort(ind.begin(), ind.end());
    do{
        vector<int> tmp;
        for (i = 0; i < ind.size(); i++) {
            if (ind[i] == 1){
                tmp.push_back(v[i]);
            }
        }
        combinations.push_back(tmp);
    }while(next_permutation(ind.begin(), ind.end()));
    // cout << combinations.size() << endl;
    int res = 1e9;
    for (auto item : combinations) {
        vector<tuple<int, int>> new_wall;
        int visited[8][8] = {0};
        cnt = 0;
        for (auto b : item) {
            // cout << b << ' ';
            int x, y;
            if (b % m){
                x = b / m;
                y = b % m - 1;
            }
            else {
                x = b / m - 1;
                y = m - 1;
            }
            // cout << x << y << endl;
            new_wall.push_back(make_tuple(x, y));
        }
        for (auto i : new_wall) {
            matrix[get<0>(i)][get<1>(i)] = 1;
        }
        for (auto i : virus) {
            cnt++;
            visited[get<0>(i)][get<1>(i)] = 1;
            spread(matrix, visited, get<0>(i), get<1>(i));
        }
        for (auto i : new_wall) {
            matrix[get<0>(i)][get<1>(i)] = 0;
        }
        if (res > cnt) {
            // cout << cnt << endl;
            res = cnt; 
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++){
            if (matrix[i][j] == 1) res++;
        }
    }
    cout << n * m - (res + 3) << endl;
}