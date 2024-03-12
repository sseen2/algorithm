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

int arr[15];
int outarr[15];
int isused[15];
int n;

void func(int k, int val) {
    if (k == 6) {
        for (int i = 0; i < 6; i++) {
            cout << outarr[i] << " ";
        }
        cout << nl;
    }

    for (int i = val; i < n; i++) {
        if(isused[i]) continue;
        outarr[k] = arr[i];
        isused[i] = 1;
        func(k + 1, i + 1);
        isused[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (1) {
        cin >> n;
        if (n == 0) break;
        fill(arr, arr+15, 0);
        fill(outarr, outarr+15, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        func(0, 0);
        cout << nl;
    }
}