if [ $1 = "win32" ]
then
    x86_64-w64-mingw32-g++ gabriel.cpp -o gabriel.exe -static
fi

if [ $1 = "linux" ]
then
    g++ -g gabriel.cpp -o gabriel
fi