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

int n, w, l, idx = 1, seconds = 1;
int truck[1005];
int bridge[105];

void print() {
    for (int i = 0; i < w; i++) {
        cout << bridge[i] << " ";
    }
    cout << nl;
}

bool isend() {
    for (int i = 0; i < w; i++) {
        if (bridge[i] != 0) return false;
    }
    return true;
}

int totalW() {
    int sum = 0;
    for (int i = 0; i < w; i++) {
        sum += bridge[i];
    }
    return sum;
}

void move() {
    for (int i = w - 1; i > 0; i--) {
        bridge[i] = bridge[i - 1];
    }
    bridge[0] = 0;
}

void solve() {
    cin >> n >> w >> l;
    for (int i = 0; i < n; i++) {
        cin >> truck[i];
    }

    bridge[0] = truck[0];
    while (!isend()) {
        move();
        if (idx < n && totalW() + truck[idx] <= l) {
            bridge[0] = truck[idx++];
        }
        seconds++;
        // print();
    }

    cout << seconds;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}