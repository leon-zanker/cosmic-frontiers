# Flexible C Project Makefile
EXE_NAME = cosmic-frontiers
COMPILER = clang
DEBUGGER = lldb
FLAGS = -Wall -Werror -g
PACKAGES = raylib

# Commands:

# make          => builds the executable
# make run      => runs the executable
# make debug    => runs the debbuger with the executable
# make clean    => removes build artifacts
# make commands => builds compile_commands.json for 'clang' and 'clangd'

# -----------------------------------------------------------------------------------------

TARGET = bin/$(EXE_NAME)
CFLAGS = -Iinclude $(FLAGS) $(shell pkg-config --cflags $(PACKAGES))
LDFLAGS = $(FLAGS) $(shell pkg-config --libs $(PACKAGES)) -Llib $(patsubst lib/lib%.a,-l%,$(wildcard lib/lib*.a))
SRC_FILES = $(wildcard src/*.c)
OBJ_FILES = $(patsubst src/%.c,build/%.o,$(SRC_FILES))

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@mkdir -p bin
	$(COMPILER) $(OBJ_FILES) -o $@ $(LDFLAGS)

build/%.o: src/%.c
	@mkdir -p build
	$(COMPILER) -c $< -o $@ $(CFLAGS)

run: $(TARGET)
	./bin/$(EXE_NAME)

debug: $(TARGET)
	$(DEBUGGER) ./bin/$(EXE_NAME)

clean:
	rm -rf bin/*
	rm -rf build/*
	rm -rf .cache

commands:
	bear -- make

# you may add your own install label here

.PHONY: all clean run debug commands # don't forget to make the install label phony if you define one
