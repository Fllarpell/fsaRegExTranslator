#include "InputData.h"

void InputData::inputData() {
    std::ifstream            input("input.txt");
    std::string              data;
    std::vector<std::string> rightInputData = {"type",
                                               "states",
                                               "alphabet",
                                               "initial",
                                               "accepting",
                                               "transitions",
                                               "non-deterministic",
                                               "deterministic"};

    std::string              typeFSA;
    std::vector<std::string> statesLabel;
    std::vector<std::string> alphabetSymbols;
    std::vector<std::string> initialStatesLabel;
    std::vector<std::string> acceptingStatesLabel;
    std::vector<std::string> transitions;

    if (!input.is_open())
        ErrorHandling::inputFileError();

    while (getline(input, data)) {
        std::map<std::string, int> mappingData;

        mappingData["type"]         = 0;
        mappingData["states"]       = 1;
        mappingData["alphabet"]     = 2;
        mappingData["initial"]      = 3;
        mappingData["accepting"]    = 4;
        mappingData["transitions"]  = 5;

        std::string inputWord = data.substr(0, data.find('='));
        data.erase(0, data.find('=') + 1).erase(0, data.find('[') + 1).erase(data.find(']'), data.find(']'));
        if (std::find(rightInputData.begin(), rightInputData.end(), inputWord) == rightInputData.end())
            ErrorHandling::inputFileError();

        switch (mappingData[inputWord]) {
            case 0:
                typeFSA = data;
                if (std::find(rightInputData.begin(), rightInputData.end(), typeFSA) == rightInputData.end())
                    ErrorHandling::inputFileError();
                break;

            case 1:
                statesLabel = split(data, ',');
                break;

            case 2:
                alphabetSymbols = split(data, ',');
                break;

            case 3:
                if (data.empty())
                    ErrorHandling::initialStateError();
                initialStatesLabel = split(data, ',');
                break;

            case 4:
                if (data.empty())
                    ErrorHandling::acceptingStateError();
                acceptingStatesLabel = split(data, ',');
                break;

            case 5:
                transitions = split(data, ',');
                break;
        }
    }

    input.close();

    // calling kleene algorithm that links with FSA
}




