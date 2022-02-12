#ifndef KAREN_H
#define KAREN_H
#include <string>
#include <iostream>

#define NO_LEVEL -1
#define DEBUG 0
#define INFO 1
#define WARNING	2
#define ERROR 3

class Karen{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	static int match_case(std::string level);
	
public:
	void complain(std::string level);

	Karen(void);
	~Karen(void);
};

#endif
