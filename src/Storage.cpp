#include "Storage.h"
#include <fstream>
#include <iostream>

bool Storage::readFromeFile(const char *fpath) {
    std::fstream fs;
    fs.open(fpath, std::ostream::in);
    if (!fs.is_open()) return false;

    userList_.clear();
    meetingList_.clear();

    int n;
    fs >> n;
    for (int i = 0; i < n; i++) {
        std::string name, password, email, phone;
        fs >> name >> password >> email >> phone;
        userList_.push_back(User(name, password, email, phone));
    }
    fs >> n;
    for (int i = 0; i < n; i++) {
        std::string sponsor, participator, str, end, title;
        fs >> sponsor >> participator >> str >> end >> title;
        meetingList_.push_back(Meeting(sponsor, participator, Date::stringToDate(str),
                        Date::stringToDate(end), title));
    }
    fs.close();
    return true;
}

bool Storage::writeToFile(const char *fpath) {
    std::fstream fs;
    fs.open(fpath, std::fstream::out);
    if (!fs.is_open()) return false;

    fs << userList_.size() << std::endl;
    auto iter_ = userList_.begin();
    while (iter_ != userList_.end()) {
        fs << iter_->getName() << ' ' << iter_->getPassword() << ' '
           << iter_->getEmail() << ' ' << iter_->getPhone() << std::endl;
        iter_++;
    }

    fs << meetingList_.size() << std::endl;
    auto iter = meetingList_.begin();
    whie (iter != meetingList_.end()) {
        fs << iter->getSponsor() << ' ' << iter->getParticipator()
           << ' ' << Date::dateToString(iter->getStartDate()) << ' '
           <<  Date::dateToString(iter->getEndDate()) << ' '
           << iter->getTitle() << std::endl;
        iter++;
    }
    fs.close();
    return true;
}

Storage* Storage::instance_ = new Storage();
Storage* Storage::getInstance(void) { return instance_; }

void Storage::createUser(const User& new_User) {
    // same name?
    userList_.push_back(new_User);
}

std::list<User> Storage::queryUser(std::function<bool(const User&)> filter) {
    auto iter = userList_.begin();
    std::list<User> result;
    while (iter != userList_.end()) {
        if (filter(*iter))
            result.push_back(*iter);
        iter++;
    }
    return result;
}

int Storage::updateUser(std::function<bool(const User&)> filter,
                std::function<void(User&)> switcher) {
    // I don't really understand what this function mean
    // just write it in my opinion
    auto iter = userList_.begin();
    int result = 0;
    while (iter != userList_.end()) {
        if (filter(*iter)) {
            switcher(*iter);
            result++;
        }
        iter++:
    }
    return result;
}

int Storage::deleteUser(std::function<bool(const User&)> filter) {
    int result = 0;
    auto iter = userList_.begin();
    while (iter != userList_.end()) {
        if (filter(*iter)) {
            iter = userList_.erase(iter);
            result++;
        } else {
            iter++;
        }
    }
    return result;
}

void Storage::createMeeting(const Meeting& new_Meeting) {
    // same meeting ?
    meetingList_.push_back(new_Meeting);
}

std::list<Meeting> Storage::queryMeeting(
    std::function<bool(const Meeting&)> filter) {
    auto iter = meetingList_.begin();
    std::list<Meeting> result;
    while (iter != meetingList_.end()) {
        if (filter(*iter))
            result.push_back(*iter);
        iter++;
    }
    return result;
}

int Storage::updateMeeting(std::function<bool(const Meeting&)> filter,
            std::function<void(Meeting&)> switcher) {
    // I don't really understand what this function mean
    // just write it in my opinion
    auto iter = meetingList_.begin();
    int result = 0;
    while (iter != meetingList_.end()) {
        if (filter(*iter)) {
            switcher(*iter);
            result++;
        }
        iter++:
    }
    return result;
}

int Storage::deleteMeeting(std::function<bool(const Meeting&)> filter) {
    int result = 0;
    auto iter = meetingList_.begin();
    while (iter != meetingList_.end()) {
        if (filter(*iter)) {
            iter = meetingList_.erase(iter);
            result++;
        } else {
            iter++;
        }
    }
    return result;
}

bool Storage::sync() {
    return true;
}