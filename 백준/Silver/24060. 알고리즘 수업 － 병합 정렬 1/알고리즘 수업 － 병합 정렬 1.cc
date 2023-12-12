#include <iostream>
#include <vector>

using namespace std;

int m = 0;
int cnt = 0;

void merge(vector<int>& A, int p, int q, int r) {
    int i = p;
    int j = q + 1;
    int t = 0;
    vector<int> tmp(r - p + 1);

    while (i <= q && j <= r) {
        if (A[i] <= A[j]) {
            tmp[t++] = A[i++];
        }
        else {
            tmp[t++] = A[j++];
        }
    }

    while (i <= q) {
        tmp[t++] = A[i++];
    }

    while (j <= r) {
        tmp[t++] = A[j++];
    }

    i = p;
    t = 0;

    while (i <= r) {
        cnt++;
        if (cnt == m) {
            cout << tmp[t] << endl;
        }
        A[i++] = tmp[t++];
    }
}

void merge_sort(vector<int>& A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main() {
    int n;
    cin >> n >> m;

    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    merge_sort(arr, 0, n - 1);
    
    if (cnt < m) {
        cout << -1 << endl;
    }

    return 0;
}
