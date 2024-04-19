#include "../main/include.h"

#ifndef FSAREGEXTRANSLATOR_ERRORHANDLING_H
#define FSAREGEXTRANSLATOR_ERRORHANDLING_H


class ErrorHandling {
public:
    static void inputFileError();
    static void initialStateError();
    static void acceptingStateError();
    static void existingStateError(const std::string &state);
    static void existingTransitionError(const std::string &transition);
    static void disjointStatesError();
    static void fsaTypeError();
};


#endif //FSAREGEXTRANSLATOR_ERRORHANDLING_H
