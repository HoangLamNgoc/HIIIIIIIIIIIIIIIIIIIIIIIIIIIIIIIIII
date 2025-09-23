#include <iostream>
#include <map>
#include <vector>

using namespace std;
const int maxN = 1e6 + 5;
int d[maxN];

void sieve() {
    fill_n(d, maxN, 0);

    for(int i = 2; i * i <= maxN; ++i) {
        if (d[i] == 0 ) {
            for (int j = i * i; j <= maxN; j += i) {
                d[j] = i;
            }
        }
    }
}

void isPrime(long long j, map<int, int>& freq) {
    while( d[j] != 0) {
        freq[d[j]]++;
        j /= d[j];
    }
    if ( j > 1 ) freq[j]++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("FRACTION.INP", "r", stdin);
    freopen("FRACTION.OUT", "w", stdout);
    int T; cin >> T;
    sieve();

    while(T--) {
        int n;
        cin >> n;
        map<int, int> a, b;

        for(int i = 1; i <= n; ++i){
            long long j; cin >> j;
            isPrime(j, a);
        }

        for(int i = 1; i <= n; ++i) {
            long long j; cin >> j;
            isPrime(j, b);
        }
        bool found = true;

        for (auto it = b.begin(); it != b.end(); ++it) {
            if (it->first == 2 || it->first == 5 ) continue;
            int dem = it->second;
            int cnt = a[it->first];
            if ( dem > cnt ) found = false;
        }

        if(found) cout << "finite" << endl;
        else cout << "repeating" << endl;
    }
    return 0;
}
