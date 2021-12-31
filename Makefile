SHELL    := /bin/bash
#TOPDIR   := $(shell dirname $(abspath $(lastword $(MAKEFILE_LIST))))/
TOPDIR   := # Set this to an actual value if the makefile is not in the root.
SRCDIR   := $(TOPDIR)src/
OBJDIR   := $(TOPDIR)bin/
OUTDIR   := $(TOPDIR)
NAME     := $(shell cat $(TOPDIR).g++out 2> /dev/null || (read -p "Enter an executable name: " module && echo $$module | tee $(TOPDIR).g++out))
EXE      := $(OUTDIR)$(NAME)
FDEBUG   := $(shell cat $(TOPDIR).debug 2> /dev/null || echo 0)

# Everything below this point is generic and could be put into a common
# make include file to be included in other makefiles.

SFILES   := cpp
OFILES   := o
DFILES   := d
CC       := g++
CFLAGS   := -std=c++17 -MMD -Wall -Wextra -Werror
LFLAGS   :=

# Persist the DEBUG flag if necessary.
ifdef DEBUG
ifneq ($(FDEBUG),$(DEBUG))
$(shell echo $(DEBUG) > $(TOPDIR).debug)
endif
else
DEBUG := $(FDEBUG)
endif

ifeq ($(DEBUG),1)
$(info (Running in debug mode...))
CFLAGS += -fsanitize=address -DDEBUG -g
LFLAGS += -fsanitize=address
else
$(info (Running in release mode...))
CFLAGS += -O2
endif

SOURCES := $(wildcard $(SRCDIR)**/*.$(SFILES)) $(SRCDIR)main.cpp
OBJECTS := $(patsubst $(SRCDIR)%$(SFILES), $(OBJDIR)%$(OFILES), $(SOURCES))
DEPENDENCIES := $(wildcard $(OBJDIR)**/*.$(DFILES))

ALLFILES := $(SOURCES)

.PHONY: all clean deepclean grammar help

all: $(EXE)
	@:

noop: ;
	@:

help: ;
	@echo "*** ChatLang Makefile ***"
	@echo
	@echo "Targets:"
	@echo " all         build the ChatLang executable"
	@echo " clean       remove the ChatLang binary files"
	@echo " deepclean   fully clean the working directory"
	@echo " grammar     rebuild the parser on grammar change"
	@echo " help        print this help message"
	@echo
	@echo "Variable flags:"
	@echo " DEBUG       if 1, enable ASan and the DEBUG macro"

.debug: ;
	@echo $(DEBUG) > $(TOPDIR).debug

$(EXE): $(OBJECTS)
	$(info Linking...)
	$(info $@)
	@mkdir -p $(OBJDIR)
	@$(CC) $(LFLAGS) $^ -o $@

$(OBJDIR)%$(OFILES): $(SRCDIR)%$(SFILES) $(TOPDIR).debug
	$(info Compiling $<...)
	@mkdir -p $(OBJDIR)
	@mkdir -p $(dir $(firstword $@))
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(TOPDIR).

clean:
	@rm -f $(OBJECTS) $(EXE)
	@echo Build is now clean.

deepclean: clean
	@rm -f $(TOPDIR).g++out
	@rm -f $(TOPDIR).debug
	@echo Workdir is now clean.

pgen: tools/pgen/main.cpp
	$(info Compiling...)
	@$(CC) tools/pgen/main.cpp -o pgen

src/parse/parser.cpp: pgen src/lang.cfg
	$(info Building automaton...)
	@./pgen --nt-only < src/lang.cfg > src/parse/.nt_def.hpp
	@if ! diff src/parse/.nt_def.hpp src/parse/nt_def.hpp > /dev/null; then cp src/parse/.nt_def.hpp src/parse/nt_def.hpp; fi
	@rm src/parse/.nt_def.hpp
	@./pgen < src/lang.cfg > src/parse/parser.cpp

grammar: src/parse/parser.cpp

include $(DEPENDENCIES)
