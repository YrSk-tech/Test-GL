CC = gcc
CFLAGS = -Wall -Wextra -I.

# Source files
SRCS = app.c findfilepath.c

# Object files
OBJS = $(SRCS:.c=.o)

# Static library
LIBRARY = findfilepathlib.a

# Default target
all: $(LIBRARY)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create static library from object files
$(LIBRARY): $(OBJS)
	ar rcs $@ $^

# Clean
clean:
	rm -f $(OBJS) $(LIBRARY)
