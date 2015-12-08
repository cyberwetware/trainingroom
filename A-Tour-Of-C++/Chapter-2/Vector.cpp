
class Vector {
	public:
		Vector(int s) :elem{new double[s]}, sz{s} { }
		double& operator[](int i) { return elem[i]; }
		int size() { return sz; }
	private:
		double* elem; // pointer to the elements
		int sz;
		// the number of elements
};

//void test()
//{
	Vector v(6);
//}

