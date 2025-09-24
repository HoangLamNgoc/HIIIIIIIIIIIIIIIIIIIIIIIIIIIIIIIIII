#include <iostream>
#include <vector>

using namespace std; 
const int maxN = 1e6;
int d[maxN + 5];

void sieve() { 
    for( int a = 2; a * a <= maxN; ++a) {
        if(d[a] == 0) {
            for(int b = a * a; b <= maxN; b += a) {
               d[b] = a;
            }
        }
    }
}

void ham( map<long long, int> a; int n) {
    while (d[n] != 0) {
        a[d[n]]++;
        n /= d[n];
    }
    if ( n > 1) a[n]++;
}

int main() {
    int n; 
    cin >> n; 
    map<long long, int> a;
    fill_n(d, maxN + 5, 0);
    sieve();
    const long long MOD = 1e7 + 9;

    for ( int i = 0; i < n; ++i) 
        ham(i);

    for(auto it = a.begin(); it != a.end(); ++it) {
        if (it->second) *it--;
        while ( it->second--) {
            dem *= it->first;
            dem %= MOD;
        }
    }
    cout << dem << endl;
    return 0;
}

