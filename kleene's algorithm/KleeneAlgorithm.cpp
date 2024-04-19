#include "KleeneAlgorithm.h"

KleeneAlgorithm::KleeneAlgorithm(const std::string &typeFSA,
                                 std::vector<std::string> &states,
                                 std::vector<std::string> &alphabet,
                                 std::vector<std::string> &initialStates,
                                 std::vector<std::string> &acceptingStates,
                                 std::vector<std::string> &transitions) {
    fsa = new FSA(typeFSA);
    for (std::string &string : states) {
        fsa->addState(string);
    }
    for (std::string &string : alphabet) {
        fsa->addSymbolIntoAlphabet(string);
    }
    for (std::string &string : initialStates) {
        fsa->addInitialState(string);
    }
    for (std::string &string : acceptingStates) {
        fsa->addAcceptingState(string);
    }
    for (std::string &string : transitions) {
        std::vector<std::string> _transitions_temp = split(string, '>');
        for (FSA::State stateFrom : fsa->getStates()) {
            if (stateFrom.getLabel() == _transitions_temp[0]) {
                for (FSA::State stateTo : fsa->getStates()) {
                    if (stateTo.getLabel() == _transitions_temp[2]) {
                        stateFrom.addTransition(_transitions_temp[1], stateTo);
                        return;
                    }
                }
            }
        }
    }
}
