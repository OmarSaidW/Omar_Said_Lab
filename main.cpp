#include <iostream>
#include "Raccoglitore.h"

//Fare in modo che la nota sia creabile solo tramite il raccoglitore, non vogliamo note libere a giro
// Fattibile tramite Factory Pattern CREDO; NON SONO SICURO.
int main() {

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
    

    return 0;
}
