if [ $1 = "win32" ]
then
    x86_64-w64-mingw32-g++ gabriel.cpp -o gabriel.exe -static
    exit 1
fi

if [ $1 = "linux" ]
then
    g++ -g gabriel.cpp -o gabriel
    exit 1
fi

echo "Gerando executável do Gabriel para o target win32..."
x86_64-w64-mingw32-g++ gabriel.cpp -o gabriel.exe -static
echo "Gerando executável do Gabriel para o target linux..."
g++ -g gabriel.cpp -o gabriel