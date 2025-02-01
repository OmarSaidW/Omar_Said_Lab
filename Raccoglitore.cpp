//
// Created by omar on 21/08/24.
//

#include "Raccoglitore.h"


void Raccoglitore::createCartella(const std::string &titl){
    std::unique_ptr<Cartella> cartella (new Cartella (titl));
    cartelle.push_back(std::move(cartella));
}

void Raccoglitore::removeNote(const std::string &title){
    for(auto iter = notes.begin(); iter!=notes.end(); iter++)
        if((*iter)->getTitle() == title){
            if((*iter)->getModify())
                modNotes--;
            else
                notModNotes--;
            notes.erase(iter);
            break;
        }
    for(  auto & iter: cartelle)
        iter->removeNote(title);
}

 const std::shared_ptr<Note> & Raccoglitore::findNote(const std::string &noteTitle) const {
    for( auto & it: notes)//cerca tra le note generali
        if (it->getTitle() == noteTitle)
            return it;

    for( const auto & it: cartelle) {
        const std::shared_ptr<Note> & note = it->findnote(noteTitle); //usa il find note in cartella
        if (note != nullptr)
            return note;
    }

    static std:: shared_ptr<Note> not_found = nullptr;
    return not_found;
}


void Raccoglitore::printFolderNotes(const std::string &folderTitle, std::string &output) {
    std::string titles;
    output = "Cartella non trovata";
    for(const auto & it: cartelle)
        if (it->getTitle() == folderTitle)
            output = it->printNotes();
}

void Raccoglitore::printRaccoglitoreNotes(std::string &output) {
    for(const auto & it: notes)
        output += "Titolo: " +  it->getTitle() + "\n" +  "Testo: " + it->getText() + "\n\n";
}

void Raccoglitore::createNewNote(const std::string &title, const std::string &text, bool modifiable) {
    if(modifiable)
        modNotes++;
    else
        notModNotes++;

    notes.push_back(std::make_shared<Note>(Note(title, text,  modifiable)));
}

void Raccoglitore::addNoteToFolder(const std::string &title, const std::string &noteTitle) {
    for(const auto & i: cartelle) //scorro x trovuniqueare la cartella
        if(i->getTitle() == title){
            auto iter = findNote(noteTitle);
            if(iter)
                i->addNote(iter);
        }
}

void Raccoglitore::modifyText(const std::string &newText, const std::string &noteTitle, std::string &result) const {
    std::shared_ptr<Note> it = findNote(noteTitle);
    if(it!= nullptr) {
        if ((it->getModify())) { //controllo che la nota sia modificabile
            it->setText(newText);
            result = "Testo modificato con successo";
        } else {
            result = "Il documento non è modificabile";
        }
    }else
        result = "Il documento non è presente";
}

void Raccoglitore::modifyTitle(const std::string &newTItle, const std::string &noteTitle) {
    std::shared_ptr<Note> it = findNote(noteTitle);
    if(it!= nullptr) {
        if ((it->getModify())) {
            it->setText(newTItle);
        } else {
            std::cout << "Il documento non è modificabile" << std::endl;
        }
    } else
        std::cout<< "Il documento non è presente";
}

const std::string & Raccoglitore ::printNoteText(const std::string title) {
    return (findNote(title)->getText());
}

const std::unique_ptr<Cartella> & Raccoglitore::getCartella(const std::string folderTitle) const {
    for(const auto & iter: cartelle)
        if (iter->getTitle() == folderTitle)
            return iter;
    static std::unique_ptr<Cartella> not_found = nullptr;
    return not_found;
}

