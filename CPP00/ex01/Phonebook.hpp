#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
private:
    Contact contacts[8];  // Max 8, NO dynamic allocation
    int     count;        // How many contacts stored so far
    int     oldest;       // Index of the oldest contact (for replacement)

public:
    PhoneBook();
    void addContact(Contact contact);
    void searchContact() const;
};

#endif