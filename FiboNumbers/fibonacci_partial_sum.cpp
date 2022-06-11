#include <iostream>


long long fibonacci_fast(int n) {
    // write your code here
    long long f1=0,f2=1;
    if (n < 2)
        return n;  
 
    for (int i = 0;i < n-1;i++)
    {
        long long tmp_f1 = f1;
        f1 = f2;
        f2 = tmp_f1 + f2;
    }
 
  return f2;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    to = to % 60;
    from = from % 60;
    long long sum = 0;
    long long fib60[60];

    for(int i=0;i<60;i++) {
        fib60[i] = fibonacci_fast(i);
        std::cout << i << "=" << fib60[i] << "\n";
    } 

    if(to < from) to = to + 60;

    for (int j = from; j < to + 1; j++) {
        sum = sum + fib60[j];
    }

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
