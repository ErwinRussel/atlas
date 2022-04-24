# Atlas
## Shared Memory IPC Process Splitter

Splitting executable in upper half (application logic) and lower half (driver part) by hooking function calls. Using IPC shmem communication to decouple the process in two seperate processes, acting as client and server. 
