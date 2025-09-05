# Game's Makefile
# This Makefile compiles the game project

# ==================== Variables ====================
# Compiler for Game Boy
CC = lcc

# Compilation flags
# -Wall -> Enable all warnings
# -std=gnu89 -> Use GNU C89 standard
CFLAGS = -Wall -std=gnu89

# Target executable name
TARGET = game

# Source files
SOURCES = $(wildcard *.c)

# Header files
HEADERS = $(wildcard *.h)

# Objects files
OBJECTS = $(SOURCES:.c=.o)

# All lcc objects
ALL_OBJECTS = $(OBJECTS) *.asm *.lst *.sym *.ihx

# ==================== Main compilation ====================
# Default target : build the executable
all: $(TARGET).gb

# Compile .c files independantly
%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

# Link objects to create executable
$(TARGET).gb: $(OBJECTS)
	@$(CC) $(OBJECTS) -o $(TARGET).gb

# ==================== Shortcuts ====================
# Format code style
format:
	clear && clang-format -i $(SOURCES) $(HEADERS)

# Code checker
check:
	clear && cppcheck --enable=all --inconclusive --std=c89 $(SOURCES) $(HEADERS)

# Format + check
check-all: format check

# Remove object files
clean:
	clear && rm -f $(ALL_OBJECTS)

# Remove object files and executable
fclean:
	clear && rm -f $(ALL_OBJECTS) $(TARGET).gb

# Rebuild everything (clean and rebuild)
re: fclean all

# Execute gb game
exec:
	$(MAKE) && sameboy $(TARGET).gb

help:
	@echo "Commands allowed :"
	@echo "make -> Build project"
	@echo "make format -> Format code synthax"
	@echo "make check -> Code checker"
	@echo "make check-all -> Format code + check it"
	@echo "make clean -> Remove objects"
	@echo "make fclean -> Remove objects + executable"
	@echo "make re -> Clean and Rebuild"
	@echo "make exec -> Compile & execute game"
	@echo "make help -> For help"
