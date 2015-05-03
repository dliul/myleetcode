#include <iostream>
#include <tr1/unordered_set>
//typedef std::unordered_set< int > intSet;
using namespace::std::tr1;

class solution {
	public:
		bool isHappy( int n ) {
			unordered_set< int > cycle;
			int new_num = n;
					
			while (true) {
				if ( new_num == 1 ) return true;
				else {
					std::cout << new_num << "\n";	
					new_num = sumSquareDigits(new_num);
					auto exist = cycle.insert(new_num);
					if ( !exist.second ) return false;
				}
			}

			
		}
	private:
		int sumSquareDigits(int number) {
			int sum = 0;
			int input = number;

			while (input) {
				sum += (input % 10) * (input % 10);
				input = input / 10;
			}

			return sum;
		}

};

int main() {
	solution test;

	std::cout << "the test number 19 " << test.isHappy(19) << "\n"; 

}
