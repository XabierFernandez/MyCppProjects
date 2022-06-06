#include <iostream>

long long pisanoPeriod(long long m){
    long long a=0, b=1 , c=0;
    for (long long i = 0; i < m * m; ++i) {
        c = (a+b)%m;
        a = b;
        b = c;
        if (a == 0 && b == 1)return i + 1;
    }
    return -1;
}

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long fibonacci_sum_fast(long long n) {
    long long rem = n % pisanoPeriod(10);
    long long previous = 0;
    long long current = 1;
    long long tmp_previous;
    long long sum = 1;

    if(rem == 0){
        return 0;
    }else if (rem == 1){
        return 1;
    }

    for (int i = 1; i < rem; i++) {
        tmp_previous = (previous + current) % 10;
        sum = sum + tmp_previous;
        previous = current;
        current = tmp_previous;
    }

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n)<< '\n';
}
