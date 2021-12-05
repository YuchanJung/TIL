#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> record, int value) {
    int start = 0;
    int end = record.size() - 1;
    while (start < end) {
        int mid = (start + end) / 2;
        if (value > record[mid]) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }
    return end;
}

int main() {
    int n, i;
    int res = 1;
    cin >> n;
    int arr[1000000];
    vector<int> record;
    // vector<int> length;
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    record.push_back(arr[0]);
    // length.push_back(1);
    for (i = 1 ; i < n; i++) {
        if (arr[i] > record.back()) {
            record.push_back(arr[i]);
            /*
            length.push_back(record.size());
            if (res < length.back()) {
                res = length.back();
            }
            */
        }
        else {
            int idx = binary_search(record, arr[i]);
            record[idx] = arr[i];
            // length.push_back(idx + 1);
        }
    }
    /*
    for (i = 0; i < record.size(); i++) {
        cout << record[i];
    }
    cout << endl;
    for (i = 0; i < n; i++) {
        cout << length[i];
    }
    */
    cout << record.size() << endl;
}