# Makefile for PipelineSolver Project
CC = gcc
CC = gcc
# C noob, need the compiler to baby sit my  ass :)
CFLAGS = -Wall -Wextra -Wpedantic -Iinclude \
         -Werror \
         -Wshadow \
         -Wconversion \
         -Wcast-qual \
         -Wcast-align \
         -Wwrite-strings \
         -Wformat=2 \
         -Wmissing-include-dirs \
         -Wredundant-decls \
         -Wswitch-enum \
         -Wundef \
         -Wpointer-arith \
         -Wstrict-prototypes \
         -Wmissing-prototypes \
         -Wlogical-op \
         -Winline \
         -Wfloat-equal \
         -Wunreachable-code \
         -Wformat-nonliteral \
         -Wshift-overflow=2 \
         -Wnull-dereference \
         -Wduplicated-cond \
         -Wduplicated-branches \
         -Wrestrict \
         -Wdouble-promotion \
         -Wstack-protector \
         -Wvla \
         -Woverlength-strings \
         -fanalyzer \
         -fstack-protector-strong \
         -fstack-clash-protection \
         -Werror=implicit-function-declaration \
         -Werror=incompatible-pointer-types \
         -Werror=return-type \
         -Walloc-zero \
         -Wsizeof-array-argument \
         -Walloca \
         -Wstringop-overflow \
         -Wstringop-truncation \
         -fno-common \
         -fno-omit-frame-pointer \
         -fno-strict-aliasing \
         -D_FORTIFY_SOURCE=2 \
				 -O2
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/pipelinesolver
MKDIR_P = mkdir -p

# Use find to get all .c files in SRC_DIR and its subdirectories
SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(MKDIR_P) $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ || { echo 'Build failed'; exit 1; }

-include $(DEPS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c -o $@ $< || { echo 'Compilation failed'; exit 1; }

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
