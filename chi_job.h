#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include "chi_job_result.h"

#define PRINTLN(x) std::cout << x << std::endl
class ChiJob
{
    public:
    ChiJob() = delete;
    ChiJob(std::string name):name_(name){}
    std::string GetName(){return name_;}
    void Execute()
    {
        PRINTLN(name_);
        //if(result_callback_ == nullptr) throw std::invalid_argument("Execute::Callback cannot be null");
        PRINTLN(result_callbacks_.size());
        result_callbacks_[0](ChiJobResult(ChiJobResult::state::PASS));
    }
    void RegisterJobResultCallBack(const std::function<void(ChiJobResult)> result_callback )
    {
        PRINTLN("ss");
        if(result_callback == nullptr) throw std::invalid_argument("Callback cannot be null");
        result_callback_ = std::function<void(ChiJobResult)>(result_callback);
        result_callbacks_.push_back(std::function<void(ChiJobResult)>(result_callback));
        PRINTLN(result_callbacks_.size());
        if(result_callback_ == nullptr) throw std::invalid_argument("Callback cannot be null");

    }
    private:
    std::string name_;
    std::function<void(ChiJobResult)> result_callback_;
    std::vector<std::function<void(ChiJobResult)>> result_callbacks_;
};