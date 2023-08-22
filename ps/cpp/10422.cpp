#include <iostream>
using namespace std;
const int mod = 1000000007;

int main() {
    int t, l, i, j;
    long long memo[5001][2] = {{0, 0}};
    memo[2][0] = 1;
    memo[2][1] = 0;
    for (i = 4; i <= 5000; i++) {
        if (i % 2 == 1)
            continue;
        memo[i][0] += (memo[i - 2][0] + memo[i - 2][1]); // S -> (S)
        memo[i][0] %= mod;
        for (j = i - 2; j > 0; j -= 2) {
            memo[i][1] += ((memo[j][0] + memo[j][1]) * memo[i - j][0]);
            memo[i][1] %= mod;
        }
    }
    cin >> t;
    for (i = 0; i < t; i++) {
        long long res = 0;
        cin >> l;
        res += (memo[l][0] + memo[l][1]);
        cout << res % mod << endl;
    }
}