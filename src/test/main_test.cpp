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

// Inside main_test.cpp, after the ManagerTest class definition


TEST_F(ManagerTest, False_Node_ID) {
    // Check if the returned IDs match the specification (0 for False)
    EXPECT_EQ(manager.False(), FALSE_ID);
}

TEST_F(ManagerTest, True_Node_ID) {
    // Check if the returned IDs match the specification (1 for True)
    EXPECT_EQ(manager.True(), TRUE_ID);
}

TEST_F(ManagerTest, IsConstant_PositiveChcek) {
    EXPECT_TRUE(manager.isConstant(TRUE_ID));
    EXPECT_TRUE(manager.isConstant(FALSE_ID));
}

TEST_F(ManagerTest, IsVariable_NegativeCheck) {
    EXPECT_FALSE(manager.isVariable(TRUE_ID));
    EXPECT_FALSE(manager.isVariable(FALSE_ID));
}


TEST_F(ManagerTest, UniqueTableSize_InitializesToTwo) {
    EXPECT_EQ(manager.uniqueTableSize(), 2);
}


TEST_F(ManagerTest, Test_Create_Var) {

    size_t initial_size = manager.uniqueTableSize();
    BDD_ID first_var = manager.createVar("a");
    EXPECT_EQ(first_var, 2);
    EXPECT_EQ(manager.uniqueTableSize(), initial_size + 1);

    BDD_ID second_var = manager.createVar("b");
    EXPECT_EQ(second_var, 3);
    EXPECT_EQ(manager.uniqueTableSize(), initial_size + 2);


    BDD_ID same_var = manager.createVar("a");
    EXPECT_EQ(same_var, first_var)<<"If a label that alredy exists is parsed as an input, then dont add the entry and return the id of the first label";
    EXPECT_EQ(manager.uniqueTableSize(), initial_size + 2);


}


TEST_F(ManagerTest, IsConstant_NegativeChcek) {
    BDD_ID first_var = manager.createVar("a");
    EXPECT_FALSE(manager.isConstant(first_var));

}

TEST_F(ManagerTest, IsVariable_PositiveCheck) {
    BDD_ID firs_var = manager.createVar("a");
    EXPECT_TRUE(manager.isVariable(firs_var));
}

//Test top VAr
TEST_F(ManagerTest, TopVariable_ID) {
    BDD_ID first_var = manager.createVar("a");
    BDD_ID second_var = manager.createVar("b");

    EXPECT_EQ(manager.topVar("a"), first_var) << "TopVar ID of a 'simple' variable must be its own ID";
    EXPECT_EQ(manager.topVar("b"), second_var) << "TopVar ID of a 'simple' variable must be its own ID";


    EXPECT_EQ(manager.topVar(FALSE_ID), FALSE_ID) << "TopVar ID of the constant False, must be 0";
    EXPECT_EQ(manager.topVar(TRUE_ID), TRUE_ID) << "TopVar ID of the constant True, must be 1";

    //PENDING TEST FOR AFTER ITE IMPLEMENTATION
    // BDD_ID complex_var1 = manager.ite(first_var, second_var, FALSE_ID); //complex_var repressenting a . b, where top var is a
    // BDD_ID complex_var2 = manager.ite(first_var, second_var, FALSE_ID);
    // BDD_ID complex_var3 = manager.ite(complex_var1, second_var, FALSE_ID);
    //
    // EXPECT_EQ(manager.topVar(complex_var1), first_var);
    // EXPECT_EQ(manager.topVar(complex_var2), first_var);
    // EXPECT_EQ(manager.topVar(complex_var3), first_var);

}

TEST_F(ManagerTest, TopVariable_Label) {
    BDD_ID first_var = manager.createVar("a");
    BDD_ID second_var = manager.createVar("b");

    EXPECT_EQ(manager.getTopVarName(first_var), "a") << "Label of a 'simple' variable must be its own label";
    EXPECT_EQ(manager.getTopVarName(second_var), "b") << "Label of a 'simple' variable must be its own label";

    EXPECT_EQ(manager.getTopVarName(FALSE_ID), "False") << "Label of the constant False, must be 'False'";
    EXPECT_EQ(manager.getTopVarName(TRUE_ID), "True") << "Label of the constant True, must be 'True'";


    //PENDING TEST FOR AFTER ITE IMPLEMENTATION
    // BDD_ID complex_var1 = manager.ite(first_var, second_var, FALSE_ID); //complex_var repressenting a . b, where top var is a
    // BDD_ID complex_var2 = manager.ite(first_var, second_var, FALSE_ID);
    // BDD_ID complex_var3 = manager.ite(complex_var1, second_var, FALSE_ID);
    //
    // EXPECT_EQ(manager.getTopVarName(complex_var1), first_var);
    // EXPECT_EQ(manager.getTopVarName(complex_var2), first_var);
    // EXPECT_EQ(manager.getTopVarName(complex_var3), first_var);


}

//Test COFActors
// TEST_F(ManagerTest, CoFactor_True) {
//     BDD_ID first_var = manager.createVar("a");
//     BDD_ID second_var = manager.createVar("b");
//
//
//
// }


//Test ite

// TEST_F(ManagerTest, Test_Node_Helpers) {
//
// }
//
// TEST_F(ManagerTest, Test_CoFactors) {
//
// }


// ... Your tests will go here ...

// main function for tests (typically handled by main_test.cpp or gtest setup)
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}