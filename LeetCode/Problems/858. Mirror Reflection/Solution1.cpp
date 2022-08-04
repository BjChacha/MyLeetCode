// math
class Solution {
private:
    int gcd(int a, int b) {
        if (a < b) return gcd(b, a);
        while (b) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
public:
    int mirrorReflection(int p, int q) {
        int total = p * q / gcd(p, q);
        if ((total / q) % 2 == 0) return 2;
        return (total / p) % 2;
    }
};
