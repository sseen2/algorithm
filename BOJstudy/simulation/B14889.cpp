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

int n, mn = INT_MAX;
int board[25][25];
int arr[25];

int total(vector<int> m) {
    int sum = 0;
    for (int i = 0; i < n / 2; i++) {
        for (int j = i + 1; j < n / 2; j++) {
            sum += ( board[m[i]][m[j]] + board[m[j]][m[i]]);
        }
    }
    return sum;
}

void solve() {
    for (int i = n / 2; i < n; i++) arr[i] = 1;

    do {
        vector<int> s; vector<int> l;
        for (int i = 0; i < n; i++) {
            if (arr[i]) s.push_back(i);
            else l.push_back(i);
        }
        
        int sumS = total(s), sumL = total(l);

        mn = min(mn, abs(sumS - sumL));
    } while (next_permutation(arr, arr + n));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    solve();

    cout << mn;
}