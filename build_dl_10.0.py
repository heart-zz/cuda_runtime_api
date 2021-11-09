rm -r build/
mkdir build
cd build

cmake  -DCMAKE_INSTALL_PREFIX:PATH=`pwd`/install \
 -DCUDA_CUDART_LIBRARY=/LocalRun/hammingsdk/denglin_hamming_sdk_linux_x86_tf12_0927/dlsdk/sdk/include \
 -DCUDA_CUDART=/LocalRun/wendong.song/development/denglin/hammingsdk/denglin_hamming_sdk_linux_x86_tf12_0927/newdir/sdk/lib/libcurt.so \
 ..
make 
