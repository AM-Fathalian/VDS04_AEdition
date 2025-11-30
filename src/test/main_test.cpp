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

#include "gtest/gtest.h"
#include "../Manager.h"

TEST(ManagerTest, Initialization) {
    ClassProject::Manager manager;
    EXPECT_EQ(manager.False(), 0);
    EXPECT_EQ(manager.True(), 1);
}


// ... Your tests will go here ...

// main function for tests (typically handled by main_test.cpp or gtest setup)
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}