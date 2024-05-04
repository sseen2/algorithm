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
queue<int> a;
queue<int> b;
int c[2000005];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int num = 0; cin >> num;
        a.push(num);
    }
    for (int i = 0; i < m; i++) {
        int num = 0; cin >> num;
        b.push(num);
    }

    for (int i = 0; i < n + m; i++) {
        if (a.empty()) {
            c[i] = b.front();
            b.pop();
            continue;
        }
        else if (b.empty()) {
            c[i] = a.front();
            a.pop();
            continue;
        }

        if (!a.empty() && a.front() <= b.front()) {
            c[i] = a.front();
            a.pop();
        }
        else if (!b.empty() && a.front() > b.front()) {
            c[i] = b.front();
            b.pop();
        }
    }

    for (int i = 0; i < n + m; i++) cout << c[i] << " ";
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}