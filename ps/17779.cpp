#include <iostream>
#include <algorithm>

using namespace std;
int n;

int cal(int matrix[][21], int x, int y, int d1, int d2) {
    int po[] = {0, 0, 0, 0, 0};
    int visited[21][21] = {0};
    int i, j;
    for (i = 0; i < d1 + 1; i++) {
        po[4] += matrix[x + i][y - i];
        visited[x + i][y - i] = 1;
    }
    for (i = 1; i < d2 + 1; i++) {
        po[4] += matrix[x + i][y + i];
        visited[x + i][y + i] = 1;
    }
    for (i = 1; i < d2 + 1; i++) {
        po[4] += matrix[x + d1 + i][y - d1 + i];
        visited[x + d1 + i][y - d1 + i] = 1;
        for (j = x + d1 + i - 1; visited[j][y - d1 + i] == 0; j--) {
            po[4] += matrix[j][y - d1 + i];
            visited[j][y - d1 + i] = 1;
        }
    }
    for (i = 1; i < d1; i++) {
        po[4] += matrix[x + d2 + i][y + d2 - i];
        visited[x + d2 + i][y + d2 - i] = 1;
        for (j = x + d2 + i - 1; visited[j][y + d2 - i] == 0; j--) {
            po[4] += matrix[j][y + d2 - i];
            visited[j][y + d2 - i] = 1;
        }
    }
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (visited[i][j] == 1)
                continue;
            if (i >= 1 && i < x + d1 && j >= 1 && j <= y)
                po[0] += matrix[i][j];
            else if (i >= 1 && i <= x + d2 && j > y && j <= n)
                po[1] += matrix[i][j];
            else if (i >= x + d1 && i <= n && j >= 1 && j < y - d1 + d2)
                po[2] += matrix[i][j];
            else
                po[3] += matrix[i][j];
        }
    }
    /*
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << visited[i][j];
        }
        cout << endl;
    }
    for (i = 1; i <= 5; i++) {
        cout << po[i];
    }
    cout << "========" << endl;
    */
    return *max_element(po, po + 5) - *min_element(po, po + 5);
}

int main() {
    int i, j, p, q;
    int matrix[21][21] = {0};
    int res = 1e9;
    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }
    for (i = 1; i < n; i++) {
        for (j = 2; j < n; j++) {
            for (p = 1; p < j; p++) {
                for (q = 1; q < n - j + 1; q++) {
                    if (i + p + q <= n) {
                        // cout << i << j << p << q;
                        int tmp = cal(matrix, i, j, p, q);
                        if (res > tmp)
                            res = tmp;
                    }     
                }
            }
        }
    }
    cout << res << endl;
}