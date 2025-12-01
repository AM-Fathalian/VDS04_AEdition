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

// main function for tests (typically handled by main_test.cpp or gtest setup)
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}