SRCDIR=src
BUILDDIR=build
BINDIR=bin
SOURCES:=$(wildcard src/*.cpp)
OBJS:=$(addprefix build/,$(notdir $(SOURCES:.cpp=.o)))
CXX_FLAGS=-Wall -Wextra -Werror -MMD -Iinclude -std=c++11
CC=g++

numberGuesser2: $(OBJS) $(BINDIR)
	$(CC) $(OBJS) -o $(BINDIR)/numberGuesser2

clean:
	rm -rf $(BUILDDIR) $(BINDIR)

build/%.o: src/%.cpp $(BUILDDIR)
	$(CC) $(CXX_FLAGS) -c $< -o $@

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

-include $(OBJS:.o=.d)
