#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  int y = 0, m = 0, num = 0;
  
  for (int i = 0; i < n; i++) {
    cin >> num;
    y += (num / 30) + 1;
    m += (num / 60) + 1;
  }
  y *= 10; m *= 15;
  (y < m) ? cout << "Y " << y 
  : (m < y) ? cout << "M " << m
  : cout << "Y M " << y;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  solve();
}