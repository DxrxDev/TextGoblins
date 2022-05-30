all: error

error:
	@echo "No arguments given?"
	@echo "build - builds exec"
	@echo "run - runs exec"

build:
	# -O1 is used as this game is/will not be
	# resource intensive. show all warnings.
	@g++ -o TextGoblins main.cpp -O1 -Wall -Wextra
