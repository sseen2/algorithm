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

int n, m, mn = 0x3f3f3f3f, cidx, hidx;
int city[55][55];
int chickenshop[15][2];     // 치킨집 좌표 저장
int house[110][2];           // 집 좌표 저장
int chickendir[15][55][55];
int arr[15];
bool isused[15];

int mdir() {
    int outnum = 0;
    for (int i = 0; i < hidx; i++) {
        int dir = 1100;
        int x = house[i][0], y = house[i][1];
        for (int j = 0; j < m; j++) {
            dir = min(dir, chickendir[arr[j]][x][y]);
        }
        outnum += dir;
    }
    return outnum;
}

void func(int k, int val) {
    if (k == m) {
        int dir = mdir();
        mn = min(dir, mn);
    }

    for (int i = val; i < cidx; i++) {
        if(isused[i]) continue;
        arr[k] = i;
        isused[i] = 1;
        func(k + 1, i + 1);
        isused[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
            if (city[i][j] == 2) {
                chickenshop[cidx][0] = i;
                chickenshop[cidx++][1] = j;
            }
            else if (city[i][j] == 1) {
                house[hidx][0] = i;
                house[hidx++][1] = j;
            }
        }
    }

    // 미리 거리 계산 후 저장
    for (int i = 0; i < cidx; i++) {
        for (int j = 0; j < hidx; j++) {
            int x = house[j][0];
            int y = house[j][1];
            chickendir[i][x][y] = abs(chickenshop[i][0] - x) + abs(chickenshop[i][1] - y);
        }
    }

    func(0, 0);
    cout << mn;
}