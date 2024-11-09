//
// Created by omar on 21/08/24.
//

#include "Raccoglitore.h"

//TODO implementare privacy nella ricerca modifica di cartelle

void Raccoglitore::createCartella(const std::string &titl){
    std::unique_ptr<Cartella> cartella (new Cartella (titl));
    cartelle.push_back(std::move(cartella));
}

void Raccoglitore::removeCartella(const std::string& cartellaTitle) {
    for(auto iter = cartelle.begin(); iter!=cartelle.end(); iter++)
        if((*iter)->getTitle() == cartellaTitle){
            cartelle.erase(iter);
            break;
        }
}

void Raccoglitore::removeNote(const std::string &title){

    for(auto iter = notes.begin(); iter!=notes.end(); iter++)
        if((*iter)->getTitle() == title){
            notes.erase(iter);
            break;
        }
    for(  auto & iter: cartelle)
        for( auto check = (iter->getCartella()).begin(); check!=(iter->getCartella()).end(); check++)
            if((*check)->getTitle() == title){
                (iter->getCartella()).erase(check);
                break;
            }
}

 std::shared_ptr<Note> Raccoglitore::findNote(const std::string &noteTitle) const {
    for( auto  it: notes) { //cerca tra le note generali
        if (it->getTitle() == noteTitle)
            return it;
    }
    for( const auto & it: cartelle) //cerca tra le note spefiche di ogni cartella

        for ( auto noteIteretor: it->getCartella())
            if (noteIteretor->getTitle() == noteTitle)
                return noteIteretor;
    return nullptr;
}

void Raccoglitore::printNoteText(const std::string & title) const {
    std::shared_ptr<Note> it = findNote( title);
    if(it!= nullptr)
            it->printText();
    else
        std::cout<< "La nota no è presente";
}

void Raccoglitore::printNotesTitles() const {
    for(const auto & it: notes)
            std::cout<< it->getTitle()<< std::endl;
}

void Raccoglitore::printFolderNotesTitle(const std::string &folderTitle) {
    bool count  = false;
    for(const auto & it: cartelle)
        if (it->getTitle() == folderTitle) {
            std::cout << "Dentro " << folderTitle << " sono presenti le seguenti note: " << std::endl;
            it->printNotesTitle();
            count = true;
        }
    if (! count)
        std::cout << "Non ci sono note dentro " << folderTitle << std::endl;
}
void Raccoglitore::createNewNote(const std::string &title, const std::string &text) {
        std::cout<< "Do you want to make " << title << " editable: Y/N"<< std::endl;
        std::string mod;
        std::cin>> mod;
        bool m;
        if( mod == "Y" || mod == "y")
            m  = true;
        else
            m = false;
        notes.push_back(std::make_shared<Note>(Note(title, text, m)));
}

void Raccoglitore::addNoteToFolder(const std::string &title, const std::string &noteTitle) {
    for(const auto & i: cartelle) //scorro x trovuniqueare la cartella
        if(i->getTitle() == title){
            auto iter = findNote(noteTitle);
            if(iter)
                i->addNote(iter);
        }
}

void Raccoglitore::modifyText(const std::string &newText, const std::string & noteTitle) const {
    std::shared_ptr<Note> it = findNote(noteTitle);
    if(it!= nullptr) {
        if ((it->getModify())) { //controllo che la nota sia modificabile
            it->setText(newText);
        } else {
            std::cout << "Il documento non è modificabile" << std::endl;
        }
    }
}

void Raccoglitore::setDeadLine(const std::string &noteTitle, const Date &date) {
    std::shared_ptr<Note> it = findNote( noteTitle);
    if(it!= nullptr)
            if(it->getModify())
                it->setScadenza(date);
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

void Raccoglitore::printCartelle() {
    std::cout << "Dentro sono presenti le seguenti cartelle: " << std::endl;
    for(const auto & iter: cartelle)
        std::cout << iter->getTitle()<< std::endl;
}

void Raccoglitore::setprivacy(bool pr, const std::string &folderTitle) {
    for (const auto & iter : cartelle)
        if(iter->getTitle() == folderTitle)
            iter->setPrivacy(pr);
}