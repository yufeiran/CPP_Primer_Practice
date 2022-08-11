#include<exception>
#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
	try {
		throw overflow_error("23");
	}
	catch (overflow_error e) {
		cout << "overflow_error" << endl;
		abort();
	}
	catch (underflow_error e) {
		cout << "underflow_error" << endl;
		abort();
	}
	catch (range_error e) {
		cout << "range_error" << endl;
		abort();
	}
	catch (domain_error e) {
		cout << "domain_error" << endl;
		abort();
	}
	catch (invalid_argument e) {
		cout << "invalid_argument" << endl;
		abort();
	}
	catch (out_of_range e) {
		cout << "out_of_range" << endl;
		abort();
	}
	catch (length_error e) {
		cout << "length_error" << endl;
		abort();
	}
	catch (runtime_error e) {
		cout << "runtime_error" << endl;
		abort();
	}
	catch (logic_error e) {
		cout << "logic_error" << endl;
		abort();
	}
	catch (bad_cast e) {
		cout << "bad_cast" << endl;
		abort();
	}
	catch (bad_alloc e) {
		cout << "bad_alloc" << endl;
		abort();
	}
	catch (exception e) {
		cout << "exception" << endl;
		abort();
	}

	return 0;
}