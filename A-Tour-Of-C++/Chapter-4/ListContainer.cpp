class List_container : public Container {// List_container implements Container
	std::list<double> ld; // (standard-librar y) list of doubles (§9.3)
	public:
	List_container() { } // empty List
	List_container(initializ er_list<double> il) : ld{il} { }
	~List_container() {}

	 double& operator[](int i);
	 int size() const { return ld.size(); }
};

double& List_container::operator[](int i)
{
	for (auto& x : ld) {
		if (i==0) return x;
		--i;
	}
	throw out_of_range("List container");
}
