#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int INF = 5e18;
const int MOD = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int,int>> p1,p2,p3;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n;i++){
        if(a[i]<0)p1.push_back({a[i], b[i]});
        if(a[i]>0)p2.push_back({a[i], b[i]});
        if(a[i]==0)
            p3.push_back({a[i], b[i]});
    }
    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }
    sort(c.begin() + 1, c.begin() + n + 1);
    auto check = [&](int y) -> bool
    {
        int cnt = 0;
        vector<long double> af, az;
        for(auto[a,b]:p1){
            af.push_back((long double)1.0*(y - b) / a);
        }
        sort(af.begin(), af.end());
        for (auto [a, b] : p2)
        {
            az.push_back((long double)1.0 * (y - b) / a);
        }
        sort(az.begin(), az.end());
        reverse(az.begin(), az.end());
        for(auto[a,b]:p3){
            cnt += (b >= y);
        }
        int i = 1, j = 0;
        for (; j < (int)af.size() && i <= n;){
            while(j<(int)af.size()&&af[j]<c[i]){
                j++;
            }
            if(j<(int)af.size()){
                cnt++;
                i++;
                j++;
            }
        }
        int ii = n, jj = 0;
        for (; jj < (int)az.size() && ii >= i;)
        {
            while (jj < (int)az.size() && az[jj] > c[ii])
            {
                jj++;
            }
            if (jj < (int)az.size())
            {
                cnt++;
                ii--;
                jj++;
            }
        }
        return cnt >= (n+1)/2;
    };
    int l = -INF, r = INF;
    while(l+1<r){
        int mid = (l + r) / 2;
        if(check(mid)){
            l = mid;
        }
  
        else{
                r = mid;
            }
    }
    cout << l << '\n';
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}