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
const int N = 100'005;

int n, mn = INT_MAX;
int arr[N];
int result[2];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        int idx = (lower_bound(arr, arr + n, -arr[i]) - arr);
        if (idx == n) idx--;
        if (i != idx && mn > abs(arr[i] + arr[idx])) {
            mn = abs(arr[i] + arr[idx]);
            result[0] = arr[i];
            result[1] = arr[idx];
        }

        if (idx != 0 && i != idx - 1 && mn > abs(arr[i] + arr[idx - 1])) {
            mn = abs(arr[i] + arr[idx - 1]);
            result[0] = arr[i];
            result[1] = arr[idx - 1];
        }
    }

    sort(result, result + 2);
    cout << result[0] << " " << result[1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}