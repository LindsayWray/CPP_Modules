#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>
#include <iostream>
#include <fstream>

class Replace{
public:
	void	replace_string(std::string to_replace, std::string replacement);

	Replace(std::string filename);
	~Replace(void);
private:
	std::ifstream _infile;
	std::ofstream _outfile;
};

#endif
