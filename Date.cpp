//
// Created by omar on 12/08/24.
//

#include "Date.h"
void Date::setMonth(int month){
    if(month>0 && month<=12){
        this->month = month;
    }
    else
        throw std::out_of_range("Insert valid values for months ( from 1 to 12) ");
}
void Date::setDay(int d){
    if(d<0)
        throw std::invalid_argument("Impossible: negative day");

    switch (month) {
        case 4:
        case 6:
        case 9:
        case 11:
            if(d>30)
                throw std::out_of_range("Insert valid day (under 28)");
            else
                this->day = d;
        case 2:
            if((year%100 && year%400) or ((year%100)!=0 && year%4)){
                if(d>29)
                    throw std::out_of_range("Insert valid day (under 29)");
                else
                    this->day = d;}

            if(d>28)
                throw std::out_of_range("Insert valid day (under 28)");
            else
                this->day = d;

        default:
            if(d>31)
                throw std::out_of_range("Insert valid day (under 31)");
            else
                this->day = d;

    }
}
