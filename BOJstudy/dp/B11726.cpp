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

int n;
ll arr[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    arr[1] = 1; arr[2] = 2;
    for (int i = 3; i <= n; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
    }
    cout << arr[n];
}