//
// Created by omar on 30/08/24.
//

#include "Cartella.h"
void Cartella::addNote(std::shared_ptr<Note> note) {
    if(note->getModify())
        modNotes++;
    else
        notmodNotes++;
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

const std::shared_ptr<Note> Cartella ::findnote(const std::string &noteTitle) const {
    for( auto & it: cartella)//cerca tra le note di una cartella
        if (it->getTitle() == noteTitle)
            return it;
    return nullptr;
}

void Cartella::removeNote(const std::string &noteTitle) {
    for( auto iter = cartella.begin(); iter!=cartella.end(); iter++)//cerca tra le note di una cartella
        if ((*iter)->getTitle() == noteTitle){
            if((*iter)->getModify())
                modNotes--;
            else
                notmodNotes--;
            cartella.erase(iter);
            break;
        }

}

