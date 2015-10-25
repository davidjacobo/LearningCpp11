#include <iostream>

using namespace std;

struct Vector {
	int sz;
	double *elem;
};

void init_vector(Vector& nums) {
	int n = nums.sz;
	for(int i=0;i<n;++i) {
		nums.elem[i] = i;
	}
}

int sum_elements(const Vector& nums) {
	int ans = 0;
	int n = nums.sz;
	for(int i = 0;i<n;++i) {
		ans+= nums.elem[i];
	}
	return ans;
}

void allocate_memory(Vector& nums, int n) {
	nums.elem = new double[n];
	nums.sz = n;
}

int main() {
	Vector nums;
	allocate_memory(nums, 10);
	init_vector(nums);
	cout<<sum_elements(nums)<<endl;
	return 0;
}