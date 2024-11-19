#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

ll n;

bool check(ll mid) {
    return mid * mid >= n;
}

void solve() {
    cin >> n;
    if (n == 0) {
        cout << 0;
        return;
    }
    
    ll st = 0, en = UINT_MAX;
    while(st + 1 < en) {
        ll mid = (st + en + 1) / 2;
        if (check(mid)) en = mid;
        else st = mid;
    }

    cout << en;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}