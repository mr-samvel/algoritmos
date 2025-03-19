#include <iostream>
#include <map>
using namespace std;

void read_input(long &N) {
    cin >> N;
}

map<long, int> factorize(long n) {
    map<long, int> factors;
    
    while (n % 2 == 0) {
        factors[2]++;
        n /= 2;
    }

    for (long f = 3; f*f <= n; f+=2) {
        while (n % f == 0) {
            factors[f]++;
            n /= f;
        }
    }

    if (n > 1)
        factors[n]++;
    
    return factors;
}

char solve(long n) {
    if (n == 1)
        return 'N';
    
    map<long, int> factors = factorize(n);

    if (factors.size() == 1) {
        int exponent = factors.begin()->second;
        return exponent % 2 == 1 ? 'Y' : 'N';
    } else if (factors.size() == 2) {
        int exponent1 = factors.begin()->second;
        int exponent2 = (++factors.begin())->second;
        return (exponent1 == 1 && exponent2 == 1) ? 'Y' : 'N';
    }

    return 'N';
}

int main() {
    long N;
    read_input(N);
    cout << solve(N);
}