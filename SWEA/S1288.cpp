#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define ll long long
#define X first
#define Y second

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';

void solve() {
    int n, x = 1; cin >> n;
    vector<bool> a(10);
    bool flag = false;

    while (!flag) {
        flag = true;
        int num = n * x;
        
        while(num > 0) {
            int b = num % 10;
            if(!a[b]) a[b] = true;
            num = num / 10;
        }
        
        for (int i = 0; i < 10; i++) if (!a[i]) flag = false;
        if (flag) break;
        x++;
    }

    cout << x * n << nl;
}   

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "#" << i << " ";
        solve();
    }
}

