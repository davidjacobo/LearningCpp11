#include <string>
#include <cstring>
#include <iostream>
#define MAX_N 1000000
#define INV -1

using namespace std;
int trie[256][MAX_N], index;

bool in_text(const string& word) {
	int len = word.size();
	int node = 0;

	for(int i=0;i<len;++i) {
		char car = word[i];
		node = trie[node][car];

		if(node==-1) return false;
	}

	return true;
}

void build_branch(const string& text, int i, int node) {
	if(i >= text.size()) return;
 	unsigned char car = text[i];	

 	if(trie[node][car]==INV)	trie[node][car] = index++;

 	build_branch(text, i+1, trie[node][car]);
}

void build_trie(const string& text) {
	int len = text.size();
	memset(trie, INV, sizeof trie);
	index = 1;

	for(int i=0;i<len;++i) {
		build_branch(text, i, 0);
	}
}

int main() {
	string text;
	getline(cin, text);
	build_trie(text);

	//Alright lets do 10 queries
	int q = 10;
	while(q-->0) {
		getline(cin, text);
		if(in_text(text)) {
			cout<<"Trie patrol wins"<<endl;
		} else {
			cout<<"Word not found"<<endl;
		}
	}
	return 0;
}