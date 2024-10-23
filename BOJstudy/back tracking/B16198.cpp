#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n, mx;
vi b;

void func(int e) {
    if (b.size() == 2) { 
        mx = max(mx, e); 
        return; 
    }

    for (int i = 1; i < b.size() - 1; i++) {
        int cur = b[i];
        e += b[i - 1] * b[i + 1];
        b.erase(b.begin() + i);
        func(e);
        b.insert(b.begin() + i, cur);
        e -= b[i - 1] * b[i + 1];
    }
}


void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        b.push_back(a);
    }

    func(0);
    cout << mx;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}