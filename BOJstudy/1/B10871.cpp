#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num < x)
            cout << num << " ";
    }
    
    return 0;
}