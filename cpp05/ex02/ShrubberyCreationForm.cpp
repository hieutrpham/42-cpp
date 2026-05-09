#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), m_target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), m_target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		m_target = other.m_target;
	}
	return *this;
}

void ShrubberyCreationForm::formAction() const {
	std::string file_name = m_target + "_shrubberry";
	std::fstream outfile(file_name, outfile.out);
	if (!outfile.is_open()) {
		throw std::runtime_error("could not open file");
	}
	outfile << R"(
       _-_              _-_              _-_              _-_
    /~~   ~~\        /~~   ~~\        /~~   ~~\        /~~   ~~\\
 /~~         ~~\  /~~         ~~\  /~~         ~~\  /~~         ~~\\
{               }{               }{               }{               }
 \  _-     -_  /  \  _-     -_  /  \  _-     -_  /  \  _-     -_  /
   ~  \\ //  ~      ~  \\ //  ~      ~  \\ //  ~      ~  \\ //  ~
_- -   | | _- _  _- -   | | _- _  _- -   | | _- _  _- -   | | _- _
  _ -  | |   -_    _ -  | |   -_    _ -  | |   -_    _ -  | |   -_
      // \\            // \\            // \\            // \\
	)";

	LOG("ShrubberyCreationForm performed action");
}
