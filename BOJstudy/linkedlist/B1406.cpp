#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int m; cin >> m;
    stack<char> cur;

    while (m-- > 0) {
        char com; cin >> com;
        if (com == 'P') {
            char put; cin >> put;
            s.push_back(put);
        }
        else if (com == 'L') {
            if (!s.empty()) {
                cur.push(s.back());
                s.pop_back();
            }
        }
        else if (com == 'D') {
            if (!cur.empty()) {
                s.push_back(cur.top());
                cur.pop();
            }
        }
        else if (com == 'B') {
            if (!s.empty()) {
                s.pop_back();
            }
        }
    }

    while (!cur.empty()) {
        s.push_back(cur.top());
        cur.pop();
    }

    cout << s;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  solve();
}