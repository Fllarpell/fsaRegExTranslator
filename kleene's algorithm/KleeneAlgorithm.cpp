#include "KleeneAlgorithm.h"

KleeneAlgorithm::KleeneAlgorithm(const std::string &typeFSA,
                                 std::vector<std::string> &states,
                                 std::vector<std::string> &alphabet,
                                 std::vector<std::string> &initialStates,
                                 std::vector<std::string> &acceptingStates,
                                 std::vector<std::string> &transitions) {
    fsa = new FSA(typeFSA);
    initialRegEx.resize(states.size(), std::vector<std::string>(states.size()));

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
        bool flagStateFrom = true;
        bool flagStateTo = true;

        std::vector<std::string> _transitions_temp = Split::split(string, '>');

        if (std::find(alphabet.begin(), alphabet.end(), _transitions_temp[1]) == alphabet.end())
            ErrorHandling::existingTransitionError(_transitions_temp[1]);

        for (FSA::State *stateFrom : this->fsa->getStates()) {
            if (stateFrom->getLabel() == _transitions_temp[0]) {
                flagStateFrom = false;

                for (FSA::State *stateTo : this->fsa->getStates()) {

                    if (stateTo->getLabel() == _transitions_temp[2]) {
                        stateFrom->addTransition(_transitions_temp[1], stateTo);
                        flagStateTo = false;
                        break;
                    }
                }
                if (flagStateTo)
                    ErrorHandling::existingStateError(_transitions_temp[2]);
            }
        }
        if (flagStateFrom)
            ErrorHandling::existingStateError(_transitions_temp[0]);
    }

    fillInitialRegEx();
}

void KleeneAlgorithm::fillInitialRegEx() {
    int i = 0;

    for (FSA::State *stateFrom : fsa->getStates()) {
        int j = 0;
        for (FSA::State *stateTo : fsa->getStates()) {
            std::string regex;
            if (stateFrom->getLabel() == stateTo->getLabel()) {
                for (auto & it : stateFrom->getTransitions())
                    if (it.second == stateTo)
                        regex = "(" + it.first + " | eps)";
                if (regex.empty())
                    regex = "(eps)";
            } else {
                for (auto & it : stateFrom->getTransitions()) {
                    if (stateFrom->getTransitions().find(it.first)->second->getLabel() == stateTo->getLabel()) {
                        if (regex.empty())
                            regex += it.first;
                        else
                            regex += " | " + it.first;
                    }
                }

                if (regex.empty())
                    regex += "({})";

                this->initialRegEx[i][j] = regex;
            }
            this->initialRegEx[i][j] = regex;
            j++;
        }
        i++;
    }
}

std::vector<std::vector<std::string>> KleeneAlgorithm::getInitialRegEx() {
    return this->initialRegEx;
}

