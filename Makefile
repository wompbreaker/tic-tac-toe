# Default target
.DEFAULT_GOAL := help

.PHONY: help game docs clear

help:
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  help   Show this help message (default)"
	@echo "  game   Build the tic-tac-toe game (output: tictactoe)"
	@echo "  docs   Generate documentation using doxygen"
	@echo "  clear  Remove generated documentation and executable"

game:
	@echo "[INFO] Compiling tic-tac-toe game..."
	@if gcc main.c src/game.c -Iinc -o tictactoe; then \
		echo "[SUCCESS] Build complete: ./tictactoe"; \
	else \
		echo "[ERROR] Build failed!"; exit 1; \
	fi

docs:
	@echo "[INFO] Generating documentation with doxygen..."
	@if doxygen Doxyfile; then \
		echo "[SUCCESS] Documentation generated in ./docs"; \
	else \
		echo "[ERROR] Documentation generation failed!"; exit 1; \
	fi

clear:
	@echo "[INFO] Removing ./docs directory and ./tictactoe executable..."
	@rm -rf ./docs ./tictactoe
	@echo "[SUCCESS] Cleanup complete."
