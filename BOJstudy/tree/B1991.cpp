#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int N = 30;
int n;
char lc[N]; // 왼쪽 자식 노드
char rc[N]; // 오른쪽 자식 노드

// 전위 순회
void preorder(char cur) {
    int c = cur - 'A' + 1;
    cout << cur;
    if (lc[c] != 0) preorder(lc[c]);
    if (rc[c] != 0) preorder(rc[c]);
}

// 중위 순회
void inorder(char cur) {
    int c = cur - 'A' + 1;
    if (lc[c] != 0) inorder(lc[c]);
    cout << cur;
    if (rc[c] != 0) inorder(rc[c]);
}

// 후위 순회
void postorder(char cur) {
    int c = cur - 'A' + 1;
    if (lc[c] != 0) postorder(lc[c]);
    if (rc[c] != 0) postorder(rc[c]);
    cout << cur;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char c, l, r; cin >> c >> l >> r;
        if (l != '.') lc[c - 'A' + 1] = l;
        if (r != '.') rc[c - 'A' + 1] = r;
    }

    preorder('A');
    cout << nl;
    inorder('A');
    cout << nl;
    postorder('A');
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}