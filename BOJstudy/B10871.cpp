#include <bits/stdc++.h>
using namespace std;

int main() {
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