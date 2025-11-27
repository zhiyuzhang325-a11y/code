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
    
    vector<deque<int>> pos(2 * n + 10);
    for (int i = 1; i <= n; i++)
    {
        pos[a[i]].push_back(i);
        pos[b[i]].push_back(i);
    }
    for (int i = 1; i <= n;i++){
        if(pos[a[i]].size()%2||pos[b[i]].size()%2){
            cout << -1 << endl;
            return;
        }
    }

    int cost = 0, num = 0;
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++)
    {
        pos[a[i]].pop_front();
        pos[b[i]].pop_front();
        if (a[i] == b[i]){
            continue;
        }
        int j1 = pos[a[i]].front();
        int j2 = pos[b[i]].front();
        if (j1 < j2)
        {
            cost += j1 - i;
            pos[a[i]].pop_front();
            pos[b[i]].push_front(j1);
            if (a[j1] == a[i])
            {
                swap(a[j1], b[i]);
                num++;
                ans.push_back({j1, i});
                //cout << "A" << ' ';
            }
            else
            {
                swap(b[j1], b[i]);
                num += 2;
                ans.push_back({i, i});
                ans.push_back({i, j1});
                //cout << "B" << ' ';
            }
        }
        else
        {
            cost += j2 - i;
            pos[a[i]].push_front(j2);
            pos[b[i]].pop_front();
            if (a[j2] == b[i])
            {
                swap(a[j2], a[i]);
                num += 2;
                ans.push_back({i, i});
                ans.push_back({j2, i});
                //cout << "C" << ' ';
            }
            else
            {
                swap(b[j2], a[i]);
                num++;
                ans.push_back({i, j2});
                //cout << "D" << ' ';
            }
        }
    }
    cout << cost << ' ' << num << endl;
    for (auto [i, j] : ans)
    {
        cout << i << ' ' << j << endl;
    }
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