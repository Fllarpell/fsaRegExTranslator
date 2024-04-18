#include "../main/include.h"

#ifndef FSAREGEXTRANSLATOR_ERRORHANDLING_H
#define FSAREGEXTRANSLATOR_ERRORHANDLING_H


class ErrorHandling {
public:
    static void inputFileError();
    static void initialStateError();
    static void acceptingStateError();
    static void existingStateError();
    static void existingTransitionError();
    static void disjointStatesError();
    static void fsaTypeError();
};


#endif //FSAREGEXTRANSLATOR_ERRORHANDLING_H
