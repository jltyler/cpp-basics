# This simple script compiles mylib.cpp into a static and dynamic library file
# and compiles uselib.cpp into two binaries that use them

echo "Creating directories..."
mkdir bin
mkdir bin/static
mkdir bin/shared

echo "Compiling into objects..."
# Progam with main()
g++ -std=c++14 -c uselib.cpp -o bin/uselib.o
# Static linking library object
g++ -std=c++14 -c mylib.cpp bin/static/mylib.o
# Dynamic linking library object (Position Independent Code)
g++ -std=c++14 -c -fPIC mylib.cpp bin/shared/mylib.o

echo "Building static binary..."
# Archiver packs static library objects (multiple if you have em)
ar rcs bin/static/libmylib.a bin/static/mylib.o
# Link and build
g++ -std=c++14 bin/uselib.o -Lbin/static -lmylib -o bin/static/a.out

echo "Building dynamic binary..."
# Build shared library
g++ -std=c++14 -shared bin/shared/mylib.o -o bin/shared/libmylib-shared.so
# Build binary
g++ -std=c++14 bin/uselib.o -Lbin/shared -lmylib-shared -o bin/shared/a.out

echo "All done!"
