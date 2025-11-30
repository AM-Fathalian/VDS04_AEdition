// #include "Manager.h"
// #include <stdexcept>
// #include <algorithm> // For std::max in topVar placeholder
//
// namespace ClassProject {
//
//     // Helper function for the True() and False() ID access
//     const BDD_ID FALSE_ID = 0;
//     const BDD_ID TRUE_ID = 1;
//
//     Manager::Manager() {
//         // Initialize False (ID 0)
//         // False node: High=0, Low=0, TopVar=0
//         unique_table.push_back({FALSE_ID, FALSE_ID, FALSE_ID, "False"});
//
//         // Initialize True (ID 1)
//         // True node: High=1, Low=1, TopVar=1
//         unique_table.push_back({TRUE_ID, TRUE_ID, TRUE_ID, "True"});
//     }
//
//     // --- Core Methods Implemented for Initial Test Compilation/Passing ---
//
//     const BDD_ID &Manager::True() {
//         // True is always represented by ID 1
//         return unique_table.at(TRUE_ID).topVar;
//     }
//
//     const BDD_ID &Manager::False() {
//         // False is always represented by ID 0
//         return unique_table.at(FALSE_ID).topVar;
//     }
//
//     size_t Manager::uniqueTableSize() {
//         // Returns the number of nodes currently in the unique table
//         return unique_table.size();
//     }
//
//     bool Manager::isConstant(BDD_ID f) {
//         // A node is a constant (leaf node) if its ID is 0 or 1
//         return f == FALSE_ID || f == TRUE_ID;
//     }
//
//     BDD_ID Manager::createVar(const std::string &label) {
//         // The new BDD_ID is the current size of the vector
//         BDD_ID new_id = unique_table.size();
//
//         // New variable node has:
//         // High Successor: True (1)
//         // Low Successor: False (0)
//         // Top Variable: Itself (new_id)
//         BDD_Node new_node = {True(), False(), new_id, label};
//         unique_table.push_back(new_node);
//
//         // Store the variable label for later use (e.g., getTopVarName)
//         var_labels[new_id] = label;
//
//         return new_id;
//     }
//
//     // Implementation based on BDD structure for variables (High=1, Low=0, TopVar=ID)
//     bool Manager::isVariable(BDD_ID x) {
//         if (isConstant(x)) {
//             return false;
//         }
//
//         // Check if the node's properties match a variable node structure
//         const auto& node = unique_table.at(x);
//         return node.high == TRUE_ID && node.low == FALSE_ID && node.topVar == x;
//     }
//
//     // --- Placeholders for Remaining Pure Virtual Functions ---
//
//     // Top Variable Accessor
//     BDD_ID Manager::topVar(BDD_ID f) {
//         if (isConstant(f)) {
//             // As per the example table, constants have a Top Var of their own ID
//             return f;
//         }
//         // Return the stored top variable ID for non-constant nodes
//         return unique_table.at(f).topVar;
//     }
//
//     // ITE Operation (Core Logic)
//     BDD_ID Manager::ite(BDD_ID i, BDD_ID t, BDD_ID e) {
//         // TEMPORARY: Return 0 (False ID) until fully implemented using recursion/unique-table checks
//         throw std::runtime_error("ite not yet implemented");
//     }
//
//     // Co-factor Operations
//     BDD_ID Manager::coFactorTrue(BDD_ID f, BDD_ID x) {
//         // TEMPORARY: Return 0 (False ID) until implemented
//         throw std::runtime_error("coFactorTrue(f, x) not yet implemented");
//     }
//
//     BDD_ID Manager::coFactorFalse(BDD_ID f, BDD_ID x) {
//         // TEMPORARY: Return 0 (False ID) until implemented
//         throw std::runtime_error("coFactorFalse(f, x) not yet implemented");
//     }
//
//     BDD_ID Manager::coFactorTrue(BDD_ID f) {
//         // TEMPORARY: Return 0 (False ID) until implemented (uses topVar(f))
//         throw std::runtime_error("coFactorTrue(f) not yet implemented");
//     }
//
//     BDD_ID Manager::coFactorFalse(BDD_ID f) {
//         // TEMPORARY: Return 0 (False ID) until implemented (uses topVar(f))
//         throw std::runtime_error("coFactorFalse(f) not yet implemented");
//     }
//
//     // Logic Operations
//     BDD_ID Manager::and2(BDD_ID a, BDD_ID b) {
//         // TEMPORARY: Return 0 (False ID) until implemented (based on ite)
//         throw std::runtime_error("and2 not yet implemented");
//     }
//
//     BDD_ID Manager::or2(BDD_ID a, BDD_ID b) {
//         // TEMPORARY: Return 0 (False ID) until implemented (based on ite)
//         throw std::runtime_error("or2 not yet implemented");
//     }
//
//     BDD_ID Manager::xor2(BDD_ID a, BDD_ID b) {
//         // TEMPORARY: Return 0 (False ID) until implemented (based on ite)
//         throw std::runtime_error("xor2 not yet implemented");
//     }
//
//     BDD_ID Manager::neg(BDD_ID a) {
//         // TEMPORARY: Return 0 (False ID) until implemented (based on ite)
//         throw std::runtime_error("neg not yet implemented");
//     }
//
//     BDD_ID Manager::nand2(BDD_ID a, BDD_ID b) {
//         // TEMPORARY: Return 0 (False ID) until implemented (based on ite)
//         throw std::runtime_error("nand2 not yet implemented");
//     }
//
//     BDD_ID Manager::nor2(BDD_ID a, BDD_ID b) {
//         // TEMPORARY: Return 0 (False ID) until implemented (based on ite)
//         throw std::runtime_error("nor2 not yet implemented");
//     }
//
//     BDD_ID Manager::xnor2(BDD_ID a, BDD_ID b) {
//         // TEMPORARY: Return 0 (False ID) until implemented (based on ite)
//         throw std::runtime_error("xnor2 not yet implemented");
//     }
//
//     // Utility/Visualization
//     std::string Manager::getTopVarName(const BDD_ID &root) {
//         if (isConstant(root)) {
//             // Return the constant label ("False" or "True")
//             return unique_table.at(root).label;
//         }
//         // Retrieve the label from the variable ID stored in the node's topVar field
//         BDD_ID var_id = unique_table.at(root).topVar;
//         auto it = var_labels.find(var_id);
//         if (it != var_labels.end()) {
//             return it->second;
//         }
//         throw std::runtime_error("Top variable label not found.");
//     }
//
//     void Manager::findNodes(const BDD_ID &root, std::set<BDD_ID> &nodes_of_root) {
//         // TEMPORARY: Do nothing until implemented (recursive traversal)
//     }
//
//     void Manager::findVars(const BDD_ID &root, std::set<BDD_ID> &vars_of_root) {
//         // TEMPORARY: Do nothing until implemented (recursive traversal)
//     }
//
//     void Manager::visualizeBDD(std::string filepath, BDD_ID &root) {
//         // TEMPORARY: Do nothing until implemented (not part of TDD)
//     }
//
// } // namespace ClassProject
/////////////////////////////////////////

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
    BDD_ID Manager::topVar(BDD_ID f) { return nodes[f].topVar; }
    size_t Manager::uniqueTableSize() { return nodes.size(); }

    BDD_ID Manager::createVar(const std::string &label) {
        BDD_ID new_id = nodes.size();
        nodes.push_back({new_id, TRUE_ID, FALSE_ID, new_id, label});
        return new_id;
    }

    std::string Manager::getTopVarName(const BDD_ID &root) {
        BDD_ID id = topVar(root);
        return nodes[id].label;
    }

    BDD_ID Manager::ite(BDD_ID i, BDD_ID t, BDD_ID e) {
        if (i == TRUE_ID) return t;
        if (i == FALSE_ID) return e;
        if (t == e) return t;
        if (t == TRUE_ID && e == FALSE_ID) return i;

        BDD_ID topI = isConstant(i) ? nodes.size() : topVar(i);
        BDD_ID topT = isConstant(t) ? nodes.size() : topVar(t);
        BDD_ID topE = isConstant(e) ? nodes.size() : topVar(e);
        BDD_ID top = std::min({topI, topT, topE});

        BDD_ID i_high = (isConstant(i) || topVar(i) != top) ? i : nodes[i].high;
        BDD_ID i_low  = (isConstant(i) || topVar(i) != top) ? i : nodes[i].low;
        BDD_ID t_high = (isConstant(t) || topVar(t) != top) ? t : nodes[t].high;
        BDD_ID t_low  = (isConstant(t) || topVar(t) != top) ? t : nodes[t].low;
        BDD_ID e_high = (isConstant(e) || topVar(e) != top) ? e : nodes[e].high;
        BDD_ID e_low  = (isConstant(e) || topVar(e) != top) ? e : nodes[e].low;

        BDD_ID r_high = ite(i_high, t_high, e_high);
        BDD_ID r_low = ite(i_low, t_low, e_low);

        if (r_high == r_low) return r_high;

        for (size_t k = 0; k < nodes.size(); k++) {
            if (nodes[k].high == r_high && nodes[k].low == r_low && nodes[k].topVar == top) return k;
        }

        BDD_ID new_id = nodes.size();
        nodes.push_back({new_id, r_high, r_low, top, ""});
        return new_id;
    }

    BDD_ID Manager::coFactorTrue(BDD_ID f, BDD_ID x) {
        if (isConstant(f)) return f;
        if (topVar(f) != x) {
             BDD_ID T = coFactorTrue(nodes[f].high, x);
             BDD_ID E = coFactorTrue(nodes[f].low, x);
             return ite(topVar(f), T, E);
        }
        return nodes[f].high;
    }

    BDD_ID Manager::coFactorFalse(BDD_ID f, BDD_ID x) {
        if (isConstant(f)) return f;
        if (topVar(f) != x) {
             BDD_ID T = coFactorFalse(nodes[f].high, x);
             BDD_ID E = coFactorFalse(nodes[f].low, x);
             return ite(topVar(f), T, E);
        }
        return nodes[f].low;
    }

    BDD_ID Manager::coFactorTrue(BDD_ID f) { return nodes[f].high; }
    BDD_ID Manager::coFactorFalse(BDD_ID f){ return nodes[f].low; }

    BDD_ID Manager::and2(BDD_ID a, BDD_ID b) { return ite(a, b, FALSE_ID); }
    BDD_ID Manager::or2(BDD_ID a, BDD_ID b)  { return ite(a, TRUE_ID, b); }
    BDD_ID Manager::xor2(BDD_ID a, BDD_ID b) { return ite(a, neg(b), b); }
    BDD_ID Manager::neg(BDD_ID a)            { return ite(a, FALSE_ID, TRUE_ID); }
    BDD_ID Manager::nand2(BDD_ID a, BDD_ID b){ return neg(and2(a, b)); }
    BDD_ID Manager::nor2(BDD_ID a, BDD_ID b) { return neg(or2(a, b)); }
    BDD_ID Manager::xnor2(BDD_ID a, BDD_ID b){ return neg(xor2(a, b)); }

    void Manager::findNodes(const BDD_ID &root, std::set<BDD_ID> &nodes_of_root) {
        nodes_of_root.insert(root);
        if (isConstant(root)) return;
        findNodes(nodes[root].high, nodes_of_root);
        findNodes(nodes[root].low, nodes_of_root);
    }

    void Manager::findVars(const BDD_ID &root, std::set<BDD_ID> &vars_of_root) {
        std::set<BDD_ID> allNodes;
        findNodes(root, allNodes);
        for(BDD_ID n : allNodes) {
            if (!isConstant(n)) vars_of_root.insert(topVar(n));
        }
    }

    void Manager::visualizeBDD(std::string filepath, BDD_ID &root) {}
}