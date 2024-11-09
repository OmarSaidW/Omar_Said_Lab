//
// Created by omar on 21/08/24.
//

#ifndef NOTE_RACCOGLITORE_H
#define NOTE_RACCOGLITORE_H
#include "Note.h"
#include "Date.h"
#include "Cartella.h"
#include <list>
#include <memory>
class Raccoglitore {
private:
     //shared pointer cosi da poter essere puntati sia da dentro una crtella che da questa lista
    std::list<std::unique_ptr<Cartella>> cartelle;
    std::list<std::shared_ptr<Note>> notes;

public:

    void createCartella (const std::string &  title);

    void removeCartella( const std::string & CartellaTitle);

    void setprivacy(bool pr, const std::string &FolderTitle);

    void printCartelle ();

    void createNewNote(const std::string &title, const std::string &text);

    void removeNote (const std::string &title);

    std::shared_ptr<Note> findNote (const std::string & noteTitle) const;

    void addNoteToFolder(const std::string &folderTitle, const std::string &noteTitle);

    void printNotesTitles() const;

    void printFolderNotesTitle(const std::string &folderTitle);

    void printNoteText(const std::string &  title) const;

    void modifyText ( const std:: string& newText, const std::string & noteTitle) const;

    void modifyTitle ( const std:: string& newTitle, const std::string & noteTitle);

    void setDeadLine (const std::string & noteTitle, const Date & date);


    //TODO: Inserire una funziona che permetta di modificare gli attributi di una nota dando un titolo e un l'attributo da modfificare
    //Facolatativo: Cartella Privata da sbloccare con password
};


#endif //NOTE_RACCOGLITORE_H
