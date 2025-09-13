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

    long long a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];

    long long mang[n + 1];
    mang[0] = 0;
    for(int i = 0; i < n; ++i) mang[i + 1] = mang[i] + a[i];

    stack<int> mins;
    mins.push(0);
    long long maxval = 0, l = 0, r = 0;
    for(int i = 1; i <= n; ++i)
        if(mang[i] < mang[mins.top()]) mins.push(i);

    for(int i = n; i >= 0; --i) {
        while(!mins.empty() && mang[i] > mang[mins.top()] && mins.top() < i) {
            int x = mins.top();
            int len = i - x + 1;
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
