#include <iostream>
#include <vector>
#include <thread>
#include "chi_job.h"
#include "chi_job_result.h"
#include "chi_group_result_aggregator.h"

#define PRINTLN(x) std::cout << x << std::endl


int main(int, char**) {
    std::cout << "Hello, world!\n";

    std::vector<ChiJob> jobs {ChiJob("job_1"), ChiJob("job_2"), ChiJob("job_3")};
    ChiGroupResultAggregator result_aggregator(jobs);
    for(auto& job : jobs)
    {
        std::function<void(ChiJobResult)> callback = [&](ChiJobResult job_result)
        {
            result_aggregator.OnResult(job_result);
        };
        job.RegisterJobResultCallBack(callback);
    }

    for(auto job : jobs)
    {
        try
        {
             job.Execute();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return 1;
        }
    }
    
    return 0;
}
