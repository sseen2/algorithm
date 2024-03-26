#include <bits/stdc++.h>
using namespace std;

void solve() {
    int sum = 0;
    int min = 101;
    int num;

    for (int i = 0; i < 7; i++) {
        cin >> num;
        if (num % 2 != 0) {
            sum += num;
            if (min > num)
                min = num;
        }
    }

    if (sum == 0) 
        cout << -1;
    else 
        cout << sum << '\n' << min;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  solve();
}