#include <iostream>
#include <algorithm>


using namespace std;
int n;

long long arrange(long long a[], long long x) {
    long long ans = 0;

    int i = 0;
    int j = n - 1;

    while(i < j) {
        if (a[i] + a[j] <= x ){
            ans += (j - i);
            ++i;
        }
        else --j;
    }
    return ans;
}

int main()
{
    freopen("KTHSUM.INP","r", stdin);
    freopen("KTHSUM.OUT","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int k;
    cin >> k;

    long long a[n];
    for (long long& i : a) cin >> i;
    sort(a, a + n);

    long long lo = a[0] + a[1];
    long long hi = a[n-2] + a[n-1];
    while(hi > lo) {
        int mid = (lo + hi) / 2;
        long long cnt = arrange(a, mid);
        if (cnt >= k)
            hi = mid;
        else
            lo = mid + 1;

    }
    cout << lo << endl;
    return 0;
}


/* idea cua KTHSUM
de 1 so la tong thu K cua day -> co k - 1 phan tu < val (so can tim) va co k phan tu <= val (definitely)
-> minh can tim 1 tong co k ptu <= tong day
-> sort mang a goc sau do chon trung binh min, neu min thoa dieu kien, luu res (min luc nay la ung vien)
tiep tuc tim xem thoa hay khong, tom lai 1 gia tri duy nhat thoa


ok buoc lam cu the :

B1 : sort mang a, chon gia tri X de tim so cap a[i] + a[j] <= x = 2 con tro :33 ( se update cach chat nhi phan sau)
B2 : so sanh so do voi k => sau do chat nhi phan de biet chinh xac gia tri cua k
B3 : cout ans
*/
