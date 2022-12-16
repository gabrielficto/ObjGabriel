if [ $1 = "win32" ]
then
    x86_64-w64-mingw32-g++ ficto.cpp -o ficto.exe -static
    exit 1
fi

if [ $1 = "linux" ]
then
    g++ -g ficto.cpp -o ficto
    exit 1
fi

echo "Gerando executável do FictoC++ para o target win32..."
x86_64-w64-mingw32-g++ ficto.cpp -o ficto.exe -static
echo "Gerando executável do FictoC++ para o target linux..."
g++ -g ficto.cpp -o ficto