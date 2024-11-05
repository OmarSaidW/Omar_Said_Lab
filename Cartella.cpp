//
// Created by omar on 30/08/24.
//

#include "Cartella.h"
void Cartella::addNote(std::shared_ptr<Note> note) {
    cartella.push_back(note);
}
void Cartella::removeNote( std::string noteTitle) {
    for (  auto &it : cartella) {
        if (it->getTitle() == noteTitle)
            cartella.remove(it);
    }
}
void Cartella::removeNotePtr(std::shared_ptr<Note> ptr) {
    for (auto it = cartella.begin();it != cartella.end(); it++) {
        if ((*it)->getTitle() == ptr->getTitle())
            cartella.remove(ptr);
    }
}




const std::string &Cartella::getTitle() const {
    return Title;
}

void Cartella::setTitle(const std::string &title) {
    Title = title;
}

void Cartella::printNotesTitle() {
    for(const auto & i: cartella)
        std::cout << i->getTitle()<< std::endl;
}



const std::shared_ptr<Note> & Cartella::findNote(const std::string &noteTitle) {
    for(const auto & it: cartella) {
        if (it->getTitle() == noteTitle)
            return it;
    }
    return nullptr;
}

std::list<std::shared_ptr<Note>> & Cartella::getCartella() {
    return cartella;
}
