#include "../main/include.h"

#ifndef FSAREGEXTRANSLATOR_FSA_H
#define FSAREGEXTRANSLATOR_FSA_H

class FSA {
public:

    explicit FSA(std::string  typeFSA) : typeFSA(std::move(typeFSA)) {};
    ~FSA() = default;

    class State {
    public:
        explicit State(std::string  label) : label(std::move(label)) {};
        ~State() = default;

        void addTransition(const std::string &labelForTransition, State *transitionState);

        std::string getLabel();

        std::map<std::string, FSA::State*> getTransitions();

    private:
        std::string label;
        std::map<std::string, FSA::State*> transitions;

    };

    void addSymbolIntoAlphabet(const std::string& symbol);

    void addState(const std::string& label);

    void addInitialState(const std::string &label);

    void addAcceptingState(const std::string &label);

    std::vector<State*> getStates();

    std::vector<State*> getInitialStates();

    std::vector<State*> getAcceptingStates();

    std::vector<std::string> getAlphabet();



private:
    std::string typeFSA;

    std::vector<FSA::State*> initialStates;
    std::vector<FSA::State*> acceptingStates;
    std::vector<FSA::State*> states;
    std::vector<std::string> alphabet;
};


#endif //FSAREGEXTRANSLATOR_FSA_H
