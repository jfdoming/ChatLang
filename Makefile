SHELL    := /bin/bash
#TOPDIR   := $(shell dirname $(abspath $(lastword $(MAKEFILE_LIST))))/
TOPDIR   := # Set this to an actual value if the makefile is not in the root.
SRCDIR   := $(TOPDIR)src/
OBJDIR   := $(TOPDIR)bin/
OUTDIR   := $(TOPDIR)
NAME     := $(shell cat $(TOPDIR).g++out 2> /dev/null || (read -p "Enter an executable name: " module && echo $$module | tee $(TOPDIR).g++out))
EXE      := $(OUTDIR)$(NAME)

# Everything below this point is generic and could be put into a common
# make include file to be included in other makefiles.

SFILES   := cpp
OFILES   := o
DFILES   := d
CC       := g++
CFLAGS   := -std=c++17 -Wall -g -MMD

SOURCES := $(wildcard $(SRCDIR)**/*.$(SFILES))
OBJECTS := $(patsubst $(SRCDIR)%$(SFILES), $(OBJDIR)%$(OFILES), $(SOURCES)) $(OBJDIR)main.o
DEPENDENCIES := $(patsubst $(SRCDIR)%$(SFILES), $(OBJDIR)%$(DFILES), $(SOURCES)) $(OBJDIR)main.d

ALLFILES := $(SOURCES) main.cpp

.PHONY: all clean exe deepclean noop

all: $(EXE)
	@:

noop: ;
	@:

$(EXE): $(OBJECTS)
	$(info Linking...)
	$(info $@)
	@mkdir -p $(OBJDIR)
	@$(CC) $^ -o $@

bin/main.o: main.cpp
	$(info Compiling $<...)
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I ./$(TOPDIR)

$(OBJDIR)%$(OFILES): $(SRCDIR)%$(SFILES)
	$(info Compiling $<...)
	@mkdir -p $(OBJDIR)
	@mkdir -p $(dir $(firstword $@))
	@$(CC) $(CFLAGS) -c $< -o $@ -I ./$(TOPDIR)

clean:
	@rm -f $(OBJECTS) $(EXE)

deepclean: clean
	@rm -f $(TOPDIR).g++out

pgen: tools/pgen/main.cpp
	$(info Compiling...)
	@$(CC) tools/pgen/main.cpp -o pgen

grammar: pgen src/lang.cfg
	$(info Building automaton...)
	@./pgen --nt-only < src/lang.cfg > src/parse/nt_def.hpp
	@./pgen < src/lang.cfg > src/parse/parser.cpp

include $(DEPENDENCIES)
