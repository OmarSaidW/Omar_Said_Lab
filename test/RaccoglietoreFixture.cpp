//
// Created by omar on 09/11/24.
//
#include "gtest/gtest.h"
#include "../Raccoglitore.h"

class RaccoglitoreSetUp : public ::testing::Test {

protected:
    void SetUp() override{
        c.createNewNote("Ciao", "Ti saluta con un ciao");
    }

    Raccoglitore c;
};

TEST_F(RaccoglitoreSetUp, NoMemoryLeaks) {
    unsigned int initialUseCount = c.findNote("Ciao").use_count();
    ASSERT_EQ(c.findNote("Ciao").use_count(),  1);
    c.removeNote("Ciao"); // Libera il puntatore "Ciao"
    EXPECT_EQ(c.findNote("Ciao").use_count(), initialUseCount - 1);
}

