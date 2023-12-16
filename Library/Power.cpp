template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; a *= a, b /= 2) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
