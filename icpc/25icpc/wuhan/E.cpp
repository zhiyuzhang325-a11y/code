#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int INF = 5e18;
const int MOD = 998244353;
using i128 = __int128_t;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    map<int, int> mp1, mp2;
    for (int i = 1; i <= n; i++)
    {
        mp1[a[i]]++;
        mp2[b[i]]++;
    }
    multiset<int> A, B;
    for (int i = 1; i <= n; i++)
    {
        if (!mp2[a[i]])
            A.insert(a[i]);
        else
            mp2[a[i]]--;
        if (!mp1[b[i]])
            B.insert(b[i]);
        else
            mp1[b[i]]--;
    }
    n = A.size();
    // cout << n << endl;
    // for(auto x:A){
    //     cout << x << ' ';
    // }
    // cout << endl;
    // for (auto x : B)
    // {
    //     cout << x << ' ';
    // }
    // cout << endl;
    for (int i = 0; i < n; i++)
    {
        auto xa = *A.begin();
        auto xb = *B.begin();
        //cout << xa << ' ' << xb << endl;
        if (xa != xb)
        {
            auto nexa = A.find(xa + 1);
            auto nexb = B.find(xb + 1);
            if (nexa != A.end())
            {
                A.insert(*nexa + (xb - xa));
                A.erase(nexa);
            }
            else if(nexb != B.end()){
                B.insert(*nexb + (xa - xb));
                B.erase(nexb);
            }
            else{
                cout << "No" << endl;
                return;
            }
        }
        A.erase(A.find(xa));
        B.erase(B.find(xb));
        // cout << 'A' << endl;
        // for (auto it = A.begin(); it != A.end();it++){
        //     cout << *it << ' ';
        // }
        // cout << endl;
        // cout << "B" << endl;
        // for (auto it = B.begin(); it != B.end(); it++)
        // {
        //     cout << *it << ' ';
        // }
        // cout << endl;
    }
    cout << "Yes" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}