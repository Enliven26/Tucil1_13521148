@echo off
echo Compiling...
cd /D ./src
g++ -o main card.cpp game.cpp IO.cpp main.cpp
echo Compilation done!
main
pause