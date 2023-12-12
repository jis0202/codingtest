#include <iostream>
#include <vector>

using namespace std;

int m = 0;
int cnt = 0;

void heapify(vector<int>& A, int k, int n) {
    int left = 2 * k;
    int right = 2 * k + 1;
    int smaller;

    if (right <= n) {
        if (A[left] < A[right]) {
            smaller = left;
        }
        else {
            smaller = right;
        }
    }
    else if (left <= n) {
        smaller = left;
    }
    else {
        return;
    }

    if (A[smaller] < A[k]) {
        cnt++;
        if (cnt == m) {
            cout << A[smaller] << " " << A[k] << endl;
        }
        swap(A[k], A[smaller]);
        heapify(A, smaller, n);
    }
}

void build_min_heap(vector<int>& A, int n) {
    for (int i = n / 2; i >= 1; --i) {
        heapify(A, i, n);
    }
}

void heap_sort(vector<int>& A, int n) {
    build_min_heap(A, n);

    for (int i = n; i >= 2; --i) {
        cnt++;
        if (cnt == m) {
            cout << A[1] << " " << A[i] << endl;
        }
        swap(A[1], A[i]);
        heapify(A, 1, i - 1);
    }
}

int main() {
    int n;
    cin >> n >> m;

    vector<int> arr(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    heap_sort(arr, n);

    if (cnt < m) {
        cout << -1 << endl;
    }

    return 0;
}
