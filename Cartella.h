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
    explicit Cartella(std::string Title = "Untitled" , bool m = false):Title(std::move(Title)), privacy(m){};

    void addNote(std::shared_ptr<Note> note);

    std::list<std::shared_ptr<Note>> & getCartella();

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    void printNotesTitle();

    bool isPrivacy() const {
        return privacy;
    }

    void setPrivacy(bool pr) {
        Cartella::privacy = pr;
    }
};


#endif //NOTE_CARTELLA_H
