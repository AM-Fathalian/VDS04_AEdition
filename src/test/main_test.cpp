#include "Tests.h" // Includes gtest/gtest.h and "../Manager.h"
#include <string>

using namespace ClassProject;

// Define the Test Fixture class
class ManagerTest : public ::testing::Test {
protected:
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


TEST_F(ManagerTest, False_Node_ID) {
    std::cout << "Testing False() returns " << FALSE_ID << std::endl;
    BDD_ID result = manager.False();
    std::cout << "False() returned: " << result << std::endl;
    EXPECT_EQ(result, FALSE_ID);
}

TEST_F(ManagerTest, True_Node_ID) {
    std::cout << "Testing True() returns " << TRUE_ID << std::endl;
    BDD_ID result = manager.True();
    std::cout << "True() returned: " << result << std::endl;
    EXPECT_EQ(result, TRUE_ID);
}

TEST_F(ManagerTest, IsConstant_PositiveChcek) {
    std::cout << "Testing isConstant for TRUE_ID and FALSE_ID" << std::endl;
    std::cout << "isConstant(TRUE_ID): " << manager.isConstant(TRUE_ID) << std::endl;
    std::cout << "isConstant(FALSE_ID): " << manager.isConstant(FALSE_ID) << std::endl;
    EXPECT_TRUE(manager.isConstant(TRUE_ID));
    EXPECT_TRUE(manager.isConstant(FALSE_ID));
}

TEST_F(ManagerTest, IsVariable_NegativeCheck) {
    std::cout << "Testing isVariable returns false for constants" << std::endl;
    std::cout << "isVariable(TRUE_ID): " << manager.isVariable(TRUE_ID) << std::endl;
    std::cout << "isVariable(FALSE_ID): " << manager.isVariable(FALSE_ID) << std::endl;
    EXPECT_FALSE(manager.isVariable(TRUE_ID));
    EXPECT_FALSE(manager.isVariable(FALSE_ID));
}

TEST_F(ManagerTest, UniqueTableSize_InitializesToTwo) {
    std::cout << "Testing uniqueTableSize() == 2" << std::endl;
    size_t size = manager.uniqueTableSize();
    std::cout << "uniqueTableSize(): " << size << std::endl;
    EXPECT_EQ(size, 2);
}



TEST_F(ManagerTest, Test_Create_Var) {
    std::cout << "\n--- Test_Create_Var ---" << std::endl;

    size_t initial_size = manager.uniqueTableSize();
    std::cout << "Initial uniqueTableSize: " << initial_size << std::endl;

    std::cout << "Creating first variable 'a'..." << std::endl;
    BDD_ID first_var = manager.createVar("a");
    std::cout << "First var ID: " << first_var << std::endl;
    EXPECT_EQ(first_var, 2);

    size_t size_after_first = manager.uniqueTableSize();
    std::cout << "Size after first var: " << size_after_first << std::endl;
    EXPECT_EQ(size_after_first, initial_size + 1);

    std::cout << "Creating second variable 'b'..." << std::endl;
    BDD_ID second_var = manager.createVar("b");
    std::cout << "Second var ID: " << second_var << std::endl;
    EXPECT_EQ(second_var, 3);

    size_t size_after_second = manager.uniqueTableSize();
    std::cout << "Size after second var: " << size_after_second << std::endl;
    EXPECT_EQ(size_after_second, initial_size + 2);

    std::cout << "Creating duplicate variable 'a'..." << std::endl;
    BDD_ID same_var = manager.createVar("a");
    // size_t size_after_duplicate = manager.uniqueTableSize();

    std::cout << "Duplicate var ID: " << same_var << std::endl;
    std::cout << "Expected (first var ID): " << first_var << std::endl;
    EXPECT_EQ(same_var, first_var) << "If a label that already exists is passed as an input, then don't add the entry and return the id of the first label";

    size_t final_size = manager.uniqueTableSize();
    std::cout << "Final uniqueTableSize: " << final_size << std::endl;
    EXPECT_EQ(final_size, initial_size + 2);
}

TEST_F(ManagerTest, IsConstant_NegativeChcek) {
    std::cout << "\n--- IsConstant_NegativeCheck ---" << std::endl;
    std::cout << "Creating variable 'a'..." << std::endl;
    BDD_ID first_var = manager.createVar("a");
    std::cout << "Variable ID: " << first_var << std::endl;
    std::cout << "isConstant(" << first_var << "): " << manager.isConstant(first_var) << std::endl;
    EXPECT_FALSE(manager.isConstant(first_var));
}

TEST_F(ManagerTest, IsVariable_PositiveCheck) {
    std::cout << "\n--- IsVariable_PositiveCheck ---" << std::endl;
    std::cout << "Creating variable 'a'..." << std::endl;
    BDD_ID first_var = manager.createVar("a");
    std::cout << "Variable ID: " << first_var << std::endl;
    std::cout << "isVariable(" << first_var << "): " << manager.isVariable(first_var) << std::endl;
    EXPECT_TRUE(manager.isVariable(first_var));
}

// main function for tests (typically handled by main_test.cpp or gtest setup)
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}