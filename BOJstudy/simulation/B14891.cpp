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

int st[4][8];

void print() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            if (j == 2 || j == 6) cout << " ";
            cout << st[i][j];
            if (j == 2 || j == 6) cout << " ";
        }
        cout << nl;
    }
    cout << nl;
}

// 시계방향, 맨 뒤를 맨 앞으로 옮김
void cw(int idx) {
    int tmp = st[idx][7];
    for (int i = 7; i > 0; i--) {
        st[idx][i] = st[idx][i - 1];
    }
    st[idx][0] = tmp;
}

// 반시계방향, 맨 앞을 맨 뒤로 옮김
void acw(int idx) {
    int tmp = st[idx][0];
    for (int i = 0; i < 7; i++) {
        st[idx][i] = st[idx][i + 1];
    }
    st[idx][7] = tmp;
}


void solve() {
    int num, n; cin >> num;
    int dir[4] = {0, 0, 0, 0};
    cin >> dir[num - 1];
    if (num == 1) {
        if (st[0][2] != st[1][6]) dir[1] = -dir[0];
        if (st[1][2] != st[2][6]) dir[2] = -dir[1];
        if (st[2][2] != st[3][6]) dir[3] = -dir[2];
    }
    else if (num == 2) {
        if (st[1][6] != st[0][2]) dir[0] = -dir[1];
        if (st[1][2] != st[2][6]) dir[2] = -dir[1];
        if (st[2][2] != st[3][6]) dir[3] = -dir[2];
    }
    else if (num == 3) {
        if (st[2][6] != st[1][2]) dir[1] = -dir[2];
        if (st[2][2] != st[3][6]) dir[3] = -dir[2];
        if (st[1][6] != st[0][2]) dir[0] = -dir[1];
    }
    else if (num == 4) {
        if (st[3][6] != st[2][2]) dir[2] = -dir[3];
        if (st[2][6] != st[1][2]) dir[1] = -dir[2];
        if (st[1][6] != st[0][2]) dir[0] = -dir[1];
    }

    for (int i = 0; i < 4; i++) {
        if (dir[i] == 1) {
            cw(i);
        }
        else if (dir[i] == -1) {
            acw(i);
        }
    }
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    for (int i = 0; i < 4; i++) {
        cin >> s;
        for (int j = 0; j < 8; j++) {
            st[i][j] = s[j] - '0';
        }
    }

    int n; cin >> n;
    while(n--)
        solve();

    cout << (st[0][0] + st[1][0] * 2 + st[2][0] * 4 + st[3][0] * 8); 
}