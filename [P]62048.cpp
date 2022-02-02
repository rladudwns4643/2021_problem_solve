using namespace std;

long long gcd(long long w, long long h) {
    long long a = w;
    long long b = h;
    long long c = 0;
    while (h != 0) {
        c = w % h;
        w = h;
        h = c;
    }
    return w;
}

long long solution(int w, int h) {
    long long W = w;
    long long H = h;
    if (w == h) {
        return (W * H) - W;
    }
    else {
        long long g = gcd(w, h);

        return (W * H) - (((W / g) + (H / g) - 1) * g);
    }
}