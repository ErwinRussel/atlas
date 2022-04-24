all: atl_uh atl_lh

atl_uh: atl_uh.c
	gcc -o atl_uh atl_uh.c -lX11 -lcriu

atl_lh: atl_lh.c
	gcc	-o atl_lh atl_lh.c -lX11

clean:
	rm atl_uh
	rm atl_lh
