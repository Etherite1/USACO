// simple implementation of the Euclidean Algorithm and the LCM function using GCD

long long gcd(long long int a, long long int b)
{
  return ((b == 0)? a : gcd(b, a % b));
}

long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
