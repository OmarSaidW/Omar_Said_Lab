//
// Created by omar on 23/11/24.
//

#ifndef NOTE_SUBJECT_H
#define NOTE_SUBJECT_H


#include "Observer.h"

class Subject {
    protected:
        virtual ~Subject() {};
    public:
        virtual void addObserver( Observer* o ) = 0;
        virtual void removeObserver( Observer* o ) = 0;
        virtual void notify()  = 0;
    };


#endif //NOTE_SUBJECT_H
