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
    std::cout << "\n--- Testing FalseID ---" << std::endl;
    std::cout << "Testing False() returns " << FALSE_ID << std::endl;
    BDD_ID result = manager.False();
    std::cout << "False() returned: " << result << std::endl;
    EXPECT_EQ(result, FALSE_ID);
}

TEST_F(ManagerTest, True_Node_ID) {
    std::cout << "\n--- Testing TrueID ---" << std::endl;
    BDD_ID result = manager.True();
    std::cout << "True() returned: " << result << std::endl;
    EXPECT_EQ(result, TRUE_ID);
}

TEST_F(ManagerTest, IsConstant_PositiveChcek) {
    std::cout << "\n---Testing is Constant for False and True ID ---" << std::endl;
    std::cout << "isConstant(TRUE_ID): " << manager.isConstant(TRUE_ID) << std::endl;
    std::cout << "isConstant(FALSE_ID): " << manager.isConstant(FALSE_ID) << std::endl;
    EXPECT_TRUE(manager.isConstant(TRUE_ID));
    EXPECT_TRUE(manager.isConstant(FALSE_ID));
}

TEST_F(ManagerTest, IsVariable_NegativeCheck) {
    std::cout << "\n--- Testing uniqueTableSize() == 2 ---" << std::endl;
    std::cout << "Testing isVariable returns false for constants" << std::endl;
    std::cout << "isVariable(TRUE_ID): " << manager.isVariable(TRUE_ID) << std::endl;
    std::cout << "isVariable(FALSE_ID): " << manager.isVariable(FALSE_ID) << std::endl;
    EXPECT_FALSE(manager.isVariable(TRUE_ID));
    EXPECT_FALSE(manager.isVariable(FALSE_ID));
}

TEST_F(ManagerTest, UniqueTableSize_InitializesToTwo) {
    std::cout << "\n--- Testing uniqueTableSize() == 2 ---" << std::endl;
    size_t size = manager.uniqueTableSize();
    std::cout << "uniqueTableSize(): " << size << std::endl;
    EXPECT_EQ(size, 2);
}



TEST_F(ManagerTest, Test_Create_Var) {
    std::cout << "\n--- Test_Create_Var ---" << std::endl;

    size_t initial_size = manager.uniqueTableSize();
    std::cout << "Initial uniqueTableSize: " << initial_size << std::endl;

    //std::cout << "Creating first variable 'a'..." << std::endl;
    BDD_ID first_var = manager.createVar("a");
    //std::cout << "First var ID: " << first_var << std::endl;
    EXPECT_EQ(first_var, 2);

    size_t size_after_first = manager.uniqueTableSize();
    std::cout << "Size after first var: " << size_after_first << std::endl;
    EXPECT_EQ(size_after_first, initial_size + 1);

    //std::cout << "Creating second variable 'b'..." << std::endl;
    BDD_ID second_var = manager.createVar("b");
    //std::cout << "Second var ID: " << second_var << std::endl;
    EXPECT_EQ(second_var, 3);

    size_t size_after_second = manager.uniqueTableSize();
    std::cout << "Size after second var: " << size_after_second << std::endl;
    EXPECT_EQ(size_after_second, initial_size + 2);

    //std::cout << "Creating duplicate variable 'a'..." << std::endl;
    BDD_ID same_var = manager.createVar("a");
    // size_t size_after_duplicate = manager.uniqueTableSize();

    //std::cout << "Duplicate var ID: " << same_var << std::endl;
    //std::cout << "Expected (first var ID): " << first_var << std::endl;
    EXPECT_EQ(same_var, first_var) << "If a label that already exists is passed as an input, then don't add the entry and return the id of the first label";

    size_t final_size = manager.uniqueTableSize();
    std::cout << "Final uniqueTableSize: " << final_size << std::endl;
    EXPECT_EQ(final_size, initial_size + 2);
}

TEST_F(ManagerTest, IsConstant_NegativeChcek) {
    std::cout << "\n--- IsConstant_NegativeCheck ---" << std::endl;
    //std::cout << "Creating variable 'a'..." << std::endl;
    BDD_ID first_var = manager.createVar("a");
    //std::cout << "Variable ID: " << first_var << std::endl;
    std::cout << "isConstant(" << first_var << "): " << manager.isConstant(first_var) << std::endl;
    EXPECT_FALSE(manager.isConstant(first_var));
}

TEST_F(ManagerTest, IsVariable_PositiveCheck) {
    std::cout << "\n--- IsVariable_PositiveCheck ---" << std::endl;
    //std::cout << "Creating variable 'a'..." << std::endl;
    BDD_ID first_var = manager.createVar("a");
    //std::cout << "Variable ID: " << first_var << std::endl;
    std::cout << "isVariable(" << first_var << "): " << manager.isVariable(first_var) << std::endl;
    EXPECT_TRUE(manager.isVariable(first_var));
}


