#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void input(vector<string>& words) {
	string input;
	int n;
	cin>>n;
	while(n--) {
		cin>>input;
		words.push_back(input);
	}
}

void count_repetitions(const vector<string>& words,map<string,int>& rep_map) {
	for(string x:words) {
		if(rep_map.find(x)==rep_map.end()) {
			rep_map[x] = 1;
		} else {
			++rep_map[x]; 
		}
	}
}

void print_repetitions(const map<string,int>& rep_map) {
	for(auto x:rep_map) {
		cout<<"word: "<<x.first<<" - "<<x.second<<endl; 
	}
}

int main() {
	map<string, int> rep_map;
	vector<string> words;
	input(words);
	count_repetitions(words, rep_map);
	print_repetitions(rep_map);

	return 0;
}