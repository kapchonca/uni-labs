#pragma once
#include <gtest/gtest.h>

#include "automaton.h"

TEST(StringTest, Subtest_1) {

    State<std::string> state1, state2, state3, state4;
    state1.addTransition("somebody", &state2);
    state2.addTransition("once", &state3);
    state3.addTransition("told", &state4);
    state4.addTransition("me", &state1);

    DFA<std::string> dfa(&state1);
    dfa.setAcceptingState(&state3);

    std::vector<std::string> input {"somebody", "once"};

    ASSERT_TRUE(dfa.check(input));
};

TEST(CharTest, Subtest_1) {

    State<char> state1, state2, state3;
    state1.addTransition('a', &state2);
    state2.addTransition('b', &state3);
    state3.addTransition('c', &state1);

    DFA<char> dfa(&state1);
    dfa.setAcceptingState(&state3); 

    std::vector<char> input {'a', 'b', 'd'};

    ASSERT_FALSE(dfa.check(input));
} 

TEST(IntTest, Subtest_1) {

    State<int> state1, state2, state3;
    state1.addTransition(1, &state2); // 1 - proceed to the next state
    state2.addTransition(1, &state3); 
    state1.addTransition(2, &state1); // 2 - stay in the same state 
    state2.addTransition(2, &state2);
    state3.addTransition(2, &state3);
    state2.addTransition(3, &state1); // 3 - proceed to the previous state 
    DFA<int> dfa(&state1);
    dfa.setAcceptingState(&state3);

    std::vector<int> input {1, 2, 3, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2};

    ASSERT_TRUE(dfa.check(input));
}
