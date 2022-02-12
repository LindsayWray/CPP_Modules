#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#define CYAN "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define DEF "\033[1;39m"


class PhoneBook
{
public:
	Contact contact_list[8];
};

#endif