TEST_F(ManagerTest, TopVariable_ID) {
    std::cout << "\n--- Test_Top_Var_ID ---" << std::endl;
    BDD_ID first_var = manager.createVar("a");
    BDD_ID second_var = manager.createVar("b");
    //std::cout << "Created variables: a(ID=" << first_var << "), b(ID=" << second_var << ")" << std::endl;

    EXPECT_EQ(manager.topVar(first_var), first_var) << "TopVar ID of a 'simple' variable must be its own ID";
    EXPECT_EQ(manager.topVar(second_var), second_var) << "TopVar ID of a 'simple' variable must be its own ID";

    std::cout << "topVar(" << first_var << ") = " << manager.topVar(first_var)
              << ", topVar(" << second_var << ") = " << manager.topVar(second_var) << std::endl;

    EXPECT_EQ(manager.topVar(FALSE_ID), FALSE_ID) << "TopVar ID of the constant False, must be 0";
    EXPECT_EQ(manager.topVar(TRUE_ID), TRUE_ID) << "TopVar ID of the constant True, must be 1";

    std::cout << "topVar(FALSE_ID) = " << manager.topVar(FALSE_ID)
              << ", topVar(TRUE_ID) = " << manager.topVar(TRUE_ID) << std::endl;

    //PENDING TEST FOR AFTER ITE IMPLEMENTATION
    // BDD_ID complex_var1 = manager.ite(first_var, second_var, FALSE_ID); //complex_var representing a . b, where top var is a
    // BDD_ID complex_var2 = manager.ite(first_var, second_var, FALSE_ID);
    // BDD_ID complex_var3 = manager.ite(complex_var1, second_var, FALSE_ID);
    //
    // EXPECT_EQ(manager.topVar(complex_var1), first_var);
    // EXPECT_EQ(manager.topVar(complex_var2), first_var);
    // EXPECT_EQ(manager.topVar(complex_var3), first_var);

}

TEST_F(ManagerTest, TopVariable_Label) {
    std::cout << "\n--- Test_Top_Var_Label ---" << std::endl;

    BDD_ID first_var = manager.createVar("a");
    BDD_ID second_var = manager.createVar("b");
    //std::cout << "Created variables: a(ID=" << first_var << "), b(ID=" << second_var << ")" << std::endl;

    EXPECT_EQ(manager.getTopVarName(first_var), "a") << "Label of a 'simple' variable must be its own label";
    EXPECT_EQ(manager.getTopVarName(second_var), "b") << "Label of a 'simple' variable must be its own label";

    std::cout << "getTopVarName(" << first_var << ") = '" << manager.getTopVarName(first_var)
              << "', getTopVarName(" << second_var << ") = '" << manager.getTopVarName(second_var) << "'" << std::endl;

    EXPECT_EQ(manager.getTopVarName(FALSE_ID), "False") << "Label of the constant False, must be 'False'";
    EXPECT_EQ(manager.getTopVarName(TRUE_ID), "True") << "Label of the constant True, must be 'True'";

    std::cout << "getTopVarName(FALSE_ID) = '" << manager.getTopVarName(FALSE_ID)
              << "', getTopVarName(TRUE_ID) = '" << manager.getTopVarName(TRUE_ID) << "'" << std::endl;

    //PENDING TEST FOR AFTER ITE IMPLEMENTATION
    // BDD_ID complex_var1 = manager.ite(first_var, second_var, FALSE_ID); //complex_var representing a . b, where top var is a
    // BDD_ID complex_var2 = manager.ite(first_var, second_var, FALSE_ID);
    // BDD_ID complex_var3 = manager.ite(complex_var1, second_var, FALSE_ID);
    //
    // EXPECT_EQ(manager.getTopVarName(complex_var1), first_var);
    // EXPECT_EQ(manager.getTopVarName(complex_var2), first_var);
    // EXPECT_EQ(manager.getTopVarName(complex_var3), first_var);

}


TEST_F(ManagerTest, ITE_BaseCase) {
    std::cout << "\n--- Test_ITE ---" << std::endl;
    std::cout << "Simple Case, no recursion" << std::endl;



    EXPECT_EQ(manager.ite(TRUE_ID, FALSE_ID, FALSE_ID), FALSE_ID) << "ITE(i, t, t) should return t (False).";
    EXPECT_EQ(manager.ite(FALSE_ID, TRUE_ID, TRUE_ID), TRUE_ID) << "ITE(i, t, t) should return t (True).";


    EXPECT_EQ(manager.ite(TRUE_ID, FALSE_ID, TRUE_ID), FALSE_ID) << "ITE(True, t, e) should return t (False).";


    EXPECT_EQ(manager.ite(FALSE_ID, TRUE_ID, FALSE_ID), FALSE_ID) << "ITE(False, t, e) should return e (False).";

    BDD_ID a_id = manager.createVar("a"); // ID 2
    EXPECT_EQ(manager.ite(a_id, TRUE_ID, FALSE_ID), a_id)
        << "ITE(a, True, False) must return the ID of variable 'a' (2).";
}


// main function for tests (typically handled by main_test.cpp or gtest setup)
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}