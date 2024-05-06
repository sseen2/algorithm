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

int n, c;
int arr[1005];
int outarr[1005];

bool cmp (int a, int b) {
    int acnt = 0, bcnt = 0, aidx = n, bidx = n;
    for (int i = 0; i < n; i++) {
        if (arr[i] == a) { acnt++; aidx = min(aidx, i); }
        if (arr[i] == b) { bcnt++; bidx = min(bidx, i); }
    }
    // cout << a << " " << aidx << " " << b << " " << bidx << nl;
    if (acnt != bcnt) return acnt > bcnt;
    else if (aidx != bidx) return aidx < bidx;
    else return false;
}

void solve() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) outarr[i] = arr[i];
    
    sort(outarr, outarr + n, cmp);
    for (int i = 0; i < n ; i++) cout << outarr[i] << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}