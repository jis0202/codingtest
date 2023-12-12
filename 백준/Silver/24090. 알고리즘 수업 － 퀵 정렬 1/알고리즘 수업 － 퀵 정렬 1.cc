#include <iostream>
#include <vector>

using namespace std;

int m = 0;
int cnt = 0;

int partition(vector<int>& A, int p, int r) {
    int x = A[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; ++j) {
        if (A[j] <= x) {
            ++i;
            cnt++;
            if (cnt == m) {
                cout << A[j] << " " << A[i] << endl;
            }
            swap(A[i], A[j]);
        }
    }

    if (i + 1 != r) {
        cnt++;
        if (cnt == m) {
            cout << A[r] << " " << A[i + 1] << endl;
        }
        swap(A[i + 1], A[r]);
    }

    return i + 1;
}

void quick_sort(vector<int>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}

int main() {
    int n;
    cin >> n >> m;

    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    quick_sort(arr, 0, n - 1);

    if (cnt < m) {
        cout << -1 << endl;
    }

    return 0;
}
