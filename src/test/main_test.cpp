#include "Tests.h" // Includes gtest/gtest.h and "../Manager.h"
#include <string>

using namespace ClassProject;

// Define the Test Fixture class
class ManagerTest : public ::testing::Test {
protected:
    // This assumes the Manager class is defined and inherits ManagerInterface
    // Make sure Manager.h is updated to define the concrete class:
    // class Manager : public ManagerInterface {...};
    Manager manager;

    // These constants are defined by the BDD specification (0 for False, 1 for True)
    const BDD_ID FALSE_ID = 0;
    const BDD_ID TRUE_ID = 1;

    void SetUp() override {
        // Assert that the terminal nodes are set up correctly upon construction.
        // The unique table must contain False (0) and True (1) immediately.
        ASSERT_EQ(manager.uniqueTableSize(), 2);
    }
};

// Inside main_test.cpp, after the ManagerTest class definition

TEST_F(ManagerTest, TerminalNodes_AreCorrectlyInitialized) {
    // 1. Check if the returned IDs match the specification (0 and 1)
    EXPECT_EQ(manager.False(), FALSE_ID);
    EXPECT_EQ(manager.True(), TRUE_ID);

    // 2. Check if the terminal nodes are correctly identified as constants
    EXPECT_TRUE(manager.isConstant(FALSE_ID));
    EXPECT_TRUE(manager.isConstant(TRUE_ID));

    // 3. Check that terminal nodes are NOT variables
    EXPECT_FALSE(manager.isVariable(FALSE_ID));
    EXPECT_FALSE(manager.isVariable(TRUE_ID));

    // 4. Check initial size
    EXPECT_EQ(manager.uniqueTableSize(), 2);
}

// ... Your tests will go here ...

// main function for tests (typically handled by main_test.cpp or gtest setup)
// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }