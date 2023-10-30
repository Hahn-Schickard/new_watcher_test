# Description

This project is meant to test new features within the [watcher](https://github.com/e-dant/watcher) project. `watcher.hpp` file is copied from [9c5b4a6](https://github.com/e-dant/watcher/tree/9c5b4a6c581ef22785fed2f14ad9efde6ab6cc66) commit [watcher.hpp](https://github.com/e-dant/watcher/blob/9c5b4a6c581ef22785fed2f14ad9efde6ab6cc66/include/wtr/watcher.hpp) file, which is licensed under [MIT License](https://github.com/e-dant/watcher/blob/release/license) and copyrighted by [e-dant](https://github.com/e-dant)

## Building

Create a new build directory and switch into it:

`mkdir build && cd build`

Generate **cmake** build scripts:

`cmake ..`

Build the project: 

`cmake --build .`

## Running 

You can run the newly built executable as follows:
* `${BUILD_DIR}/watcher_test_runner` - uses current working directory as observed directory
* `${BUILD_DIR}/watcher_test_runner ${OBSERVERD_DIR}` - uses given directory as observed, if it does not exist, defaults to current working dir