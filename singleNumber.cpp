#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class solution {
public:
	int singleNumber(vector<int>& nums) {
		int one = 0, two = 0, three = 0;
		for (auto it = nums.begin();it != nums.end(); ++it) {
			two = two | one & (*it);
			one = one ^ *it;
			three = two & one;
			one = one & (~three);
			two = two & (~three);	
		}
		return one;
	}	
};

int main () {
	solution s;
	vector<int> input {12, 1, 12, 3, 12, 1, 1, 2, 3, 3};
	cout << s.singleNumber(input) << endl;
}
