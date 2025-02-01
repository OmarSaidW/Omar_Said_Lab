//
// Created by omar on 21/08/24.
//

#ifndef NOTE_RACCOGLITORE_H
#define NOTE_RACCOGLITORE_H
#include "Note.h"

#include "Cartella.h"
#include <list>
#include <memory>
class Raccoglitore {
private:
     //shared pointer cosi da poter essere puntati sia da dentro una crtella che da questa lista
    std::list<std::unique_ptr<Cartella>> cartelle;
    std::list<std::shared_ptr<Note>> notes;
    unsigned int modNotes =0;
    unsigned int notModNotes =0;

public:

    void createCartella (const std::string &  title);

    void createNewNote(const std::string &title, const std::string &text, bool modifiable = true);

    void removeNote (const std::string &title);

    const std::shared_ptr<Note> & findNote (const std::string & noteTitle) const;

    void addNoteToFolder(const std::string &folderTitle, const std::string &noteTitle);

    void printFolderNotes(const std::string &folderTitle, std::string &output);

    void printRaccoglitoreNotes(std::string &output);

    void modifyText(const std::string &newText, const std::string &noteTitle, std::string &result) const;

    void modifyTitle ( const std:: string& newTitle, const std::string & noteTitle);

    const unsigned int getNotModNotes() const {
        return notModNotes;
    }

    const unsigned int getModNotes() const {
        return modNotes;
    }

    const std::string & printNoteText ( const std::string title);

    const std::list<std::unique_ptr<Cartella>> &getCartelle() const {
        return cartelle;
    }

    const std::unique_ptr<Cartella> & getCartella(const std::string folderTitle) const;

};


#endif //NOTE_RACCOGLITORE_H
