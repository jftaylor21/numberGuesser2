SRCDIR=src
BUILDDIR=build
SOURCES:=$(wildcard src/*.cpp)
OBJS:=$(addprefix build/,$(notdir $(SOURCES:.cpp=.o)))
CXX_FLAGS=-Wall -Wextra -Werror -MMD -Iinclude -std=c++11
CC=g++

numberGuesser2: $(OBJS)
	$(CC) $^ -o $(BUILDDIR)/numberGuesser2

clean:
	rm -f $(OBJS)

build/%.o: src/%.cpp $(BUILDDIR)
	$(CC) $(CXX_FLAGS) -c $< -o $@

$(BUILDDIR):
	rm -rf $(BUILDDIR)

-include $(OBJS:.o=.d)
