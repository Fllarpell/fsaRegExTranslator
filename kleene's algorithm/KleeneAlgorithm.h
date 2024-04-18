#include "../main/include.h"
#include "../fsa/FSA.h"

#ifndef FSAREGEXTRANSLATOR_KLEENEALGORITHM_H
#define FSAREGEXTRANSLATOR_KLEENEALGORITHM_H


class KleeneAlgorithm {
    FSA* fsa;
    std::vector<std::vector<std::string>> initialRegEx;
public:
    KleeneAlgorithm(const std::string &typeFSA,
                    std::vector<std::string> &states,
                    std::vector<std::string> &alphabet,
                    std::vector<std::string> &initialStates,
                    std::vector<std::string> &acceptingStates,
                    std::vector<std::string> &transitions);


};


#endif //FSAREGEXTRANSLATOR_KLEENEALGORITHM_H
