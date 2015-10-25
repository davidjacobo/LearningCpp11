class Vector{
public:
	Vector(int n);
	double& operator[](int i);
	int size();
private:
	double* elem;
	int sz;
};