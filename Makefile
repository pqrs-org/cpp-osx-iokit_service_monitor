CLANG_FORMAT_FILES = \
	'*.h' \
	'*.hpp' \
	'*.hpp.in' \
	'*.iig' \
	'*.mm' \
	'*.cpp' \
	':(exclude)vendor/**'

format: clang-format

clang-format:
	git ls-files -z -- $(CLANG_FORMAT_FILES) | xargs -0 clang-format -i
