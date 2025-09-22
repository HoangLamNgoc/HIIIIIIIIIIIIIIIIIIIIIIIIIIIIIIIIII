#include <iostream>
#include <algorithm>

using namespace std;
const int maxN = 1e6;
int main() {
    freopen("BUNNY.INP", "r", stdin);
    freopen("BUNNY.OUT", "w", stdout);

    long long n;
    cin >> n;

    long long k = n % 6;
    n /= 6;
    long long ans;
    if ( k == 0 ) ans = 1 + (n % maxN) * (( n + 1) % maxN) * 3 + (n % maxN) * k;
    else ans = k + (n % maxN) * (( n + 1) % maxN) * 3 + (n % maxN) * k;
    cout << ans % maxN;
    return 0;
}
