//
// Created by omar on 23/11/24.
//

#ifndef NOTE_CONTROLLER_H
#define NOTE_CONTROLLER_H


#include "Model.h"
class Controller {
public:
    Controller(Model* m) : model(m) {}
    void increment();
    void decrement();
private:
    Model* model;
};


#endif //NOTE_CONTROLLER_H
