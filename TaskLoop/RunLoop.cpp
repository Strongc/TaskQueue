//
//  RunLoop.cpp
//  TaskLoop
//
//  Created by pansafeimager on 15/12/9.
//  Copyright © 2015年 imager. All rights reserved.
//

#include <thread>
#include <future>
#include "RunLoop.h"

namespace task
{
    Runloop::Runloop()
    {
        
    }
    
    Runloop::~Runloop()
    {
        
    }
    void Runloop::AddRunner(const Clouser& clouser)
    {
        _waitqueue.Add(clouser);
    }
    void Runloop::DoLoop()
    {
        for (;;)
        {
            if (_waitqueue.Empty()) {
                _waitqueue.WaitforWork();
            }
            WaitQueue<Clouser>::QueueType queue;
            _waitqueue.ReloadWaitQueue(queue);
            
            while(!queue.empty()){
                Clouser clouser = queue.front();
                Schedule(clouser);
                queue.pop();
            }
            
        }
    }
    Runloop* Runloop::Create() {
        auto ploop = new Runloop();
        std::thread(std::bind(&Runloop::DoLoop,ploop)).detach();
        return ploop;
    }
    
    void Runloop::Schedule(Clouser& clouser)
    {
        clouser.Run();
    }
}
