#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    list<int> l;
    
    for (int i = 1; i <= n; i++) {
        l.push_back(i);
    }
    auto point = l.begin();
    for (int i = 1; i < k; i++) {
      if (point == l.end()) point = l.begin();
      point++;
    }

    cout << "<" << *point << ", ";
    point = l.erase(point);
  
    while (!l.empty()) {
      if (l.size() == 1) {
        cout << *point << ">";
        break;
      }
      for (int i = 1; i < k; i++) {
        if (point == l.end()) point = l.begin();
        point++;
      }
      cout << *point << ", ";
      point = l.erase(point);
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  solve();
}