#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long m; 
    cin >> n >> m;  

    long long pre[m + 1]; 
    pre[0] = 0; 
    long long a[m + 1]; 
    for (long long i = 1; i <= m; ++i) {
        cin >> a[i]; 
    }
    sort(a, a + m + 1);
    for (long long i = 1; i <= m; ++i) pre[i] = pre[i - 1] + a[i]; 

    long long dem = 0;
    long long i = 1, j = m;
    while (i <= j) { 
        long long mid = a[(i + j) / 2];
        

