//
// Created by omar on 23/11/24.
//

#ifndef NOTE_OBSERVER_H
#define NOTE_OBSERVER_H


class Observer {
    protected:
        virtual ~Observer() {};
    public:
        virtual void update(float temp, float humidity, float pressure) = 0;
};


#endif //NOTE_OBSERVER_H
