#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, i;
    int res = 1;
    cin >> n;
    int arr[1000000];
    vector<int> record;
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    record.push_back(arr[0]);
    for (i = 1 ; i < n; i++) {
        if (arr[i] > record.back()) {
            record.push_back(arr[i]);
        }
        else {
            int start = 0;
            int end = record.size() - 1;
            while (start < end) {
                int mid = (start + end) / 2;
                if (arr[i] > record[mid]) {
                    start = mid + 1;
                }
                else {
                    end = mid;
                }
            }
            record[end] = arr[i];
        }
    }
    cout << record.size() << endl;
}