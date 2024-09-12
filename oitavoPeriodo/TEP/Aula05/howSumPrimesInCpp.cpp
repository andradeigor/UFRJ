#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std; 

vector<bool> P(10000001, true);
unordered_set<int> crivo(int N) {
    unordered_set<int> numbers;
    if (N < 2) return numbers;

    P[0] = P[1] = false;

    for (unsigned int value = 2; value <= N; value++) {
        if (P[value]) {        
            numbers.insert(value);
            for (unsigned int i = value * value; i <= N; i += value) {
                //cout<< "deveria estar appendando " << i << endl;    
                if(i <= N){
                    P[i] = false;
                }
            }
        }
    }

    return numbers;
}

pair<int, int> resolve(int n, const unordered_set<int>& numbers) {
    for (int i : numbers) {
        if (numbers.count(n - i) != 0) {
            return {i, n - i};
        }
    }
    return {-2, -1}; // Indica que não encontrou
}

int main() {
    int limit = 10000000;
    
    

    unordered_set<int> numbers = crivo(limit);

    int n;
    while (cin >> n) {
        if (n == 0) break;
        if (n < 8) {
            cout << "Impossible." << endl;
            continue;
        }

        pair<int, int> res;
        if (n % 2 == 0) {
            res = resolve(n - 4, numbers);
            cout << "2 2 " << res.first << " " << res.second << endl;
        } else {
            res = resolve(n - 5, numbers);
            cout << "2 3 " << res.first << " " << res.second << endl;
        }
    }

    return 0;
}