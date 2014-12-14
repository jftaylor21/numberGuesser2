MAKERULESDIR=makerules
include $(MAKERULESDIR)/os.mk

ENGINEDIR=engine
include $(ENGINEDIR)/engine.mk

BUILDDIR=build
BINDIR=bin
CXX_FLAGS=-Wall -Wextra -Werror -MMD -Iinclude $(ENGINE_INCLUDES) -std=c++11

SRCDIR=src
SOURCES:=$(wildcard src/*.cpp)
OBJS:=$(addprefix $(BUILDDIR)/,$(notdir $(SOURCES:.cpp=.o)))

$(BINDIR)/numberGuesser2$(BINEXTENSION): $(OBJS) | $(BINDIR)
	$(CC) $(OBJS) $(ENGINE_LIBS) -o $@ -Wl,-rpath,.
	$(CP) $(ENGINE_BINDIR)/* $(BINDIR)

clean:
	$(RMDIR) $(BUILDDIR) $(BINDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CC) $(CXX_FLAGS) -c $< -o $@

$(BUILDDIR):
	$(MKDIR) $(BUILDDIR)

$(BINDIR):
	$(MKDIR) $(BINDIR)

-include $(OBJS:.o=.d)
