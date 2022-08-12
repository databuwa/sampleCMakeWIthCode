#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include "chi_job.h"
#include "chi_job_result.h"
#include <future>

#define PRINTLN(x) std::cout << x << std::endl

class ChiGroupResultAggregator
{
    public:
    ChiGroupResultAggregator() = delete;
    ChiGroupResultAggregator(std::vector<ChiJob> &job_list):job_list_(job_list)
    {
        //std::async(&ChiGroupResultAggregator::ResultUpdateWorker, &this);   
    }
    void RegisterForGroupResultNotification(){}
    void OnResult(ChiJobResult job_result)
    {
        PRINTLN("result received");
        received_result_count_++;
        if(received_result_count_ == job_list_.size())
            PRINTLN("Group result available");
    }

    void ResultUpdateWorker()
    {

    }

    private:
    std::vector<ChiJob>& job_list_;
    int received_result_count_ = 0;

};