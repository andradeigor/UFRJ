#include <iostream>
#include <map>

std::map<int, int> primeFactors(int N) {
    std::map<int, int> primfac;
    int p = 2;
    
    while (p * p <= N) {
        while (N % p == 0) {
            if(primfac.find(p) == primfac.end()){
                primfac[p] = 0;
            }
            primfac[p] +=1 ;
            N /= p;
        }
        p++;
    }
    
    if (N > 1) {
        primfac[N] = 1;
    }
    
    return primfac;
}

int main() {
    int n;
    while (std::cin >> n) {
        std::map<int, int> fact = primeFactors(n);
        int result = 0;
        for (const auto& [number, factor] : fact) {
            result += factor * number;
        }
        std::cout << result << std::endl;
    }

    return 0;
}
