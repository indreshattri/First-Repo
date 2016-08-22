#include <iostream>

using namespace std;

class mine{
	public:
		void setname(string x) {
			name = x;
		}
		string getname() {
			return name;
		}
	private :
		string name;
};

int main()
{
	mine bo;
	bo.setname("HEy  THere)");
	cout << bo.getname();
	return 0;
}
