#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main() {
    int n; 
    cin >> n; 

    long long start = 1; 
    long long end = 10;
    while (n--) {
        start *= 10;
        end *= 10; 
    }

    long long end1 = end, start1 = start;
    long long dem = 0; 
    while (start < end) {
        int mid = (start + end ) / 2; 
        string s = to_string(mid); 
        if ( s.length() > n * 2 ) end = mid; 
        else if (s.length() < n * 2 ) start = mid;
        else {dem = mid; break; }
    }

    vector<long long> v; 
    for (int i = dem ; i < end1; ++i) {
        long long y = i * i; 
        long long j = y % start1;
        y /= start1; 
        if ( y + j == n ) v.push_back(i);
    }

    for (long long& i : v ) cout << i << " "; 
    return 0; 
}
