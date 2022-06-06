#include <iostream>
#include <vector>
using std::vector;

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

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    long long rem = to % pisanoPeriod(10);
    long long previous = 0;
    long long current = 1;
    long long tmp_previous;
    long long sum = 0;

    if(from <2){
        sum = 1;
        from = 2; 
    }
    
    for (int i = from; i < rem; i++) {
        tmp_previous = (previous + current) % 10;
        sum = sum + tmp_previous;
        previous = current;
        current = tmp_previous;
    }

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
