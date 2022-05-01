all: atl_lh atl_lib

atl_lib: atl_uh.c atl_hook.c
	gcc -shared -o atl_lib.so atl_uh.c atl_hook.c -lX11 -lGL -fPIC # add -lcriu

atl_uh: atl_uh.c
	gcc -o atl_uh atl_uh.c -lX11 -lcriu -lGL

atl_lh: atl_lh.c
	gcc	-o atl_lh atl_lh.c -lX11 -lGL

atl_hook: atl_hook.c
	gcc -o atl_hook atl_hook.c

#glxgears
glxgears: glxgears.c
	gcc -o glxgears glxgears.c -lX11 -lGL -lm

clean-glxgears:
	rm glxgears

clean:
	rm atl_lh
	rm atl_lib.so
