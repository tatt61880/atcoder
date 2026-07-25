all: node_modules
	npm run eslint
	npm run htmlhint
	npm run stylelint
	update_data.bat

node_modules:
	npm install
