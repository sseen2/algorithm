#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const char nl = '\n';
const int N = 10005;
int p, n;
vi t;

void func(int st, int en) {
    if (st > en) return; 
    int root = t[st];
    int tmp = -1;
    for (int i = st + 1; i <= en; i++) 
        if (root < t[i]) {
            tmp = i;
            break;
        }

    if (tmp != -1) {
        func(st + 1, tmp - 1);
        func(tmp, en);
    }
    else func(st + 1, en);
    cout << root << nl;
}

void solve() {
    while (cin >> p) t.push_back(p);
    n = t.size();
    func(0, n - 1);
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}