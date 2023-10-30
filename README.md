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