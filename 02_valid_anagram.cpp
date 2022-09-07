/**
 *
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 *
 *
 *
 */

#include <bits/stdc++.h>

class Solution {
private:
	std::array<int, 256> chars = { 0 };
public:
	void printArray() {
		for (int i=0; i<256; i++) {
			if (chars[i])
				printf("%c: %d ", i, chars[i]);
		}
		std::cout << std::endl;
	}

    bool isAnagram(std::string s, std::string t) {
		if (s.size() != t.size())
			return false;

		std::string::iterator it;
		for (it = s.begin(); it != s.end(); ++it) {
			int idx = int(*it);
			printf("%c %d\n", *it, idx);
			chars[idx]++;
		}
		printArray();

		for (it = t.begin(); it != t.end(); ++it) {
			int idx = int(*it);
			printf("%c %d\n", *it, idx);
			if (chars[idx]) {
				--chars[idx];

			} else
				return false;
			printArray();
		}
		return true;
    }
};

int main() {
	Solution	sol;
	std::string	s = "anagram";
	std::string	t = "nagaram";
	std::cout << "Solution: " << sol.isAnagram(s, t) << std::endl;
}
