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
const int N = 10005;
const int M = 105;

int n, m, cnt = 0;
int arr[M][N];
vector<vi> uni(M, vector<int>());

void print() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << nl;
    }
}

void solve() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            uni[i].push_back(arr[i][j]);
        }
        sort(uni[i].begin(), uni[i].end());
        uni[i].erase(unique(uni[i].begin(), uni[i].end()), uni[i].end());
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = lower_bound(uni[i].begin(), uni[i].end(), arr[i][j]) - uni[i].begin();
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (equal(arr[i], arr[i] + n, arr[j])) cnt++;
        }
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}