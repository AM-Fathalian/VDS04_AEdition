#include "Manager.h"
#include <algorithm>

namespace ClassProject {

    Manager::Manager() {
        nodes.push_back({FALSE_ID, FALSE_ID, FALSE_ID, FALSE_ID, "False"});
        nodes.push_back({TRUE_ID, TRUE_ID, TRUE_ID, TRUE_ID, "True"});
    }

    const BDD_ID &Manager::True() { return TRUE_ID; }
    const BDD_ID &Manager::False() { return FALSE_ID; }
    bool Manager::isConstant(BDD_ID f) { return (f == TRUE_ID || f == FALSE_ID); }
    bool Manager::isVariable(BDD_ID x) { return (nodes[x].high == TRUE_ID && nodes[x].low == FALSE_ID); }
    BDD_ID Manager::topVar(BDD_ID f) { return 0; }
    size_t Manager::uniqueTableSize() { return nodes.size(); }

    BDD_ID Manager::createVar(const std::string &label) {
        return 0;
    }

    std::string Manager::getTopVarName(const BDD_ID &root) {
        return "";
    }

    BDD_ID Manager::ite(BDD_ID i, BDD_ID t, BDD_ID e) {
        return 0;
    }

    BDD_ID Manager::coFactorTrue(BDD_ID f, BDD_ID x) {
        return 0;
    }

    BDD_ID Manager::coFactorFalse(BDD_ID f, BDD_ID x) {
        return 0;
    }

    BDD_ID Manager::coFactorTrue(BDD_ID f) { return 0; }
    BDD_ID Manager::coFactorFalse(BDD_ID f){ return 0; }

    BDD_ID Manager::and2(BDD_ID a, BDD_ID b) { return 0; }
    BDD_ID Manager::or2(BDD_ID a, BDD_ID b)  { return 0; }
    BDD_ID Manager::xor2(BDD_ID a, BDD_ID b) { return 0; }
    BDD_ID Manager::neg(BDD_ID a)            { return 0; }
    BDD_ID Manager::nand2(BDD_ID a, BDD_ID b){ return 0; }
    BDD_ID Manager::nor2(BDD_ID a, BDD_ID b) { return 0; }
    BDD_ID Manager::xnor2(BDD_ID a, BDD_ID b){ return 0; }

    void Manager::findNodes(const BDD_ID &root, std::set<BDD_ID> &nodes_of_root) {

    }

    void Manager::findVars(const BDD_ID &root, std::set<BDD_ID> &vars_of_root) {

    }

    void Manager::visualizeBDD(std::string filepath, BDD_ID &root) {}
}
#include "Manager.h"
