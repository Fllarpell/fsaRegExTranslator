#include "KleeneAlgorithm.h"

KleeneAlgorithm::KleeneAlgorithm(const std::string        &typeFSA,
                                 std::vector<std::string> &states,
                                 std::vector<std::string> &alphabet,
                                 std::vector<std::string> &initialStates,
                                 std::vector<std::string> &acceptingStates,
                                 std::vector<std::string> &transitions) {
    fsa = new FSA(typeFSA);
    initialRegEx.resize(states.size(), std::vector<std::string>(states.size()));
    finalRegex.resize(states.size(), std::vector<std::string>(states.size()));
    finalStatesInRegex.resize(states.size(), std::vector<bool>(states.size()));

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

    if (this->fsa->getTypeFSA() == "deterministic") {
        if (states.size() * alphabet.size() != transitions.size())
            ErrorHandling::disjointStatesError();
    } else if (this->fsa->getTypeFSA() == "non-deterministic") {
        for (FSA::State *stateInit : this->fsa->getInitialStates())
            if (stateInit->getTransitions().empty())
                ErrorHandling::disjointStatesError();


        for (FSA::State *stateAccept : this->fsa->getAcceptingStates()) {
            bool flagHasNotWayToAccept = true;
            for (FSA::State *stateInit : this->fsa->getInitialStates())
                for (auto & i : stateInit->getTransitions())
                    if (stateAccept->getLabel() == i.second->getLabel())
                        flagHasNotWayToAccept = false;

            if (flagHasNotWayToAccept)
                ErrorHandling::disjointStatesError();
        }
    }

    fillInitialRegEx();
}

void KleeneAlgorithm::fillInitialRegEx() {
    int i = 0;

    for (FSA::State *stateFrom : fsa->getStates()) {
        int j = 0;
        for (FSA::State *stateTo : fsa->getStates()) {

            for (FSA::State *stateInit : fsa->getInitialStates())
                for (FSA::State *stateAccept : fsa->getAcceptingStates())
                    if (stateTo->getLabel() == stateAccept->getLabel()
                            && stateFrom->getLabel() == stateInit->getLabel())
                        finalStatesInRegex[i][j] = true;
                    else
                        finalStatesInRegex[i][j] = false;

            std::string regex;
            if (stateFrom->getLabel() == stateTo->getLabel()) {
                for (auto & it : stateFrom->getTransitions())
                    if (it.second == stateTo)
                        regex.empty() ? regex = "(" + it.first + "|" : regex += it.first + "|";
                if (regex.empty())
                    regex = "(eps)";
                else
                    regex += "eps)";
            } else {
                for (auto & it : stateFrom->getTransitions()) {
                    if (stateFrom->getTransitions().find(it.first)->second->getLabel() == stateTo->getLabel()) {
                        if (regex.empty())
                            regex += "(" + it.first + ")";
                        else
                            regex += "|(" + it.first + ")";
                    }
                }

                if (regex.empty())
                    regex += "({})";

            }
            this->initialRegEx[i][j] = regex;
            j++;
        }
        i++;
    }

    // fix maybe???
    for (std::vector<std::string> reg : this->initialRegEx)
        if (std::find(reg.begin(), reg.end(), "(eps)") == reg.end()
                || std::find(reg.begin(), reg.end(), "({})") == reg.end())
            if (this->fsa->getTypeFSA() == "deterministic")
                ErrorHandling::fsaTypeError();

    finalRegEx();
}

void KleeneAlgorithm::finalRegEx() {
    for (int k = 0; k < this->initialRegEx.size(); k++) {
        for (int i = 0; i < this->initialRegEx.size(); i++)
            for (int j = 0; j < this->initialRegEx.size(); j++) {
                finalRegex[i][j] = "(" + this->initialRegEx[i][k] + this->initialRegEx[k][k]
                                   + "*" + this->initialRegEx[k][j] + "|" + this->initialRegEx[i][j] + ")";
            }

        for (int i = 0; i < this->initialRegEx.size(); i++)
            for (int j = 0; j < this->initialRegEx.size(); j++) {
                initialRegEx[i][j] = finalRegex[i][j];
            }
    }

    std::string regex;
    for (int i = 0; i < this->finalStatesInRegex.size(); ++i) {
        for (int j = 0; j < this->finalStatesInRegex.size(); ++j) {
            if (finalStatesInRegex[i][j])
                regex.empty() ? regex = this->finalRegex[i][j] : regex += "+" + this->finalRegex[i][j];
        }
    }

    if (regex.empty()) {
        ErrorHandling::disjointStatesError();
    } else {
        std::cout << regex << std::endl;
    }


}
