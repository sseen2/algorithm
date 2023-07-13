#include <bits/stdc++.h>
using namespace std;

void print(long a, long b) {
    cout << b - a - 1 << '\n';
    for (long i = a + 1; i < b; i++)
        cout << i << ' ';
}

void solve() {
    long a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0;
        return;
    }
    (b > a) ? print(a, b) : print(b, a);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  solve();
}