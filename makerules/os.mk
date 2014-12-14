# This is where OS specific build variables are set

ifeq ($(OS),Windows_NT)
  include $(MAKERULESDIR)/windows.mk
else
  UNAME_S := $(shell uname -s)
  ifeq ($(UNAME_S),Linux)
    include $(MAKERULESDIR)/linux.mk
  else
    $(error Unsupported platform)
  endif
endif

