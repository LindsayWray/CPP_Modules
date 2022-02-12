#include "Phonebook.hpp"

void process_input(std::string query, std::string& field){
	while(true){
		std::cout << CYAN << query << DEF << std::endl;
		std::getline(std::cin, field);
		if (std::cin.eof())
			exit(EXIT_SUCCESS);
		if (field != "")
			return ;
		std::cout << "Field cannot be void" << std::endl;
	}
}

Contact	add_new_entry(){
	Contact new_contact;
	std::string user_input;

	std::cout << MAGENTA << "You'd like to add a new contact to this awesome phonebook" << DEF << std::endl;
	std::cout << "Please fill out the following details:" << std::endl;
	process_input("Enter first name:", new_contact.first_name);
	process_input("Enter last name:", new_contact.last_name);
	process_input("Enter nickname:", new_contact.nickname);
	process_input("Enter phone number:", new_contact.phone_number);
	process_input("Enter a deep dark secret:", new_contact.secret);
	std::cout << MAGENTA << "The new contact has been added to this awesome phonebook" << DEF << std::endl;
	return (new_contact);
}
std::string crop_string(std::string str){
	if (str.length() > 10){
		return (str.substr(0,9) + ".");
	}
	return (str);
}

void	search_phonebook(PhoneBook phonebook, int counter){
	int i;
	int index;
	std::string  user_input;

	if (counter == 0){
		std::cout << "\nThe phonebook is currently empty" << std::endl << std::endl;
		return ;
	}
	std::cout << MAGENTA << "\nOverview Contacts" << DEF << std::endl;
	std::cout << "           | Firstname|  Lastname|  Nickname" << std::endl;
	for (i = 0; i < counter && i < 8; i++){
		std::cout << std::setw(10) << "index " << (i + 1) << "|";
		std::cout << std::setw(10) << crop_string(phonebook.contact_list[i].first_name)  << "|";
		std::cout << std::setw(10) << crop_string(phonebook.contact_list[i].last_name) << "|";
		std::cout << std::setw(10) << crop_string(phonebook.contact_list[i].nickname) << std::endl;
	}
	while (true){
		std::cout << MAGENTA << "\nSelect an index to view the corresponding contact's information" << DEF << std::endl;
		std::getline(std::cin, user_input);
		if (std::cin.eof())
			exit(EXIT_SUCCESS);
		index = std::atoi(user_input.c_str());
		if (index > 0 && index <= counter && index <= 8)
			break;
		std::cout << "\nNot a valid index number" << std::endl;
	}
	std::cout << phonebook.contact_list[index - 1].first_name << std::endl;
	std::cout << phonebook.contact_list[index - 1].last_name << std::endl;
	std::cout << phonebook.contact_list[index - 1].nickname << std::endl;
	std::cout << phonebook.contact_list[index - 1].phone_number << std::endl;
	std::cout << phonebook.contact_list[index - 1].secret << std::endl << std::endl;
}

int main(){
	PhoneBook phonebook;
	std::string user_input;
	int counter = 0;

	std::cout << MAGENTA << "\nThank you for using my crappy awesome phonebook software." << DEF << std::endl;
	while(true){
		std::cout << "If you wish to add a contact, type" << CYAN << " ADD" << DEF << std::endl;
		std::cout << "If you wish to search the phonebook, type" << CYAN << " SEARCH" << DEF << std::endl;
		std::cout << "If you'd like to exit, type" << CYAN << " EXIT "  << DEF << std::endl;
		std::getline(std::cin, user_input);
		if (std::cin.eof())
			return (0);
		if (user_input == "ADD"){
			phonebook.contact_list[counter % 8] = add_new_entry();
			counter++;
		}
		if (user_input == "SEARCH")
			search_phonebook(phonebook, counter);
		if (user_input == "EXIT")
			return (0);
	}
	return (0);
}