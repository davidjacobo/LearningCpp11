#include <string>
#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

bool is_palindrome(const string line) {
	int len = line.size();

	for(int i=0;i<len/2;++i) {
		if(line[i]!=line[len-i-1]) return false;
	}
	return true;
}

int pimp_my_hashing(const string line, int base, int MOD) {
	ll hash = 0;
	int len = line.size();

	for(int i=0;i<len;++i) {
		hash = (hash*base + line[i]) % MOD;
	}

	return hash;
}

bool is_anagram(const string line_a, const string line_b) {
	int counter[256];
	memset(counter, 0, sizeof counter);
	int len_a = line_a.size();
	int len_b = line_b.size();

	if(len_a!=len_b) return false;

	for(int i=0;i<len_a;++i) {
		++counter[line_a[i]];
	}

	for(int i=0;i<len_b;++i) {
		--counter[line_b[i]];
		if(counter[line_b[i]] <0) return false;
	}
	return true;
}

int main(){
	string word;
	getline(cin, word);
	if(is_palindrome(word)) {
		cout<<"Ok this word is palindrom"<<endl;
	} else {
		cout<<"N O T P A L I N D R O M E B O Y Z"<<endl;
	}

	string word2;
	getline(cin, word);
	getline(cin, word2);
	if(is_anagram(word, word2)) {
		cout<<"Ok these guys are anagram of each other"<<endl;
	} else {
		cout<<"N O T A N A G R A M B O Y Z"<<endl;
	}

	getline(cin, word);
	cout<<pimp_my_hashing(word, 26, 1000000007)<<endl;
	return 0;
}