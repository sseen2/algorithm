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
int arr[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << nl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (k != 0 && arr[k - 1] > i) continue;
        arr[k] = i;
        func(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}