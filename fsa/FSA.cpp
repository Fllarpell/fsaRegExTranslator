#include "FSA.h"

void FSA::addSymbolIntoAlphabet(const std::string &symbol) {
    this->alphabet.push_back(symbol);
}

void FSA::addState(const std::string &label) {
    FSA::State *state = new FSA::State(label);
    this->states.push_back(state);
}

void FSA::addInitialState(const std::string &label) {
    for (State *state: this->states)
        if (state->getLabel() == label) {
            this->initialStates.push_back(state);
            return;
        }
}

void FSA::addAcceptingState(const std::string &label) {
    for (State *state : this->states)
        if (state->getLabel() == label) {
            this->acceptingStates.push_back(state);
            return;
        }
}

std::vector<FSA::State*> FSA::getStates() {
    return this->states;
}

std::string FSA::getTypeFSA() {
    return this->typeFSA;
}

std::vector<FSA::State*> FSA::getAcceptingStates() {
    return this->acceptingStates;
}

void FSA::State::addTransition(const std::string &labelForTransition, FSA::State *transitionState) {
    this->transitions.insert({ labelForTransition, transitionState});
}

std::string FSA::State::getLabel() {
    return this->label;
}

std::map<std::string, FSA::State*> FSA::State::getTransitions() {
    return this->transitions;
}
