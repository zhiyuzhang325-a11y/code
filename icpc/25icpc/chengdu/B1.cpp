#include <bits/stdc++.h>
using namespace std;

using ll = long long;
static const ll NEG_INF = (ll)-4e18; // sufficiently small

// C = A (max-plus) B, dimension dim
// optimized loop order: i, k, j and skip NEG_INF entries
void matMultiply(vector<vector<ll>> &C,
                 const vector<vector<ll>> &A,
                 const vector<vector<ll>> &B,
                 int dim)
{
    // initialize C to NEG_INF
    for (int i = 0; i < dim; ++i)
    {
        std::fill(C[i].begin(), C[i].end(), NEG_INF);
    }
    for (int i = 0; i < dim; ++i)
    {
        for (int k = 0; k < dim; ++k)
        {
            ll aik = A[i][k];
            if (aik == NEG_INF)
                continue;
            // iterate j, try to update C[i][j] with aik + B[k][j]
            const vector<ll> &Bk = B[k];
            vector<ll> &Ci = C[i];
            for (int j = 0; j < dim; ++j)
            {
                ll bkj = Bk[j];
                if (bkj == NEG_INF)
                    continue;
                ll val = aik + bkj;
                if (val > Ci[j])
                    Ci[j] = val;
            }
        }
    }
}

// result = M^p (max-plus), dim = (1<<n)
void matPower(vector<vector<ll>> &result,
              const vector<vector<ll>> &M,
              long long p, int dim)
{
    // result = identity (max-plus): diag = 0, others = -inf
    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < dim; ++j)
        {
            result[i][j] = (i == j ? 0LL : NEG_INF);
        }
    }
    vector<vector<ll>> base = M;
    vector<vector<ll>> temp(dim, vector<ll>(dim, NEG_INF));
    while (p > 0)
    {
        if (p & 1LL)
        {
            matMultiply(temp, result, base, dim);
            result.swap(temp);
        }
        matMultiply(temp, base, base, dim);
        base.swap(temp);
        p >>= 1LL;
    }
}

// res = v (vector) * M (max-plus)
void vecMatMultiply(vector<ll> &res,
                    const vector<ll> &v,
                    const vector<vector<ll>> &M,
                    int dim)
{
    for (int j = 0; j < dim; ++j)
    {
        ll best = NEG_INF;
        for (int i = 0; i < dim; ++i)
        {
            if (v[i] == NEG_INF)
                continue;
            ll mij = M[i][j];
            if (mij == NEG_INF)
                continue;
            ll val = v[i] + mij;
            if (val > best)
                best = val;
        }
        res[j] = best;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#if defined(__GNUC__)
    // nothing
#endif

    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int n;
        long long m, k, R;
        cin >> n >> m >> k >> R;
        vector<ll> a(n), c(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i] >> c[i];

        int dim = 1 << n;
        vector<vector<ll>> Mmat(dim, vector<ll>(dim, NEG_INF));

        // precompute costWhenS[s][i]
        vector<vector<ll>> costWhenS(dim, vector<ll>(n, 0));
        for (int s = 0; s < dim; ++s)
        {
            for (int i = 0; i < n; ++i)
            {
                if (s & (1 << i))
                    costWhenS[s][i] = c[i] + k;
                else
                    costWhenS[s][i] = c[i];
            }
        }

        // build transition matrix
        for (int s = 0; s < dim; ++s)
        {
            for (int t = 0; t < dim; ++t)
            {
                ll sumCost = 0;
                ll sumDamage = 0;
                // t's bits indicate who acts this round; next state's bits = t
                for (int i = 0; i < n; ++i)
                {
                    if (t & (1 << i))
                    {
                        sumCost += costWhenS[s][i];
                        if (sumCost > m)
                            break;
                        sumDamage += a[i];
                    }
                }
                if (sumCost <= m)
                    Mmat[s][t] = sumDamage;
                // else remains NEG_INF
            }
        }

        // power Mmat^R
        vector<vector<ll>> Mpow(dim, vector<ll>(dim, NEG_INF));
        matPower(Mpow, Mmat, R, dim);

        // initial vector v: only state 0 has 0
        vector<ll> v(dim, NEG_INF);
        v[0] = 0;
        vector<ll> vFinal(dim, NEG_INF);
        vecMatMultiply(vFinal, v, Mpow, dim);

        ll ans = NEG_INF;
        for (int i = 0; i < dim; ++i)
            if (vFinal[i] > ans)
                ans = vFinal[i];
        if (ans == NEG_INF)
            ans = 0; // just in case, though should not happen
        cout << ans << '\n';
    }

    return 0;
}