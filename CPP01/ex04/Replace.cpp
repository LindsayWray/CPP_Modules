#include "Replace.hpp"

Replace::Replace(std::string filename) 
	: _infile(filename), _outfile(filename + ".replace", std::ios_base::trunc){

	if (!_infile.is_open()){
		std::cerr << "Could not open file\n";
		exit(EXIT_FAILURE);
	}
	if (!_outfile.is_open()){
		std::cerr << "Could not open file\n";
		exit(EXIT_FAILURE);
	}
}

Replace::~Replace(void){
	_infile.close();
	_outfile.close();
}

void Replace::replace_string(std::string to_replace, std::string replacement){
	std::string file_content;

	std::getline(_infile, file_content, '\0');
	size_t pos = 0;
	size_t start = pos;
	while(true){
		start = pos;
		pos = file_content.find(to_replace, pos);
		if (pos == std::string::npos)
			break ;
		_outfile	<< file_content.substr(start, pos - start)
					<< replacement;

		pos = pos + to_replace.length();
	}
	_outfile << file_content.substr(start, pos - start);
}
