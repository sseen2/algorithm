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

int n, m;
int arr[100'005];
int sum[100'005];

int func(int k) {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + arr[i];
    }
    while(m--) {
        int i, j; cin >> i >> j;
        if (i - 2 < 0) cout << sum[j - 1] << nl;
        else cout << sum[j - 1] - sum[i - 2] << nl;
    }
}