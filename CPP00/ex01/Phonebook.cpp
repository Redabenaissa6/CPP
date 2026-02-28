#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : count(0), oldest(0) {} //  Initialize list

void PhoneBook::addContact(Contact contact) {
    contacts[oldest] = contact;
    oldest = (oldest + 1) % 8;  // Wrap around after 8
    if (count < 8)
        count++;
}

// Helper to print a column (truncate if > 10 chars, right-align)
static void printColumn(const std::string &str) {
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << str;
}

void PhoneBook::searchContact() const {
    if (count == 0) {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
          << std::setw(10) << "First Name" << "|"
          << std::setw(10) << "Last Name" << "|"
          << std::setw(10) << "Nickname" << "\n";
    // Print the table
    for (int i = 0; i < count; i++) {
        std::cout << std::setw(10) << i << "|";
        printColumn(contacts[i].getFirstName()); std::cout << "|";
        printColumn(contacts[i].getLastName());  std::cout << "|";
        printColumn(contacts[i].getNickname());  std::cout << std::endl;
    }

    // Ask for index
    std::cout << "Enter index: ";
    int index;
    if (!(std::cin >> index))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index\n";
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (std::cin.fail() || index < 0 || index >= count) {
        std::cin.clear();
        std::cout << "Invalid index." << std::endl;
        return;
    }

    // Display full contact info
    std::cout << "First name:     " << contacts[index].getFirstName()     << std::endl;
    std::cout << "Last name:      " << contacts[index].getLastName()      << std::endl;
    std::cout << "Nickname:       " << contacts[index].getNickname()      << std::endl;
    std::cout << "Phone number:   " << contacts[index].getPhoneNumber()   << std::endl;
    std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}
