#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
const int D = 35;

int d, k;
int a[D];
int b[D];

int inputA(int n) {
    if (a[n] != -1) return a[n];
    a[n] = inputA(n - 1) + inputA(n - 2);
    return a[n];
}

int inputB(int n) {
    if (b[n] != -1) return b[n];
    b[n] = inputB(n - 1) + inputB(n - 2);
    return b[n];
}

void solve() {
    cin >> d >> k;
    
    fill(a, a + d + 1, -1);
    fill(b, b + d + 1, -1);
    a[1] = 1; a[2] = 0;
    b[1] = 0; b[2] = 1;
    inputA(d);
    inputB(d);

    for (int i = 1; i < k; i++) {
        for (int j = i + 1; j < k; j++)
        if (k - (i * a[d]) == j * b[d]) {
            cout << i << nl << j;
            return;
        }
    }
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}