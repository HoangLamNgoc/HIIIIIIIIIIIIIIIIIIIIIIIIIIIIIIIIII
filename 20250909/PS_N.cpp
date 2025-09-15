#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main() {
    freopen("PS.INP", "r", stdin);
    freopen("PS.OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long a[n + 1];
    for(int i = 1; i <= n; ++i) cin >> a[i];

    long long mang[n + 1];
    mang[0] = 0;
    for(int i = 1; i <= n; ++i) mang[i] = mang[i - 1] + a[i];

    stack<int> mins;
    mins.push(0);
    long long maxval = 0, l = 1, r = 1;
    for(int i = 1; i <= n; ++i)
        if(mang[i] < mang[mins.top()]) mins.push(i);

    for(int i = n; i >= 1; --i) {
        while(!mins.empty() && mang[i] > mang[mins.top()]) {
            long long x = mins.top();
            long long len = i - x;
            if ( len > maxval) {
                maxval = len;
                l = x + 1;
                r = i;
            }
            mins.pop();
        }
    }
    cout << l << " " << r << endl;
    return 0;
}
