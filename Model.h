//
// Created by omar on 23/11/24.
//

#ifndef NOTE_MODEL_H
#define NOTE_MODEL_H
#include "Subject.h"
#include <list>
class Model: public Subject {

    public:
        int getData() const {
            return data;
        }
        void setData(const int i);
        virtual void addObserver(Observer* o) override;
        virtual void removeObserver(Observer* o) override;
        virtual void notify() override;
    private:
        int data = 0;
        std::list<Observer*> observers;
};


#endif //NOTE_MODEL_H
