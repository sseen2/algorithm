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
const int N = 500'005;

int n, m;
int a[N], b[N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(b, b + m);

    vi v;
    for (int i = 0; i < n; i++) 
        if (!binary_search(b, b + m, a[i])) v.push_back(a[i]);
    
    
    cout << v.size() << nl;
    if (v.size() != 0) {
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}