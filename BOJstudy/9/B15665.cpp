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
int inp[10];
bool uniq[10][10005];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << nl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!uniq[k][inp[i]]) {
            arr[k] = inp[i];
            uniq[k][inp[i]] = 1;
            func(k + 1);
        }
    }

    for (int i = 0; i < n; i++) uniq[k][inp[i]] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0;  i < n; i++) cin >> inp[i];
    sort(inp, inp + n);
    func(0);
}