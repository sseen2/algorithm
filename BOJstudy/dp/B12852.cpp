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
const int N = 1'000'005;

int n;
int dp[N];
int arr[N];

int func(int k) {
    if (k == 1) return 0;
    if (dp[k] != -1) return dp[k];

    int result = func(k - 1) + 1;
    int tmp = result;
    if (k % 3 == 0) {
        int nxt = func(k / 3) + 1;
        if (nxt < result) {
            result = nxt;
            arr[k] = k / 3;
        }
    }
    if (k % 2 == 0) {
        int nxt = func(k / 2) + 1;
        if(nxt < result) {
            result = nxt;
            arr[k] = k / 2;
        }
    }
    if (tmp == result) arr[k] = k - 1;
    dp[k] = result;
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if (n == 1) { 
        cout << 0 << nl << 1;
        return 0;    
    }
    fill(dp, dp + N, -1);

    cout << func(n) << nl;

    cout << n << " ";
    int num = n;
    while (arr[num] != 0) {
        cout << arr[num] << " ";
        num = arr[num];
    }
}