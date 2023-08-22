#include <iostream>
#include <algorithm>

using namespace std;
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

int process(int matrix[][4][2], int loc[][2], int sx, int sy) {
    int i;
    int res, res_tmp, sdi;
    res = res_tmp = matrix[sx][sy][0];
    sdi = matrix[sx][sy][1];
    matrix[sx][sy][0] = -1;
    loc[res][0] = loc[res][1] = -1;
    for (int l = 1; l < 17; l++) {
        if (loc[l][0] == -1)
            continue;
        int x, y, nx, ny, di;
        x = loc[l][0];
        y = loc[l][1];
        di = matrix[x][y][1];
        nx = x + dx[di];
        ny = y + dy[di];
        bool flag = true;
        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || matrix[nx][ny][0] == -1) {
            flag = false;
            for (i = 0; i < 7; i++) {
                di = (di + 1) % 8;
                nx = x + dx[di];
                ny = y + dy[di];
                if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && matrix[nx][ny][0] != -1) {
                    flag = true;
                    break;
                }
            } 
        }
        if (flag) {
            int tmp_n = matrix[nx][ny][0];
            int tmp_d = matrix[nx][ny][1];
            matrix[nx][ny][0] = matrix[x][y][0];
            matrix[nx][ny][1] = di;
            matrix[x][y][0] = tmp_n;
            matrix[x][y][1] = tmp_d;
            
            loc[matrix[nx][ny][0]][0] = nx;
            loc[matrix[nx][ny][0]][1] = ny;
            loc[matrix[x][y][0]][0] = x;
            loc[matrix[x][y][0]][1] = y;
        }
    }
    int nsx, nsy;
    int matrix_cp[4][4][2];
    int loc_cp[17][2];
    nsx = sx + dx[sdi];
    nsy = sy + dy[sdi];
    while (true) {
        if (nsx < 0 || nsx >= 4 || nsy < 0 || nsy >= 4)
            break;
        if (matrix[nsx][nsy][0] <= 0) {
            nsx = nsx + dx[sdi];
            nsy = nsy + dy[sdi];
            continue;
        }
        copy(&matrix[0][0][0], &matrix[0][0][0] + 32, &matrix_cp[0][0][0]);
        copy(&loc[0][0], &loc[0][0] + 34, &loc_cp[0][0]);
        matrix_cp[sx][sy][0] = 0;
        res = max(res, res_tmp + process(matrix_cp, loc_cp, nsx, nsy));
        nsx = nsx + dx[sdi];
        nsy = nsy + dy[sdi];
    }
    return res;
}


int main() {
    int i, j;
    int matrix[4][4][2] = {0};
    int loc[17][2] = {0};
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            cin >> matrix[i][j][0] >> matrix[i][j][1]; // num, direction
            matrix[i][j][1] -= 1;
            loc[matrix[i][j][0]][0] = i;
            loc[matrix[i][j][0]][1] = j;
        }
    }
    cout << process(matrix, loc, 0, 0) << endl;
}