#include "gtest/gtest.h"
#include "../Raccoglitore.h"
#include "../Cartella.h"

class FolderSetUp : public ::testing::Test {

protected:
    void SetUp() override{
        c.createNewNote("Ciao", "Ti saluta con un ciao", false);
        c.createNewNote("Nciao", "Non ti saluto", true);
        c.createNewNote("Addio", "Ti dico addio", false);
        c.createCartella("Saluti");
        c.addNoteToFolder("Saluti", "Ciao");
    }

    Raccoglitore c;
};

TEST_F(FolderSetUp, NoteCounters){
    EXPECT_EQ(c.getCartella("Saluti")->getModNotes(), 0);
    EXPECT_EQ(c.getCartella("Saluti")->getNotmodNotes(), 1);
}