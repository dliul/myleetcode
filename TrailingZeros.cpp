/* Given an integer n, return the number of trailing zeroes in n!.
 *
 * Note: Your solution should be in logarithmic time complexity.
 *
 * Reference:
 * http://en.wikipedia.org/wiki/Trailing_zero
 *
 *
 *
 *
 */


#include <iostream>
#include <math.h>
using std::cout;
using std::cin;

class Solution {
	public:
		int trailingZeros (int n) {
			if ( n <= 0 ) return 0;
			int sum = 0;
			do {
				sum += n / 5;
				n = n / 5;
			} while (n);
			return sum;	
		}

};


int main () {
	Solution test;
	
	int input;
	cin >> input;
	cout << test.trailingZeros(input) << std::endl;
}
