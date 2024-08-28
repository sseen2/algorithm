#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

void solve() {
    int n; cin >> n;
    int size = n * n;
    // 배열 풀이
    // int a[size];
    // for (int i = 0; i < size; i++) cin >> a[i];
    // sort(a, a + size);
    // cout << a[size - n];
    
    // 우선순위 큐 풀이
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < size; i++) {
        int a; cin >> a;
        pq.push(a);
        if (pq.size() > n) pq.pop();
    }

    cout << pq.top();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}