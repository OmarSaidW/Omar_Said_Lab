
#include "gtest/gtest.h"
#include "../Raccoglitore.h"

class RaccoglitoreSetUp : public ::testing::Test {

protected:
    void SetUp() override{
        c.createNewNote("Ciao", "Ti saluta con un ciao", false);
        c.createNewNote("Nciao", "Non ti saluto", true);
        c.createNewNote("Addio", "Ti dico addio", false);
    }

    Raccoglitore c;
};
class RaccoglitoreFindNote : public ::testing::Test {

protected:
    void SetUp() override{
        c.createNewNote("Ciao", "Ti saluta con un ciao", false);
    }

    Raccoglitore c;
};


TEST_F(RaccoglitoreSetUp, NoMemoryLeaks) { // Verifica che non ci siano memory leaks
    unsigned int initialUseCount = c.findNote("Ciao").use_count();
    ASSERT_EQ(c.findNote("Ciao").use_count(),  1);
    c.removeNote("Ciao"); // Libera il puntatore "Ciao"
    EXPECT_EQ(c.findNote("Ciao").use_count(), initialUseCount - 1); //verica eventuali memory leaks durante l'eliminazione di una nota
}



TEST_F(RaccoglitoreSetUp, ModifyNotes){
    std::string nciao = "";
    c.modifyText( "Ancora non ti saluto", "Nciao", nciao);
    EXPECT_EQ(nciao, "Testo modificato con successo"); //Verifica che modifichi effettivamente una nota modificata
    EXPECT_EQ(c.printNoteText("Nciao"), "Ancora non ti saluto");
    std::string ciao = "";
    c.modifyText("Ora ti saluto subito", "Ciao", ciao);
    EXPECT_EQ(ciao, "Il documento non è modificabile"); //Verifica che non modifichi un documento non modificabile
    EXPECT_EQ(c.printNoteText("Ciao"), "Ti saluta con un ciao");
    std::string nhere = "";
    c.modifyText("Testiamo per una nota non presente", "Nhere", nhere); //Testa il caso in cui una nota non moddificabile
    EXPECT_EQ(nhere, "Il documento non è presente");
}

TEST_F(RaccoglitoreFindNote, findNoteTest) {  // Verifica che la funzione findNote funzioni correttamente
    EXPECT_EQ(c.findNote("Pippo"), nullptr);
}

TEST_F(RaccoglitoreSetUp, NoteCounters){
    EXPECT_EQ(c.getModNotes(), 1);
    EXPECT_EQ(c.getNotModNotes(), 2);
    EXPECT_EQ(c.getNotModNotes() + c.getModNotes(), 3);
    c.removeNote("Ciao");
    EXPECT_EQ(c.getNotModNotes(), 1);
    EXPECT_EQ(c.getNotModNotes() + c.getModNotes(), 2);
    c.removeNote("Amami");
    EXPECT_EQ(c.getNotModNotes() + c.getModNotes(), 2);
}


