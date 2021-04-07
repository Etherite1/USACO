long long binpow(long long a, long long b, long long m = 1e9 + 7) 
{
    a %= m;
    long long res = 1;
    while(b > 0) 
    {
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

long long modinv(long long a, long long m = 1e9 + 7)
{
    return binpow(a, m - 2, m);
}