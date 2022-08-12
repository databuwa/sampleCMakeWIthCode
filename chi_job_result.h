#pragma once
#include <iostream>
#include <vector>
#include <thread>
#define PRINTLN(x) std::cout << x << std::endl
class ChiJobResult
{
    public:
    enum state
    {
        PASS,
        FAIL
    };
    ChiJobResult() = delete;
    ChiJobResult(ChiJobResult::state state):state_(state){}
    ChiJobResult::state GetState(){ return state_; }

    private:
    ChiJobResult::state state_;
};