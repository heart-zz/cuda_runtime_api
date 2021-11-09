#include "cuda_runtime_api.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main() {
        int current_device;
        cudaGetDevice(&current_device);

        printf( "current_device %d\n", current_device);
	      cudaDeviceProp cuprops;
        cudaError_t cuerr = cudaGetDeviceProperties(&cuprops, current_device);
        if (cuerr != cudaSuccess) {
           printf("cudaGetDeviceProperties() failed. %d", cuerr);

        }
        else {
	        std::string cc = std::to_string(cuprops.major) + "." + std::to_string(cuprops.minor);
                cout << cc << endl;
          cout <<  "device Properties pciDeviceID:" << (int)cuprops.pciDeviceID << endl; 
          cout <<  "device Properties pciBusID:" << cuprops.pciBusID << endl;
          cout <<  "device Properties pciDomainID:" << cuprops.pciDomainID << endl;
          cout <<  "device Properties name:" << cuprops.name << endl;
	      }

    cudaError_t cudaSt;

    int cudaDeviceCount;

    cudaSt = cudaGetDeviceCount(&cudaDeviceCount);
    if (cudaSt == cudaSuccess)
    {
      
        printf("cudaDeviceCount %d\n", cudaDeviceCount);
        for (int deviceIdx = 0; deviceIdx < cudaDeviceCount; deviceIdx++)
        {
            cudaSetDevice(deviceIdx);
          //  cudaDeviceReset();
            char* pciBusId = new char[100];
            cudaSt = cudaDeviceGetPCIBusId(pciBusId, 100, deviceIdx);
            if(cudaSt == cudaSuccess)
            {
               printf("pciBusId %s\n", pciBusId);
            } 
            else {
              cout<< "cudaDeviceGetPCIBusId failed." << cudaSt<< endl;
            }
            delete(pciBusId);
          //  printf("Reset device %d\n", deviceIdx);
        }
    }
    else
    {
        printf("cudaGetDeviceCount,%d", cudaSt);
    }
        

}

