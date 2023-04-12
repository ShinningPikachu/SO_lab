all: calc1.c hijo1.c calc2.c calc3.c
calc1:
	gcc -o calc1 calc1.c
	
calc2:
	gcc -o calc2 calc2.c
	
calc3:
	gcc -o calc3 calc3.c

hijo1:
	gcc -o hijo1 hijo1.c

clean:
	rm calc1 hijo1 calc2 calc3
