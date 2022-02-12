#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"

class RobotomyRequestForm : public Form{
private:
	RobotomyRequestForm();
	void	formExecution(std::string target) const;
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const& original);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(RobotomyRequestForm const& original);
};

#endif
