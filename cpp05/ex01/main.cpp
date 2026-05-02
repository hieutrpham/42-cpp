#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat b;
		Bureaucrat a("hieu", 1);
		Bureaucrat c;
		Bureaucrat d(b);
		LOG(b);
		LOG(a);
		LOG(c);
		c = a;
		LOG(c);
		b.incrementGrade();
		LOG(b);
		a.decrementGrade();
		LOG(a);
	} catch (std::exception& e) {
		ERR(e.what());
	}

	try {
		Form a, b, c;
		LOG(a);
		LOG(b);
		LOG(c);
		Form d(b);
		LOG(d);
		c = a;
		Bureaucrat b1("hieu", 4);
		Form e("cookie", 0, 3, 123);
		LOG(e);
		b1.signForm(e);
		LOG(e);
	} catch (std::exception& e) {
		ERR(e.what());
	}
}
