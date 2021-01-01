
// ceil 
ll aceil(ll num, ll denom)
{
    return (num + denom - 1) / denom;
}

// greatest common divisor
ll gcd(ll a, ll b)
{
    return __gcd(a, b);
}

// least common multiple
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

// checks whether two line segments intersect
bool inter(float p0_x, float p0_y, float p1_x, float p1_y, float p2_x, float p2_y, float p3_x, float p3_y)
{
    float s1_x, s1_y, s2_x, s2_y;
    s1_x = p1_x - p0_x;     
    s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;     
    s2_y = p3_y - p2_y;

    float s, t;
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1) return 1;
    else return 0; // No collision
}

