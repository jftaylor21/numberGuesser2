MAKERULESDIR=../makerules
include $(MAKERULESDIR)/os.mk

BUILDDIR=build
BINDIR=bin
CXX_FLAGS=-Wall -Wextra -Werror -MMD -Iinclude -std=c++11 -fPIC

SRCDIR=src
SOURCES:=$(wildcard src/*.cpp)
OBJS:=$(addprefix $(BUILDDIR)/,$(notdir $(SOURCES:.cpp=.o)))

$(BINDIR)/libengine$(SOEXTENSION): $(OBJS) | $(BINDIR)
	$(CC) $(OBJS) -shared -o $@

clean:
	$(RMDIR) $(BUILDDIR) $(BINDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CC) $(CXX_FLAGS) -c $< -o $@

$(BUILDDIR):
	$(MKDIR) $(BUILDDIR)

$(BINDIR):
	$(MKDIR) $(BINDIR)

-include $(OBJS:.o=.d)
