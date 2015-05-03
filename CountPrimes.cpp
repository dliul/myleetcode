/* Description:
 *
 * Count the number of prime numbers less than a non-negative number, n
 *
 * Reference:
 * Sieve of Eratosthenes
 * http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 *
 */

#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::vector;

class Solution {
public:
	int countPrimes(int n) {
		if (n < 2) return 0;
		int cnt = 0;
		vector<int> primes (n - 2, 1);

		for (int i = 0; i < n - 2; ++i) {
			if (primes[i] != 0) {
				int step = i + 2;
				for ( int j = i; j < n - 2; j += step) {
					if (primes[j]) primes[j] = 0;
				}
				++cnt;
			}
		}
		return cnt;
	}
};

int main () {
	Solution test;

	int i;
	cin >> i;
	cout << "The input number 10 :" << test.countPrimes(i) << std::endl;

}
