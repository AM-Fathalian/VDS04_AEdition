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
    BDD_ID a_id = manager.createVar("a");
    //std::cout << "First var ID: " << a_id << std::endl;
    EXPECT_EQ(a_id, 2);

    size_t size_after_first = manager.uniqueTableSize();
    std::cout << "Size after first var: " << size_after_first << std::endl;
    EXPECT_EQ(size_after_first, initial_size + 1);

    //std::cout << "Creating second variable 'b'..." << std::endl;
    BDD_ID b_id = manager.createVar("b");
    //std::cout << "Second var ID: " << b_id << std::endl;
    EXPECT_EQ(b_id, 3);

    size_t size_after_second = manager.uniqueTableSize();
    std::cout << "Size after second var: " << size_after_second << std::endl;
    EXPECT_EQ(size_after_second, initial_size + 2);

    //std::cout << "Creating duplicate variable 'a'..." << std::endl;
    BDD_ID a_copy_id = manager.createVar("a");
    // size_t size_after_duplicate = manager.uniqueTableSize();

    //std::cout << "Duplicate var ID: " << a_copy_id << std::endl;
    //std::cout << "Expected (first var ID): " << a_id << std::endl;
    EXPECT_EQ(a_copy_id, a_id) << "If a label that already exists is passed as an input, then don't add the entry and return the id of the first label";

    size_t final_size = manager.uniqueTableSize();
    std::cout << "Final uniqueTableSize: " << final_size << std::endl;
    EXPECT_EQ(final_size, initial_size + 2);
}

TEST_F(ManagerTest, IsConstant_NegativeChcek) {
    std::cout << "\n--- IsConstant_NegativeCheck ---" << std::endl;
    //std::cout << "Creating variable 'a'..." << std::endl;
    BDD_ID a_id = manager.createVar("a");
    //std::cout << "Variable ID: " << a_id << std::endl;
    std::cout << "isConstant(" << a_id << "): " << manager.isConstant(a_id) << std::endl;
    EXPECT_FALSE(manager.isConstant(a_id));
}

TEST_F(ManagerTest, IsVariable_PositiveCheck) {
    std::cout << "\n--- IsVariable_PositiveCheck ---" << std::endl;
    //std::cout << "Creating variable 'a'..." << std::endl;
    BDD_ID a_id = manager.createVar("a");
    //std::cout << "Variable ID: " << a_id << std::endl;
    std::cout << "isVariable(" << a_id << "): " << manager.isVariable(a_id) << std::endl;
    EXPECT_TRUE(manager.isVariable(a_id));
}


TEST_F(ManagerTest, TopVariable_ID) {
    std::cout << "\n--- Test_Top_Var_ID ---" << std::endl;
    BDD_ID a_id = manager.createVar("a");
    BDD_ID b_id = manager.createVar("b");
    //std::cout << "Created variables: a(ID=" << a_id << "), b(ID=" << b_id << ")" << std::endl;

    EXPECT_EQ(manager.topVar(a_id), a_id) << "TopVar ID of a 'simple' variable must be its own ID";
    EXPECT_EQ(manager.topVar(b_id), b_id) << "TopVar ID of a 'simple' variable must be its own ID";

    std::cout << "topVar(" << a_id << ") = " << manager.topVar(a_id)
              << ", topVar(" << b_id << ") = " << manager.topVar(b_id) << std::endl;

    EXPECT_EQ(manager.topVar(FALSE_ID), FALSE_ID) << "TopVar ID of the constant False, must be 0";
    EXPECT_EQ(manager.topVar(TRUE_ID), TRUE_ID) << "TopVar ID of the constant True, must be 1";

    std::cout << "topVar(FALSE_ID) = " << manager.topVar(FALSE_ID)
              << ", topVar(TRUE_ID) = " << manager.topVar(TRUE_ID) << std::endl;




}

TEST_F(ManagerTest, TopVariable_ID_ComplexNodes) {
    std::cout << "\n--- Test_Top_Var_ID_Complex ---" << std::endl;
    BDD_ID a_id = manager.createVar("a");

    BDD_ID x_id = manager.ite(a_id, FALSE_ID, TRUE_ID);
    EXPECT_EQ(manager.topVar(x_id), a_id)
        << "TopVar of the complex node x must be set to the highest-priority variable used in its definition";


}


TEST_F(ManagerTest, TopVariable_Label) {
    std::cout << "\n--- Test_Top_Var_Label ---" << std::endl;

    BDD_ID a_id = manager.createVar("a");
    BDD_ID b_id = manager.createVar("b");
    //std::cout << "Created variables: a(ID=" << a_id << "), b(ID=" << b_id << ")" << std::endl;

    EXPECT_EQ(manager.getTopVarName(a_id), "a") << "Label of a 'simple' variable must be its own label";
    EXPECT_EQ(manager.getTopVarName(b_id), "b") << "Label of a 'simple' variable must be its own label";

    std::cout << "getTopVarName(" << a_id << ") = '" << manager.getTopVarName(a_id)
              << "', getTopVarName(" << b_id << ") = '" << manager.getTopVarName(b_id) << "'" << std::endl;

    EXPECT_EQ(manager.getTopVarName(FALSE_ID), "False") << "Label of the constant False, must be 'False'";
    EXPECT_EQ(manager.getTopVarName(TRUE_ID), "True") << "Label of the constant True, must be 'True'";

    std::cout << "getTopVarName(FALSE_ID) = '" << manager.getTopVarName(FALSE_ID)
              << "', getTopVarName(TRUE_ID) = '" << manager.getTopVarName(TRUE_ID) << "'" << std::endl;



}

TEST_F(ManagerTest, TopVariable_Label_ComplexNodes) {
    std::cout << "\n--- Test_Top_Var_Label_Complex ---" << std::endl;
    BDD_ID a_id = manager.createVar("a");

    BDD_ID x_id = manager.ite(a_id, FALSE_ID, TRUE_ID);
    EXPECT_EQ(manager.getTopVarName(x_id), "a")
        << "TopVarName of the complex node x must be set to the highest-priority variable used in its definition";

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


TEST_F(ManagerTest, ComplexNode_Properties) {
    std::cout << "\n--- Test_Complex_Nodes_Properties ---" << std::endl;

    BDD_ID a_id = manager.createVar("a"); // ID 2

    // This creates a new complex node (e.g., ID 4).
    BDD_ID x_id = manager.ite(a_id, FALSE_ID, TRUE_ID);

    // 1. Check ID and Size
    EXPECT_GT(x_id, TRUE_ID) << "x must be a non-terminal ID (> 1).";
    EXPECT_EQ(manager.uniqueTableSize(), 4) << "Unique table must increase by 1 to store the new complex node x.";

    // 2. Check Classifications
    EXPECT_FALSE(manager.isConstant(x_id)) << "x must not be a constant.";
    EXPECT_FALSE(manager.isVariable(x_id)) << "x must not be a variable node.";
}


// main function for tests (typically handled by main_test.cpp or gtest setup)
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}