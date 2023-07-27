#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    while (n-- > 0) {
        string s; cin >> s;
        stack<char> cur;
        list<char> pw;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '<') {
                if (!pw.empty()) {
                    cur.push(pw.back());
                    pw.pop_back();
                }
            }
            else if (s[i] == '>') {
                if (!cur.empty()) {
                    pw.push_back(cur.top());
                    cur.pop();
                }
            }
            else if (s[i] == '-') {
                if (!pw.empty()) pw.pop_back();
            }
            else pw.push_back(s[i]);
        }
        while (!cur.empty()) {
            pw.push_back(cur.top());
            cur.pop();
        }

        for (auto it = pw.begin(); it != pw.end(); it++) {
            cout << *it;
        }
        cout << "\n";
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  solve();
}