# atlas libraries
all: atl_uh atl_hook

atl_lib: atl_uh.c atl_hook.c
	gcc -shared -o atl_lib.so atl_uh.c atl_hook.c -lX11 -lcriu -lGL -fPIC

atl_uh: atl_uh.c
	gcc -o atl_uh atl_uh.c -lX11 -lcriu -lGL

atl_lh: atl_lh.c
	gcc	-o atl_lh atl_lh.c -lX11 -lGL

atl_hook: atl_hook.c
	gcc -o atl_hook atl_hook.c

# Xhw application
Xhw: Xhw.c
	gcc -o Xhw Xhw.c -lX11

clean:
	rm atl_uh
	rm atl_lh
	rm atl_lib
	rm atl_hook
	rm Xhw