all: atl_lh atl_lib

atl_lib: atl_uh.c atl_hook.c
	gcc -shared -o atl_lib.so atl_uh.c atl_hook.c -lX11 -lGL -fPIC # add -lcriu

atl_uh: atl_uh.c
	gcc -o atl_uh atl_uh.c -lX11 -lcriu -lGL

atl_lh: atl_lh.c
	gcc -o atl_lh atl_lh.c -lX11 -lGL -no-pie

atl_hook: atl_hook.c
	gcc -o atl_hook atl_hook.c

#glxgears
Openglhw: Openglhw.c
	gcc -o Openglhw Openglhw.c -lX11 -lGL

clean-glxgears:
	rm Openglhw

clean:
	rm atl_lh
	rm atl_lib.so
