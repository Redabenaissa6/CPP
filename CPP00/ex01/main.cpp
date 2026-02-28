#include "Phonebook.hpp"

int main() {
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            Contact newContact;
            std::string input;

            std::cout << "First Name: ";
            std::getline(std::cin, input);
            newContact.setFirstName(input);

            std::cout << "Last Name: ";
            std::getline(std::cin, input);
            newContact.setLastName(input);

            std::cout << "Nickname: ";
            std::getline(std::cin, input);
            newContact.setNickname(input);

            std::cout << "Phone Number: ";
            std::getline(std::cin, input);
            newContact.setPhoneNumber(input);

            std::cout << "Darkest Secret: ";
            std::getline(std::cin, input);
            newContact.setDarkestSecret(input);

            phonebook.addContact(newContact);
        } else if (command == "SEARCH") {
            phonebook.searchContact();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }

    return 0;
}