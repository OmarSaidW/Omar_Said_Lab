//
// Created by omar on 30/08/24.
//

#ifndef NOTE_CARTELLA_H
#define NOTE_CARTELLA_H
#include "Note.h"
#include <list>
#include <memory>
class Cartella {
private:
    std::string Title;
    std::list<std::shared_ptr<Note>> cartella;
    unsigned int modNotes =0;
    unsigned int notmodNotes = 0;

public:
    explicit Cartella(std::string Title = "Untitled" ):Title(std::move(Title)){};

    void addNote(std::shared_ptr<Note> note);

    std::list<std::shared_ptr<Note>> & getCartella();

    const std::shared_ptr<Note> findnote(const std::string &noteTitle) const;

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    std::string printNotes(std::string Notes = " ") const;

    void removeNote ( const std::string & noteTitle);

    unsigned int getModNotes() const {
        return modNotes;
    }

    unsigned int getNotmodNotes() const {
        return notmodNotes;
    }

};


#endif //NOTE_CARTELLA_H
