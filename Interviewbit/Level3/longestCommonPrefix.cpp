/*
Write a function to find the longest common prefix string amongst an array of strings.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.

Example:

Given the array as:

[

  "abcdefgh",

  "aefghijk",

  "abcefgh"
]*/
string compareTwoStrings(string prefix, string word) {

	if (word.size () == 0 || prefix == "") {
		return "";
	}

	string newPrefix = "";
	for (int i = 0; i < word.size() && i < prefix.size(); i++) {
		if (word[i] != prefix[i]) {
			return newPrefix;
		} else {
			newPrefix += word[i];
		}
	}
	return newPrefix;
}

string Solution::longestCommonPrefix(vector<string> &A) {
	if (!A.size()) return "";

	string prefix = A[0];

	for (int i = 1; i < A.size(); i++) {
		prefix = compareTwoStrings(prefix, A[i]);
	}
	return prefix;
}

