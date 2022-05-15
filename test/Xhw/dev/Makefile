# atlas libraries
all: atl_lib atl_lh

atl_lib: atl_uh.c atl_hook.c
	gcc -shared -o atl_lib.so atl_uh.c atl_hook.c -lX11 -lGL -lcriu -fPIC

atl_uh: atl_uh.c
	gcc -o atl_uh atl_uh.c -lX11 -lGL

atl_lh: atl_lh.c replay.c
	gcc	-o atl_lh atl_lh.c replay.c -lX11 -lGL

atl_hook: atl_hook.c
	gcc -o atl_hook atl_hook.c

# Xhw application
Xhw: Xhw.c
	gcc -o Xhw Xhw.c -lX11

clean:
	rm atl_lh
	rm atl_lib
	rm atl_hook
	rm Xhw