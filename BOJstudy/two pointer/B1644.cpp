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
const int N = 4'000'005;

ll n, en, cnt, sum, l; 
vi a; // 2부터 n까지 소수 저장
vector<bool> state(N, true);  // 에라토스테네스의 체

void printa() {
    for (int i = 0; i < l; i++) cout << a[i] << " ";
    cout << nl;
}

void solve() {
    cin >> n;
    state[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (!state[i]) continue;
        for (ll j = i * i; j <= n; j += i) 
            state[j] = false;
    }
    for (int i = 2; i <= n; i++) if (state[i]) a.push_back(i);
    
    l = a.size();
    for (int st = 0; st < l; st++) {
        while (en < l && sum < n) {
            if (en != l) sum += a[en];
            en++;
        }
        if (sum == n) cnt++;
        sum -= a[st];
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