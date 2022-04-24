# Atlas
## Shared Memory IPC Process Splitter

Splitting executable in upper half (application logic) and lower half (driver part) by hooking function calls. Using IPC via shmem to decouple the process in two seperate processes, acting as client and server. 

Atlas will be expanded with log and replay of the function calls in the lower half, effectively enabling X window and GPU applications (OpenGL) to be checkpointed by CRIU (with some small adaptations, DMTCP should work too). 

### Checkpointing
In order to checkpoint the application with the upper half preloaded, send a `SIGUSER1` signal to the application. The application will detach from the shared memory in order to escape SysV IPC namespace (unsupported by CRIU) and the application will be checkpointed. Upon restore, the application will attach again to the shared memory.
