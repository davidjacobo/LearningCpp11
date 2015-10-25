#include <iostream>

using namespace std;

class Vector{
public:
	Vector(int s) : elem{new double[s]}, sz{s} {}
	double& operator[](int i) {return elem[i];}
	int size() {return sz;}
private:
	int sz;
	double* elem;
};

void set_values(Vector& nums) {
	for(auto i=0;i<nums.size();++i){
		nums[i] = i;
	}
}

int main(){
	Vector vec(6), vec2(100);
	//Should they be of the same size? Even
	//if pointing to different length arrays?
	set_values(vec);
	set_values(vec2);
	cout<<sizeof(vec)<<endl;
	cout<<sizeof(vec2)<<endl;

	//Short answer: Yes
	return 0;
}