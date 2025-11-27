#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ceil division a/b ; assume b>0
static inline ll ceil_div(ll a, ll b)
{
    if (b <= 0)
        throw;
    if (a >= 0)
        return (a + b - 1) / b;
    return a / b; // for our usage we'll clamp negative L to 0 later
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> d(n);
        int cnt0 = 0, cnt100 = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> d[i];
            if (d[i] == 0)
                ++cnt0;
            if (d[i] == 100)
                ++cnt100;
        }

        // Special cases
        // 1) All zeros:
        if (cnt0 == n)
        {
            // Feasible iff n >= 201 (derivation in analysis).
            if (n <= 200)
            {
                cout << "No\n";
                continue;
            }
            else
            {
                // Constructive solution for n >= 201:
                // choose m = 200*n + 1 (so r=1, k=n), then
                // R_i = floor((m-1)/200) = n, so capacity sum = n*n >= m for n>=201.
                ll m = 200LL * n + 1;
                vector<ll> ans(n, 0);
                ll cap_each = ((m - 1) / 200); // = n
                // Greedily fill using capacity; easiest: give each cap_each until sum reaches m
                ll remaining = m;
                for (int i = 0; i < n; ++i)
                {
                    ll give = min(remaining - (ll)(n - 1 - i) * 0LL, cap_each);
                    // give at most cap_each, but ensure we can fill remaining with later zeros
                    // simple greedy: give min(cap_each, remaining)
                    give = min(give, remaining);
                    ans[i] = give;
                    remaining -= give;
                }
                if (remaining != 0)
                {
                    // fallback: distribute properly (this branch should not happen for n>=201)
                    remaining = m;
                    for (int i = 0; i < n; ++i)
                    {
                        ll give = min(cap_each, remaining);
                        ans[i] = give;
                        remaining -= give;
                    }
                }
                cout << "Yes\n";
                for (int i = 0; i < n; ++i)
                {
                    if (i)
                        cout << ' ';
                    cout << ans[i];
                }
                cout << '\n';
                continue;
            }
        }

        // 2) All one-hundreds:
        if (cnt100 == n)
        {
            // Only possible when n == 1
            if (n == 1)
            {
                cout << "Yes\n1\n";
            }
            else
            {
                cout << "No\n";
            }
            continue;
        }

        // General case: enumerate m up to a reasonable limit (e.g. 10000)
        // For each m compute integer L_i,R_i and check sumL <= m <= sumR
        bool found = false;
        vector<ll> answer;
        const int MMAX = 10000; // practical safe bound

        for (int m = 1; m <= MMAX && !found; ++m)
        {
            vector<ll> L(n), R(n);
            ll lowSum = 0, highSum = 0;
            bool bad = false;
            for (int i = 0; i < n; ++i)
            {
                ll numL = (ll)m * (2LL * d[i] - 1LL);
                ll Li = ceil_div(numL, 200LL);
                if (Li < 0)
                    Li = 0;
                ll numR = (ll)m * (2LL * d[i] + 1LL) - 1LL;
                ll Ri = numR / 200LL;
                if (Ri < 0)
                    Ri = 0;
                if (Li > Ri)
                {
                    bad = true;
                    break;
                }
                L[i] = Li;
                R[i] = Ri;
                lowSum += Li;
                highSum += Ri;
                if (lowSum > m)
                {
                    bad = true;
                    break;
                } // early prune
            }
            if (bad)
                continue;
            if (lowSum <= m && m <= highSum)
            {
                // construct by greedy
                ll extra = m - lowSum;
                answer.assign(n, 0);
                for (int i = 0; i < n; ++i)
                {
                    ll add = min(extra, R[i] - L[i]);
                    answer[i] = L[i] + add;
                    extra -= add;
                }
                if (extra == 0)
                {
                    found = true;
                    break;
                }
                // otherwise continue (should rarely happen)
            }
        }

        if (!found)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
            for (int i = 0; i < (int)answer.size(); ++i)
            {
                if (i)
                    cout << ' ';
                cout << answer[i];
            }
            cout << '\n';
        }
    }

    return 0;
}
