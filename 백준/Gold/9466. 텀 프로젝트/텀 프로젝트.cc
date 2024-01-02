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

int arr[100005];
int n;
int state[100005];

void run(int x) {
    int cur = x;
    while (1) {
        state[cur] = x;
        cur = arr[cur];
        if (state[cur] == x) {
            while (state[cur] != -1) {
                state[cur] = -1;
                cur = arr[cur];
            }
            return; 
        }
        else if (state[cur] != 0) return;
    }
}

void solve() {
    cin >> n;
    fill(state + 1, state + n + 1, 0);
    for (int i = 1; i <= n; i++) 
        cin >> arr[i];
    for (int i = 1; i <= n; i++) 
        if (state[i] == 0) run(i);
    int cnt = 0;
    for (int i = 1; i <= n; i++) 
        if (state[i] != -1) cnt++;
    cout << cnt << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}