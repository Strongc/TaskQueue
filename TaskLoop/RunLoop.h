//
//  RunLoop.hpp
//  TaskLoop
//
//  Created by pansafeimager on 15/12/9.
//  Copyright © 2015年 imager. All rights reserved.
//

#ifndef RunLoop_hpp
#define RunLoop_hpp

#include "Runner.hpp"
#include "WaitQueue.hpp"
namespace task {
    class Runloop
    {
    public:
        static Runloop* Create();
        
        void AddRunner(const Clouser& clouser);
        
        void DoLoop();
        
        virtual void Schedule(Clouser& clouser);
        
    protected:
        
        Runloop();
        ~Runloop();
        WaitQueue<Clouser> _waitqueue;
    };
}

#endif /* RunLoop_hpp */
