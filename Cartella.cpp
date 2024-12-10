//
// Created by omar on 30/08/24.
//

#include "Cartella.h"
void Cartella::addNote(std::shared_ptr<Note> note) {
    cartella.push_back(note);
}

const std::string &Cartella::getTitle() const {
    return Title;
}

void Cartella::setTitle(const std::string &title) {
    Title = title;
}

std::string Cartella::printNotes(std::string Notes) const {
    for(const auto & i: cartella)
        Notes += "Titolo: " +  i->getTitle() + "\n" +  "Testo: " + i->getText() + "\n\n";
    return Notes;
}



std::list<std::shared_ptr<Note>> & Cartella::getCartella() {
    return cartella;
}
