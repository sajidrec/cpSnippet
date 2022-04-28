#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;

lld binpow(lld base, lld power)
{
    //** Time complexity O(log(n)) **//

    // if power is odd then res = res*base and power--
    // if power if even then base = base*base and power = power/2
    // if power is zero then res will be the answer

    lld res = 1;

    while (power)
    {
        if (power == 1)
        {
            res *= base;
            power = 0;
            break;
        }
        if (power % 2 == 0)
        {
            base *= base;
            power /= 2;
        }
        else
        {
            res *= base;
            power--;
        }
    }

    return res;
}

bool isPrime(lld num)
{
    // Time complexity O(sqrt(n))

    if (num == 1 || (num % 2 == 0 && num != 2))
    {
        return false;
    }
    for (lld i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
