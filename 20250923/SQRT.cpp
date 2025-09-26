#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
const int maxN = 1e6;
int d[maxN + 5];

void sieve() {
    for (int a = 2; a * a <= maxN; ++a) {
        if (d[a] == 0) {
            for (long long b = a * a; b <= maxN; b += a) {
                if (d[b] == 0) d[b] = a;
            }
        }
    }
}

void ham(vector<long long>& a, int n) {
    while (d[n] != 0) {
        a[d[n]]++;
        n /= d[n];
    }
    if (n > 1) a[n]++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("SQRNUM.INP", "r", stdin);
    freopen("SQRNUM.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<long long> v(maxN + 1, 0);
    fill_n(d, maxN + 5, 0);
    sieve();
    const long long MOD = 1e9 + 7;
    long long dem = 1;

    for (long long i = 1; i <= n; ++i) {
        ham(v, i);
    }

    for (long long i = 2; i <= n; ++i) {
        if(v[i] % 2 == 1) v[i]--;
        while ( v[i] > 0) {
            dem *= i;
            v[i]--;
            dem %= MOD;
        }
    }
    cout << dem << endl;
    return 0;
}
