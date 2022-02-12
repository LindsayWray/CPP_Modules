#include "scalarConversion.hpp"

void	inputError(){
	std::cerr << "\nInput Error: must be of type char, int, float or double.\n";
	exit(EXIT_FAILURE);
}

void	convertChar(char value){
	std::cout << "\nconvert char:   '" << value << "'" << std:: endl;
	std::cout << "        int:    " << static_cast<int>(value) << std::endl;
	std::cout << std::fixed;
	std::cout << "        float:  " << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "        double: " << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void	convertInt(long value){
	if (value > INT_MAX || value < INT_MIN){
		std::cerr << "Input error: not a valid integer\n";
		return ;
	}
	std::cout << "\nconvert int:    " << value << std:: endl;
	if (isprint(static_cast<char>(value)))
		std::cout << "        char:   '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "        char:   Non displayable" <<  std::endl;
	std::cout << std::fixed;
	std::cout << "        float:  " << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "        double: " << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

bool	infiniteOrNan(double value){
	if (isinf(value) || isnan(value) || value > INT_MAX || value < INT_MIN){
		std::cout << "        char:   impossible" <<  std::endl;
		std::cout << "        int:    impossible" <<  std::endl;
		return true;
	}
	return false;
}

void	convertFloat(double value){
	if ((value > FLT_MAX || value < -FLT_MAX) && !isinf(value)){
		std::cerr << "Input error: not a valid float\n";
		return ;
	}
	std::cout << std::showpoint;
	std::cout << "\nCONVERT float:  " << value << "f" << std:: endl;
	std::cout << "        double: " << static_cast<double>(value) << std::endl;
	if (infiniteOrNan(value))
		return ;
	if (isprint(static_cast<char>(value)))
		std::cout << "        char:   '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "        char:   Non displayable" <<  std::endl;
	std::cout << "        int:    " << static_cast<int>(value) << std::endl;

}

void	convertDouble(double value){
	if ((value > DBL_MAX || value < -DBL_MAX) && !isinf(value)){
		std::cerr << "Input error: not a valid double\n";
		return ;
	}
	std::cout << std::showpoint;
	std::cout << "\nCONVERT double: " << value << std:: endl;
	std::cout << "        float:  " << static_cast<float>(value) << "f" << std::endl;
	if (infiniteOrNan(value))
		return ;
	if (isprint(static_cast<char>(value)))
		std::cout << "        char:   '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "        char:   Non displayable" <<  std::endl;
	std::cout << "        int:    " << static_cast<int>(value) << std::endl;
}

void	validateInput(char *input){
	char	*pEnd;
	double	doubleValue;
	long	intValue;

	if (strlen(input) == 1 && isprint(*input) && !isdigit(*input)){
		convertChar(*input);
		return ;
	}
	intValue = strtol(input, &pEnd, BASE);
	if(*pEnd == '\0'){
		if (intValue == 0L && pEnd == input)
			inputError();
		convertInt(intValue);
		return ;
	}
	doubleValue = strtod(input, &pEnd);
	if (*pEnd == 'f' && *(pEnd + 1) == '\0')
		convertFloat(doubleValue);
	else if (*pEnd == '\0')
		convertDouble(doubleValue);
	else
		inputError();
}

int main(int argc, char **argv){
	if (argc != 2){	
		std::cerr << "Incorrect program usage\n";
		exit(EXIT_FAILURE);
	}
	validateInput(argv[1]);
}
