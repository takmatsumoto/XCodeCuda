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
    CUdevice device;
    
    // 初始化CUDA裝置
    if (cuInit(0) != CUDA_SUCCESS)
        return false;
    
    // 取得裝置數量
    cuDeviceGetCount(&deviceCount);
    
    // 取得裝置
    if (deviceCount>0) {
#ifdef DEBUG
        printf("CUDA Device Count : %d\n",deviceCount);
#endif    
        for (int i=0; i<deviceCount; i++) {
            
            if (cuDeviceGet(&device, i)==CUDA_SUCCESS) {
                break;
            }
            else {
                printf("get device failure\n");
                return false;
            }
        }
    }
    else {
        printf("No CUDA device in this computer\n");
        return false;
    }
    
    // 取得裝置內容 (create context)
    CUcontext context;
    cuCtxCreate_v2(&context, 0, device);
    
    char deviceName[1024] = {0};
    cuDeviceGetName(deviceName, 1024, device);
#ifdef DEBUG
    printf("Device Name : %s\n",deviceName);
#endif
    
    
    return true;
}
