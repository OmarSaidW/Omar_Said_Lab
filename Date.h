//
// Created by omar on 12/08/24.
//

#ifndef NOTE_DATE_H
#define NOTE_DATE_H

#include <exception>
#include <stdexcept>
#include "iostream"
class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(int y, int m, int d){
        setYear(y);
        setMonth(m);
        setDay(d);
    }
    Date(const Date& d){
        setYear(d.year);
        setMonth(d.month);
        setDay(d.day);
    }
    Date& operator = (const Date & d){
        if(this != &d) {
            setYear(d.year);
            setMonth(d.month);
            setDay(d.day);
        }
        return *this;
    }
    bool operator == (const Date & data) const { // necessario per operator == di notes
        if (day == data.getDay() && month == data.getMonth() && year == data.getYear())
            return true;
        return false;
    }
    int getDay() const {
        return day;}

    void setDay(int day);

    int getMonth() const {
        return month;}

    void setMonth(int month);

    int getYear() const {
        return year;}

    void setYear(int year) {
        this->year = year;}

    void printDate() const{
        std::cout<< day << "/" << month << "/" << year << std::endl;
    };
};


#endif //NOTE_DATE_H
