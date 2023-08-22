#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <cmath>

using namespace std;
void rotate(vector<deque<int>> &v, int visited[], int wnum, int direction) {
    int nd;
    nd = (direction == 1) ? -1 : 1;
    if (wnum + 1 <= 4 && visited[wnum + 1] == 0) {
        if (v[wnum - 1][2] != v[wnum][6]) {
            visited[wnum + 1] = 1;
            rotate(v, visited, wnum + 1, nd);
        }
    }
    if (wnum - 1 >= 1 && visited[wnum - 1] == 0) {
        if (v[wnum - 1][6] != v[wnum - 2][2]) {
            visited[wnum - 1] = 1;
            rotate(v, visited, wnum - 1, nd);
        }
    }
    if (direction == 1) {
        v[wnum - 1].push_front(v[wnum - 1].back());
        v[wnum - 1].pop_back();
    }
    else {
        v[wnum - 1].push_back(v[wnum - 1].front());
        v[wnum - 1].pop_front();
    }
}


int main() {
    int i, j, r;
    int k;
    int wheel_num, direction;
    int res = 0;
    vector<deque<int>> v;
    for (i = 0; i < 4; i++) {
        deque<int> d;
        string a;
        cin >> a;
        for (j = 0; j < 8; j++) {
            d.push_back(a[j] - '0');
        }
        v.push_back(d);
    }
    cin >> k;
    for (i = 0; i < k; i++) {
        int visited[5] = {0};
        cin >> wheel_num >> direction;
        visited[wheel_num] = 1;
        rotate(v, visited, wheel_num, direction);
    }
    for (j = 0; j < 4; j++) {
        if (v[j][0])
            res += (int)pow(2, j);
    }
    cout << res << endl;  
}