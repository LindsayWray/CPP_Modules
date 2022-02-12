#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form{
private:
	ShrubberyCreationForm();
	void	formExecution(std::string target) const;
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const& original);
	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(ShrubberyCreationForm const& original);
};

#endif
