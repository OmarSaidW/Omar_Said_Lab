#include <iostream>
#include <SFML/Graphics.hpp>
#include "Raccoglitore.h"

//Fare in modo che la nota sia creabile solo tramite il raccoglitore, non vogliamo note libere a giro
// Fattibile tramite Factory Pattern CREDO; NON SONO SICURO.
int main() {

    Date Giorno(2012, 2, 28);
    Giorno.printDate();
    Raccoglitore iphoneNotes;
    iphoneNotes.createNewNote("Spesa", "Burro, sale, pepe, latte");
    iphoneNotes.createNewNote("Esami", "FRO, Calcolatori, Algoritmi e Strutture dati");
    iphoneNotes.createCartella("Personale");
    iphoneNotes.addNoteToFolder("Personale", "Spesa");
    iphoneNotes.printFolderNotesTitle("Personale");
    iphoneNotes.printNoteText("Esami");
    iphoneNotes.modifyText("olio sale e pepe", "Spesa");

    iphoneNotes.printNoteText("Spesa");
    iphoneNotes.printCartelle();


    iphoneNotes.removeNote("Spesa");
    iphoneNotes.printFolderNotesTitle("Personale");
    iphoneNotes.printNoteText("Spesa");


// wxWidgets macro to declare and implement the application
    //TODO wxIMPLEMENT_APP(MyApp);
    // in modo tale da poter visualizzare le cartelle, le noti e le scadenze

    return 0;
}
