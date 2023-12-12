#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m = 0;
	map<string, string> info;

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		string site, password;
		cin >> site >> password;
		info[site] = password;
	}

	for (int i = 0; i < m; i++) {
		string find;
		cin >> find;
		cout << info[find] << "\n";
	}

	return 0;
}