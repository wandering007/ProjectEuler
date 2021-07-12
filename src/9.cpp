#include <iostream>

/*
a^2 + b^2 = c^2
a + b + c = 1000
a^2 + b^2 + c^2 + 2(ab + bc + ac) = 10^6
2c^2 + 2(ab + (1000 - c)c) = 10^6
2(ab + 1000c) = 10^6
c^2 > 2ab = 10^6 - 2000c
c^2 + 2000 c - 10 ^ 6 > 0
c > 2^0.5*1000 - 1000 = 414
*/

int main() {
    const int N = 1000;
    // a < b < c, so a should start from 1
    for (int a = 1; a < N; ++a) {
        for (int b = a + 1;; ++b) {
            int c = N - a - b;
            if (a + b < c) {
                continue;
            }
            if (c <= b or 2 * a * b >= c * c) {
                break;
            }
            if (a * a + b * b == c * c) {
                printf("a=%d, b=%d, c=%d, abc=%d\n", a, b, c, a * b * c);
                // break;
            }
        }
    }
    return 0;
}