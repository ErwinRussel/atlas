all: atl_uh atl_lh

atl_uh: atl_uh.c
	gcc -o atl_uh atl_uh.c -lX11 -lcriu -lGL

atl_lh: atl_lh.c
	gcc	-o atl_lh atl_lh.c -lX11 -lGL

atl_hook: atl_hook.c
	gcc -o atl_hook atl_hook.c

clean:
	rm atl_uh
	rm atl_lh
