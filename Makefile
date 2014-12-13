include makerules/os.mk

SRCDIR=src
BUILDDIR=build
BINDIR=bin
SOURCES:=$(wildcard src/*.cpp)
OBJS:=$(addprefix $(BUILDDIR)/,$(notdir $(SOURCES:.cpp=.o)))
CXX_FLAGS=-Wall -Wextra -Werror -MMD -Iinclude -std=c++11

$(BINDIR)/numberGuesser2$(BINEXTENSION): $(OBJS) $(BINDIR)
	$(CC) $(OBJS) -o $@

clean:
	$(RMDIR) $(BUILDDIR) $(BINDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(BUILDDIR)
	$(CC) $(CXX_FLAGS) -c $< -o $@

$(BUILDDIR):
	$(MKDIR) $(BUILDDIR)

$(BINDIR):
	$(MKDIR) $(BINDIR)

-include $(OBJS:.o=.d)
