all: server client

server: server_stub.c
	gcc	-o server server_stub.c -lX11

#client: client_stub.c
#	gcc -shared -o client.so client_stub.c -fPIC -lX11

client: client_stub.c
	gcc -o client client_stub.c -lX11 -lcriu

bufftest: bufftest.c
	gcc -o bufftest bufftest.c -lX11

clean:
	rm server
	rm client
	rm bufftest
	rm client.so