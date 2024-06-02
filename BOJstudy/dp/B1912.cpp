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
const int N = 100005;

int n, mx = -10000;
int arr[N];
int sum[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sum[0] = arr[0];
    for (int i = 0; i < n; i++) sum[i] = max(arr[i], sum[i - 1] + arr[i]);
    cout << *max_element(sum, sum + n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}