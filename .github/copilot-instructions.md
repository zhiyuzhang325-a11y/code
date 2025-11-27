# Copilot Instructions for Competitive Programming Codebase

## Project Overview
This is a competitive programming practice repository organized by:
- **数据结构/** (Data Structures) - Categorized by algorithm type (并查集/Disjoint Set, 树状数组/Fenwick Tree, st表/Sparse Table)
  - Each subdirectory has 入门 (Beginner) and 进阶 (Advanced) templates
- **icpc/** - ICPC contest solutions organized by year and competition location
- **ccpc/** - CCPC contest solutions with similar structure

## Core Coding Patterns & Conventions

### Standard Template Structure
All solution files follow this exact boilerplate:
```cpp
#include <bits/stdc++.h>
using namespace std;
#ifdef GILBCXX_DEBUG
#define DEBUG(x) std::cerr << x << std::endl
#else
#define DEBUG(x)
#endif
#define endl '\n'                    // Fast output (usually enabled)
#define int long long               // Default integer type is 64-bit
const int INF = 5e18;               // Standard infinity
const int MOD = 998244353;          // Standard modulo (NTT prime)
using i128 = __int128_t;            // For large intermediate calculations

void solve() { /* problem logic */ }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;  // Uncomment for multi-test cases
    while (T--) solve();
}
```

**Key variants to preserve:**
- Some files disable `endl` redefinition (comment it out) when precise output control needed
- `#define int long long` is NOT used in some advanced problems—check if overflow is possible before assuming 64-bit

### Template Classes & Data Structures
Reference implementations in 数据结构:
- **BIT (Fenwick Tree)** - `树状数组/进阶/P111.cpp` & 入门 files: Generic template with `update(x, p)`, `query(x)`, `query(l, r)`, `lower_bound(target)`
- **Disjoint Set Union** - `并查集/入门/P3367.cpp`: Path compression + union by size, methods: `find(u)`, `unite(u,v)`, `is_united(u,v)`
- **Sparse Table** - `st表/入门/P3865.cpp`: Static RMQ, methods: `query(l, r)`

Always use `signed main()` when `#define int long long` is active.

## Build & Execution
- **Compiler**: `g++.exe` from `E:\vscode\mingw64\bin\`
- **Task**: Run via VS Code task "C/C++: g++.exe 生成活动文件" or compile: 
  ```
  g++.exe -fdiagnostics-color=always -g <file> -o <file>.exe
  ```
- **Fast I/O**: Always include `ios::sync_with_stdio(false); cin.tie(nullptr);`

## Problem-Specific Patterns

### Input Format
- First line: number of test cases T (often 1, sometimes multiple)
- Contest problems use 1-indexed arrays: `vector<int> a(n + 1)` loops from `i = 1` to `i <= n`

### Competitive Programming Idioms
- Use `__gcd()` for GCD (example: `数据结构/icpc/24icpc/hangzhou/H.cpp`)
- Use `__lg(n)` for log2(n) (examples: BIT lower_bound, Sparse Table)
- Bit manipulation: `x & -x` for lowest set bit (BIT operations)
- Lambda recursion: `auto dfs = [&](auto &&dfs, ...) { ... dfs(dfs, ...); };` for recursive functions

### Sorting & Lambdas
Common pattern:
```cpp
sort(a.begin() + 1, a.end(), [&](auto a, auto b) {
    return a.second - a.first > b.second - b.first;  // Custom comparator
});
```

## File Organization Rules
- Data structure templates are **reusable across contests**; check 数据结构 before reimplementing
- Contest solutions follow event structure: `ccpc/25ccpc/huerbin/A.cpp`, `icpc/24icpc/hangzhou/H.cpp`
- Incomplete files may exist (see `P111.cpp` with unfinished `solve()`)—this is normal for active development

## Debug Workflow
- `DEBUG()` macro is predefined but disabled by default (`GILBCXX_DEBUG` not set in release builds)
- Enable via compiler flag `-DGILBCXX_DEBUG` for debug builds if needed
- Avoid `cout` in performance-critical sections; use `#define endl '\n'` everywhere

## Key Constraints & Assumptions
- Integer overflow is expected at 5e18+ values; use `i128` or restructure algorithm
- MOD = 998244353 for modular arithmetic (NTT-friendly prime)
- 1-indexed arrays are standard (index 0 unused)
- Multi-test cases common but not universal—check problem statement

---
**When implementing new solutions:** Follow the boilerplate exactly, use existing templates from 数据结构/, and maintain the solve() structure for consistency.
