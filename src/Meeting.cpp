#include "Meeting.h"
#include <string>

Meeting::Meeting() {}
Meeting::Meeting(std::string sponsor, std::string pa,
                Date startTime, Date endTime, std::string title) {
                    sponsor_ = sponsor;
                    participator_ = pa;
                    startDate_ = startTime;
                    endDate_ = endTime;
                    title_ = title;
                }

std::string Meeting::getSponsor() const { return sponsor_; }
void Meeting::setSponsor(std::string sponsor) {sponsor_ = sponsor; }

std::string Meeting::getParticipator() const { return participator_; }
void Meeting::setParticipator(std::string pa) { participator_ = pa; }

Date Meeting::getStartDate() const { return startDate_; }
void Meeting::setStartDate(Date start) { startDate_ = start; }

Date Meeting::getEndDate() const { return endDate_; }
void Meeting::setEndDate(Date end) { endDate_ = end; }

std::string Meeting::getTitle() const { return title_; }
void Meeting::setTitle(std::string title) { title_ = title; }
