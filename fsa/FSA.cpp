#include "FSA.h"

void FSA::addSymbolIntoAlphabet(const std::string &symbol) {
    this->alphabet.push_back(symbol);
}

void FSA::addState(const std::string &label) {
    FSA::State state(label);
    this->states.push_back(state);
}

void FSA::addInitialState(const std::string &label) {
    for (State state : this->states)
        if (state.getLabel() == label) {
            this->initialStates.push_back(state);
            return;
        }
    ErrorHandling::existingStateError();
}

void FSA::addAcceptingState(const std::string &label) {
    for (State state : this->states)
        if (state.getLabel() == label) {
            this->acceptingStates.push_back(state);
            return;
        }
    ErrorHandling::existingStateError();
}

std::vector<FSA::State> FSA::getStates() {
    return this->states;
}

std::vector<FSA::State> FSA::getInitialStates() {
    return this->initialStates;
}

std::vector<FSA::State> FSA::getAcceptingStates() {
    return this->acceptingStates;
}

std::vector<std::string> FSA::getAlphabet() {
    return this->alphabet;
}

void FSA::State::addTransition(const std::string &labelForTransition, const FSA::State& transitionState) {
    this->transitions.insert({labelForTransition, transitionState});
}
