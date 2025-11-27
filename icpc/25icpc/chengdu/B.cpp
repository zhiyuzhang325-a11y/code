#include <bits/stdc++.h>
using namespace std;
#define int long long
const int NEG = -4e18;

void mul(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int n)
{
    for (int i = 0; i < n; i++)
        fill(C[i].begin(), C[i].end(), NEG);
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            if (A[i][k] != NEG)
                for (int j = 0; j < n; j++)
                    if (B[k][j] != NEG)
                        C[i][j] = max(C[i][j], A[i][k] + B[k][j]);
}

vector<vector<int>> power(vector<vector<int>> base, long long p, int n)
{
    vector<vector<int>> res(n, vector<int>(n, NEG)), tmp(n, vector<int>(n, NEG));
    for (int i = 0; i < n; i++)
        res[i][i] = 0;
    while (p)
    {
        if (p & 1)
        {
            mul(res, base, tmp, n);
            res.swap(tmp);
        }
        mul(base, base, tmp, n);
        base.swap(tmp);
        p >>= 1;
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, k, R;
        cin >> n >> m >> k >> R;
        vector<int> a(n), c(n);
        for (int i = 0; i < n; i++)
            cin >> a[i] >> c[i];
        int N = 1 << n;
        vector<vector<int>> M(N, vector<int>(N, NEG));

        // 预计算每个状态下的费用
        vector<vector<int>> cost(N, vector<int>(n));
        for (int s = 0; s < N; s++)
            for (int i = 0; i < n; i++)
                cost[s][i] = c[i] + ((s >> i) & 1 ? k : 0);

        // 构建状态转移矩阵
        for (int s = 0; s < N; s++)
            for (int t = 0; t < N; t++)
            {
                int sumC = 0, sumD = 0;
                for (int i = 0; i < n; i++)
                    if ((t >> i) & 1)
                    {
                        sumC += cost[s][i];
                        if (sumC > m)
                            break;
                        sumD += a[i];
                    }
                if (sumC <= m)
                    M[s][t] = sumD;
            }

        // M^R
        auto MP = power(M, R, N);

        // 初始状态为 0，只取 M^R 第 0 行的最大值
        int ans = *max_element(MP[0].begin(), MP[0].end());
        cout << ans << '\n';
    }
}
