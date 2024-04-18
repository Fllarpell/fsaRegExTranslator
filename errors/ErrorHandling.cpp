#include "ErrorHandling.h"

void ErrorHandling::inputFileError() {
    std::cout << "E1: Input file is malformed";
    exit(0);
}

void ErrorHandling::initialStateError() {
    std::cout << "E2: Initial state is not defined";
    exit(0);
}

void ErrorHandling::acceptingStateError() {
    std::cout << "E3: Set of accepting states is empty";
    exit(0);
}

void ErrorHandling::existingStateError() {
    std::cout << "E4: A state 's' is not in the set of states"; // add parameteres
    exit(0);
}

void ErrorHandling::existingTransitionError() {
    std::cout << "E5: A transition 'a' is not represented in the alphabet"; // add parameteres
    exit(0);
}

void ErrorHandling::disjointStatesError() {
    std::cout << "E6: Some states are disjoint";
    exit(0);
}

void ErrorHandling::fsaTypeError() {
    std::cout << "E7: FSA is non-deterministic";
    exit(0);
}
