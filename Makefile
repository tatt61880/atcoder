all: atcoder.exe node_modules
	npm run eslint
	npm run htmlhint
	npm run stylelint
	python download_submissions.py
	python update_resources_if_needed.py
	atcoder.exe

node_modules:
	npm install

atcoder.exe: atcoder.kn
	kuincl.exe -i atcoder.kn -o atcoder.exe
