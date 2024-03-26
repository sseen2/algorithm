#include <bits/stdc++.h>
using namespace std;

void solve() {
    int num;
    cin >> num;

    if (num >= 90) {
        cout << "A";
    }
    else if (num < 90 && num >= 80) {
        cout << "B";
    }
    else if (num < 80 && num >= 70) {
        cout << "C";
    }
    else if (num < 70 && num >= 60) {
        cout << "D";
    }
    else {
        cout << "F";
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  solve();
}