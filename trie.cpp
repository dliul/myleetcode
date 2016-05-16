#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::string;

class TrieNode {
	public:
		TrieNode* Children[26]; // 26 letters
		bool hasWord;
		TrieNode() {
			std::memset(Children, 0, sizeof(Children));
			hasWord = false;
		}
};

class Trie {
	public:
		Trie() {
			root = new TrieNode();
		}

		void insert(string word) {
			TrieNode* curr = root;
			for(auto c:word) {
				if (curr->Children[c-'a'] == NULL) {
					// if the letter is not in the child nodes, add a new one
					curr->Children[c-'a'] = new TrieNode();
				}
				curr = curr->Children[c-'a'];
			}
			curr->hasWord = true; // it forms a word

		}

		bool search(string word) {
			TrieNode* curr = root;
			for(auto c:word) {
				if (curr->Children[c-'a'] == NULL) return false;
				else curr = curr->Children[c-'a'];
			}
			return curr->hasWord ? true: false;
		
		}

		bool starsWith(string prefix) {
			TrieNode* curr = root;
			for(auto c:prefix) {
				if (curr->Children[c-'a'] ==NULL) return false;
				else curr = curr->Children[c-'a'];
			}
			return true;
		}

	private:
		TrieNode* root;
};

int main() {
	Trie test;
	test.insert("bad");
	test.insert("crazy");
	cout << "happy is " << test.search("happy") << "\n";
	cout << "bad is " << test.search("bad") << "\n";
}

