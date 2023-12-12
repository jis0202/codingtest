#include <iostream>

using namespace std;

int cnum, e, c = 0;
bool num[101] = { false };
int chain[101][101] = { 0 };

void dfs(int n) {
    c++;
    num[n] = true;
    for (int i = 1; i <= cnum; i++) {
        if (chain[n][i] && !num[i])
            dfs(i);
    }
}

int main() {
    int x, y;

	cin >> cnum >> e;

    for (int i = 0; i < e; i++) {
        cin >> x >> y;
        chain[x][y] = chain[y][x] = 1;
    }

    dfs(1);
    cout << (c - 1) << endl;
}
