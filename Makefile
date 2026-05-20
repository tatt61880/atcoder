all: atcoder.exe node_modules
	npm run eslint
	npm run htmlhint
	npm run stylelint
	python download_submissions.py
	python download_contests.py
	python download_problems.py
	python download_contest_problem.py
	atcoder.exe

node_modules:
	npm install

atcoder.exe: atcoder.kn
	kuincl.exe -i atcoder.kn -o atcoder.exe
