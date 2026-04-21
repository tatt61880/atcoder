
all: atcoder.exe
	atcoder.exe

atcoder.exe: atcoder.kn
	kuincl.exe -i atcoder.kn -o atcoder.exe
