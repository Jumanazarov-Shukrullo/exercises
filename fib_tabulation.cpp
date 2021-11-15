/// C++ program to compute fibonacci numbers in range from 1 to 100

#include <iostream>
#include <vector>

size_t fib(size_t n) {
    std::vector<size_t> vec(n);
    if (n <= 1) {
        return n;
    }
    vec[0] = 0;
    vec[1] = 1;
    for (int i = 2; i <= n; ++i) {
        vec[i] = vec[i - 1] + vec[i - 2];
    }
    return vec[n];
}

int main() {
    size_t n;
    std::cin >> n;
    std::cout << fib(n);
}
