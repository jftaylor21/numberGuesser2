SRCDIR=src
BUILDDIR=build
SOURCES:=$(wildcard src/*.cpp)
OBJS:=$(addprefix build/,$(notdir $(SOURCES:.cpp=.o)))
CXX_FLAGS=-Wall -Wextra -Werror -MMD -Iinclude -std=c++11
CC=g++

numberGuesser2: $(OBJS)

clean:
	rm -f $(OBJS)

build/%.o: src/%.cpp $(BUILDDIR)
	$(CC) $(CXX_FLAGS) -c $< -o $@

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

-include $(OBJS:.o=.d)
