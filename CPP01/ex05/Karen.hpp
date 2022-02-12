#ifndef KAREN_H
#define KAREN_H
#include <string>
#include <iostream>

class Karen{
private:
	typedef void(Karen::*t_func)(void); // t_func is an alias for a ptr to a function in the class Karen that takes void and returns void

	typedef struct s_log{
		std::string level;
		t_func func_ptr;
	} t_log;

private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

	t_log	_log_table[4];
	
public:
	void complain(std::string level);

	Karen(void);
	~Karen(void);
};

#endif
