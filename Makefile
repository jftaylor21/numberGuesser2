MAKERULESDIR=makerules
include $(MAKERULESDIR)/os.mk

BUILDDIR=build
BINDIR=bin
CXX_FLAGS=-Wall -Wextra -Werror -MMD -std=c++11 $(FPIC)

CLI_SRCDIR=src
CLI_SOURCES:=$(wildcard $(CLI_SRCDIR)/*.cpp)
CLI_OBJS:=$(addprefix $(BUILDDIR)/,$(notdir $(CLI_SOURCES:.cpp=.o)))
CLI_INCLUDES=include

ENGINE_SRCDIR=engine/src
ENGINE_SOURCES:=$(wildcard $(ENGINE_SRCDIR)/*.cpp)
ENGINE_OBJS:=$(addprefix $(BUILDDIR)/engine/,$(notdir $(ENGINE_SOURCES:.cpp=.o)))
ENGINE_INCLUDES=engine/include
ENGINE_TARGET=$(BINDIR)/libengine$(SOEXTENSION)

# exeutable rules

$(BINDIR)/numberGuesser2$(BINEXTENSION): $(CLI_OBJS) $(ENGINE_TARGET) | $(BINDIR)
	$(CC) $(CLI_OBJS) -Lbin -lengine -o $@ -Wl,-rpath,.

# so rules

$(ENGINE_TARGET): $(ENGINE_OBJS) | $(BINDIR)
	$(CC) $(ENGINE_OBJS) -shared -o $@

# clean rules

clean:
	$(RMDIR) $(BUILDDIR) $(BINDIR)

# cpp rules

$(BUILDDIR)/engine/%.o: $(ENGINE_SRCDIR)/%.cpp | $(BUILDDIR)/engine
	$(CC) $(CXX_FLAGS) -I$(ENGINE_INCLUDES) -c $< -o $@

$(BUILDDIR)/%.o: $(CLI_SRCDIR)/%.cpp | $(BUILDDIR)
	$(CC) $(CXX_FLAGS) -I$(ENGINE_INCLUDES) -I$(CLI_INCLUDES) -c $< -o $@

# mkdir rules

$(BUILDDIR)/engine: | $(BUILDDIR)
	$(MKDIR) $(BUILDDIR)/engine

$(BUILDDIR):
	$(MKDIR) $(BUILDDIR)

$(BINDIR):
	$(MKDIR) $(BINDIR)

# generate dependency files
-include $(CLI_OBJS:.o=.d)
-include $(ENGINE_OBJS:.o=.d)

