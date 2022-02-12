#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>

# define DEFAULT_GRADE 150

class Bureaucrat{
private:
	std::string const	_name;
	int					_grade;
	Bureaucrat();

public:

	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const& original);
	~Bureaucrat();

	Bureaucrat&			operator=(Bureaucrat const& original);
	std::string	const	getName() const;
	int					getGrade() const;
	void				improveGrade();
	void				diminishGrade();

	class GradeTooHighException : public std::exception{ //create exceptions as subclasses of std exception
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
};

// declare this prototype outside the class because it's altering an instance of another class (ostream).
std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);

#endif
