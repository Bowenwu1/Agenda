#include "Storage.h"
#include <fstream>

bool Storage::readFromeFile(const char *fpath) {
    std::istream 
}

bool Storage::writeToFile(const char *fpath) {

}

Storage* Storage::instance_ = new Storage();
Storage* Storage::getInstance(void) { return instance_; }

void Storage::createUser(const User& new_User) {
    // same name?
    userList_.push_back(new_User);
}

std::list<User> Storage::queryUser(std::function<bool(const User&)> filter) {

}

int Storage::updateUser(std::function<bool(const User&)> filter,
                std::function<void(User&)> switcher) {
    
}

int Storage::deleteUser(std::function<bool(const User&)> filter) {

}

void Storage::createMeeting(const Meeting& new_Meeting) {

}

std::list<Meeting> Storage::queryMeeting(
    std::function<bool(const Meeting&)> filter) {

}

int Storage::updateMeeting(std::function<bool(const Meeting&)> filter,
            std::function<void(Meeting&)> switcher) {

}

int Storage::deleteMeeting(std::function<bool(const Meeting&)> filter) {

}

bool Storage::sync() {
    
}