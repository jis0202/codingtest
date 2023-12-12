#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;
int QS[100001];

int main() {

	int n, m, q_value, value = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> QS[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> q_value;
		if (QS[i] == 0) {
			dq.push_front(q_value);
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> value;
		dq.push_back(value);
	}
	for (int i = 0; i < m; i++) {
		cout << dq.front() << " ";
		dq.pop_front();
	}

	return 0;
}