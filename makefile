a.exe:heap_app.o heap_imp.o
	c++ heap_app.o heap_imp.o -o a.exe
heap_app.o:heap_app.cpp
	c++ -c heap_app.cpp
heap_imp.o:heap_imp.cpp
	c++ -c heap_imp.cpp