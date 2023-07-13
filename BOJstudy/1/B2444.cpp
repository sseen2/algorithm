#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        for (int j = n - i; j > 0; j--) {
            cout << " ";
        }
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        for (int j = 1; j < i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i - 1; j++) {
            cout << " ";
        }
        for (int j = 0; j <= n - i; j++) {
            cout << "*";
        }
        for (int j = 1; j <= n - i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  solve();
}