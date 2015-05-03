#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> results;
		if (digits.empty()) return results;
		digits2Letters(results, 0, digits, "");
		return results;
	}

private:
	void digits2Letters(vector<string> &results, int pos, string digits, string str) {
		string letters[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
					
		if (pos == digits.size()) {
			results.push_back(str);	
			return; 
		}
		else {
			int idx = pos; // the first number in the phone number
			for (int i = 0;i < letters[digits[pos]-'2'].size(); ++i) {
				str = str + letters[digits[pos]-'2'][i];
				digits2Letters(results, pos+1, digits, str);
				str.pop_back();
			}

		}
	}
};

int main () {

	Solution s;
	vector<string> re = s.letterCombinations("235674");

	for (auto i = re.begin(); i != re.end(); ++i)
		cout << *i << endl;
}
