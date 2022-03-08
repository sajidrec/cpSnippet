#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;

lld binpow(lld base, lld power)
{
    if (!power)
        return 1;
    lld res = binpow(base, power / 2);
    if (power % 2)
        return res * res * base;
    else
        return res * res;
}

int main(void)
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
