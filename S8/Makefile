all: exServerSocket exClientSocket lector escritor sin_nombre

exServerSocket: exServerSocket.c socketMng.o
	gcc -o exServerSocket exServerSocket.c socketMng.o

exClientSocket: exClientSocket.c socketMng.o
	gcc -o exClientSocket exClientSocket.c socketMng.o

socketMng.o: socketMng.c
	gcc -c socketMng.c
	
lector: lector.c
	gcc -c lector.c

escritor: escritor.c
	gcc -c escritor.c

sin_nombre: sin_nombre.c
	gcc -c sin_nombre.c

clean: 
	rm -f exServerSocket exClientSocket socketMng.o lector escritor sin_nombre
