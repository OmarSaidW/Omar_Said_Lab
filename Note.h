//
// Created by omar on 12/08/24.
//

#ifndef NOTE_NOTE_H
#define NOTE_NOTE_H
#include <iostream>
#include <utility>
#include "Date.h"
class Note {
private:
    std::string  Title;
    std::string Text;
    Date scadenza;
    bool Modify;

public:
    explicit Note( std::string Title = "Untitled", std::string text = " ",  bool m = true): Title(std::move(Title)), Text(std::move(text)), Modify(m),
                                                                                    scadenza(0000, 01, 01){};
// METODI SETTER E GETTER
    const std::string &getTitle() const {
        return Title;
    }

    void setTitle(const std::string &title) {
        Title = title;
    }

    const std::string &getText() const {
        return Text;
    }

    void setText(const std::string &text) {
        Text = text;
    }

    bool getModify() const {
        return Modify;
    }

    void setModify(bool modify) {
        Modify = modify;
    }

    const Date &getScadenza() const{
        return scadenza;
    }

    void setScadenza(const Date &scadenz){
        scadenza = scadenz;
    }

    bool operator == (const Note & note){ // necessario per il remove
        if(Title == note.getTitle() && Text == note.getText() && scadenza == note.getScadenza())
            return true;
        return false;
    }

    void printText(){
        std::cout <<"Titolo: " <<this->Title<< "  Testo: " <<this->getText()<< std::endl;
    }

};



#endif //NOTE_NOTE_H
