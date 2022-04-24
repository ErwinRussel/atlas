# Atlas
## Shared Memory IPC Process Splitter

Splitting executable in upper half (application logic) and lower half (driver part) by hooking function calls. Using IPC shmem communication to decouple the process in two seperate processes, acting as client and server. 

Atlas will be expanded with log and replay of the function calls in the lower half, effectively enabling X window and GPU applications (OpenGL) to be checkpointed by CRIU (with some small adaptations, DMTCP should work too). 
