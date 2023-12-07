#ifndef AUTOMATON
#define AUTOMATON

#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

template <typename SymbolType>
class State {
public:

    void addTransition(SymbolType input, State* nextState) {
        transitions[input] = nextState;
    }

    State* makeTransition(SymbolType input) const {
        auto it = transitions.find(input);
        return (it != transitions.end()) ? it->second : nullptr;
    }

private:
    std::unordered_map<SymbolType, State*> transitions;
    SymbolType symbol;
};

template <typename SymbolType>
class DFA {
public:
    DFA(State<SymbolType>* initialState) : initialState(initialState), currentState(initialState) {}

    bool makeTransition(SymbolType input) {
        currentState = currentState->makeTransition(input);
        return currentState != nullptr; 
    }

    void isInAcceptingState() const {
        std::string output = (currentState == acceptingState) ? "String accepted\n" : "String not accepted\n";
        std::cout << output;
    } // for in-code tests (there are none anymore)

    bool isInAcceptingStateBool() const {
        return currentState == acceptingState;
    } // for google tests

    void setAcceptingState(State<SymbolType>* state) {
        acceptingState = state;
    }

    bool check(std::vector<SymbolType> inputArray) {
        for (SymbolType input: inputArray) { 
            if (!(this->makeTransition(input))) { break; }
        }
        return this->isInAcceptingStateBool();
    }
private:
    State<SymbolType>* initialState;
    State<SymbolType>* currentState;
    State<SymbolType>* acceptingState;
};

#endif //AUTOMATOn