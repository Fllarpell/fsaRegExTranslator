#include "../main/include.h"
#include "../fsa/FSA.h"
#include "../errors/ErrorHandling.h"

#ifndef FSAREGEXTRANSLATOR_KLEENEALGORITHM_H
#define FSAREGEXTRANSLATOR_KLEENEALGORITHM_H


class KleeneAlgorithm {
    FSA* fsa;
public:
    KleeneAlgorithm(const std::string &typeFSA,
                    std::vector<std::string> &states,
                    std::vector<std::string> &alphabet,
                    std::vector<std::string> &initialStates,
                    std::vector<std::string> &acceptingStates,
                    std::vector<std::string> &transitions);

    void fillInitialRegEx();

    void finalRegEx();

private:
    std::vector<std::vector<std::string>> initialRegEx;
    std::vector<std::vector<std::string>> finalRegex;
    std::vector<std::vector<bool>> finalStatesInRegex;
};


#endif //FSAREGEXTRANSLATOR_KLEENEALGORITHM_H
