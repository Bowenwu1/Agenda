#include "User.h"

User::User() {}
User::User(std::string userName, std::string userPassword, 
            std::string userEmail, std::string userPhone) {
                //
                name_ = userName;
                //
                password_ = userPassword;
                //
                email_ = userEmail;
                //
                phone_ = userPhone;
            }
std::string User::getName() const { return name_; }
void User::setName(std::string n) { name_ = n; }

std::string User::getPassword() const { return password_; }
void User::setPassword(std::string p) { password_ = p; }

std::string User::getEmail() const { return email_; }
void User::setEmail(std::string e) { email_ = e; }

std::string User::getPhone() const { return phone_; }
void User::setPhone(std::string p) { phone_ = p; }
