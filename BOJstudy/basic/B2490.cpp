#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t = 0;

    while (t++ < 3) {
        int count = 0;
        int y;
        for (int i = 0; i < 4; i++) {
            cin >> y;
            if (y == 0) count++;
        }

        switch (count)
        {
        case 1: // 배 1 >> 도
            cout << 'A' << '\n';
            break;
        case 2: // 배 2 >> 개
            cout << 'B' << '\n';
            break;
        case 3: // 배 3 >> 걸
            cout << 'C' << '\n';
            break;
        case 4: // 배 4 >> 윷
            cout << 'D' << '\n';
            break;
        default: // 배 0 >> 모
            cout << 'E' << '\n';
            break;
        }
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  solve();
}