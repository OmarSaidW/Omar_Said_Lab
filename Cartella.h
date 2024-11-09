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
    bool privacy;

public:
    explicit Cartella(std::string Title = "Untitled"):Title(std::move(Title)), privacy(false){};

    void addNote(std::shared_ptr<Note> note);

    void removeNote(const std::string &noteTitle);

    void removeNotePtr (std::shared_ptr<Note> ptr);

    std::list<std::shared_ptr<Note>> & getCartella();

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    void printNotesTitle();

    const std::shared_ptr<Note> & findNote (const std::string & noteTitle);

    bool isPrivacy() const {
        return privacy;
    }

    void setPrivacy(bool pr) {
        Cartella::privacy = pr;
    }
};


#endif //NOTE_CARTELLA_H
