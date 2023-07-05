simulation:
    
	g++ src/main.cc src/Point.cc -o simulation -lsfml-graphics -lsfml-window -lsfml-system

run:
	./simulation

clean:
	rm simulation
