all: atcoder.exe node_modules
	npm run eslint
	npm run htmlhint
	npm run stylelint
	python save_submissions.py
	atcoder.exe

node_modules:
	npm install

atcoder.exe: atcoder.kn
	kuincl.exe -i atcoder.kn -o atcoder.exe
