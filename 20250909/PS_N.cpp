#include <iostream>
#include <algorithm>
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

    vector<int> mins;
    mins.push_back(0);
    long long maxval = 0, l = 1, r = 1;
    for(int i = 1; i <= n; ++i)
        if(mang[i] < mang[mins.back()]) mins.push_back(i);

    for(int i = n; i >= 1; --i) {
        while(!mins.empty() && mang[i] > mang[mins.back()]) {
            long long x = mins.back();
            long long len = i - x;
            if ( len > maxval) {
                maxval = len;
                l = x + 1;
                r = i;
            }
            mins.pop_back();
        }
    }
    cout << l << " " << r << endl;
    return 0;
}


// Cach khac 

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("PS.INP", "r", stdin);
    freopen("PS.OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long a[n + 1], mang[n + 1];
    mang[0] = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        mang[i] = mang[i - 1] + a[i];
    }

    int mins[n + 1];
    mins[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (mang[i] > mang[mins[i - 1]]) mins[i] = mins[i - 1];
        else mins[i] = i;
    }

    long long maxval = 0;
    int l = 1, r = 1;

    int i = mins[n], j = n;
    while (i >= 0) {
        while (i < j && mang[j] <= mang[i]) --j;
        if (j - i > maxval) {
            maxval = j - i;
            r = j;
            l = i + 1;
        }
        if (i == 0) break;
        i = mins[i - 1];
    }

    cout << l << " " << r << "\n";
    return 0;
}
