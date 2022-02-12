#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
private:
	std::string const	_formName;
	int					_signReq;
	int					_execReq;
	bool				_signed;
	std::string			_target;
	Form();
protected:
	virtual void	formExecution(std::string target) const = 0;
	void			setSignReq(int signReq);
	void			setExecReq(int execReq);
	void			setTarget(std::string target);
public:

	Form(std::string formName, int signReq, int execReq);
	Form(Form const& original);
	virtual ~Form();

	Form&				operator=(Form const& original);
	std::string	const	getName() const;
	int					getSignReq() const;
	int					getExecReq() const;
	bool				getSigned() const;
	void				beSigned(Bureaucrat const& bureaucrat);
	std::string			getTarget() const;
	void				execute(Bureaucrat const & executor) const;

	class GradeTooHighException : public std::exception{
	public:
		const char* what() const throw(){ //throw() - declares that the function throws no exceptions
			return "Grade too high [grade range: 1 - 150]";
		}
	};

	class GradeTooLowException : public std::exception{
	public:
		const char* what() const throw(){
			return "Grade too low [grade range: 1 - 150]";
		}
	};

	class FormAlreadySignedException : public std::exception{
	public:
		const char* what() const throw(){
			return "This form is already signed";
		}
	};

	class FormNotSignedException : public std::exception{
	public:
		const char* what() const throw(){
			return "This form is not yet signed";
		}
	};

	class GradeTooLowForExecException : public std::exception{
	public:
		const char* what() const throw(){
			return "Grade too low to execute this form";
		}
	};
};

std::ostream& operator<<(std::ostream& stream, const Form& form);

#endif
