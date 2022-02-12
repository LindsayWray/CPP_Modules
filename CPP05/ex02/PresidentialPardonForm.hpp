#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"

class PresidentialPardonForm : public Form{
private:
	PresidentialPardonForm();
	void	formExecution(std::string target) const;
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const& original);
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=(PresidentialPardonForm const& original);
};

#endif
