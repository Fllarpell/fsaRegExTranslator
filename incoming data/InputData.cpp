#include "InputData.h"

void InputData::inputData() {
    std::ifstream            input;
    std::string              typeFSA;
    std::vector<std::string> statesLabel;
    std::vector<std::string> alphabetSymbols;
    std::vector<std::string> initialStatesLabel;
    std::vector<std::string> acceptingStatesLabel;


    if (!input.is_open()) {
        ErrorHandling::inputFileError();
    }




    input.close();

    // calling kleene algorithm that links with FSA
}
