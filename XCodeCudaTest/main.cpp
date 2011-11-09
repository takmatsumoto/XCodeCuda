//
//  main.cpp
//  XCodeCudaTest
//
//  Created by  on 2011/11/8.
//  Copyright (c) 2011年 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include <CUDA/CUDA.h>
#include <CUDA/cudaProfiler.h>

bool InitCuda();

int main (int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, CUDA!\n";
    
    // 初始化
    InitCuda();
    
    return 0;
}

bool InitCuda() {
    
    int deviceCount;
    
    cuInit(0);
    cuDeviceGetCount(&deviceCount);
    
#ifdef DEBUG
    printf("CUDA Device Count : %d\n",deviceCount);
#endif    
    
    
    return true;
}
