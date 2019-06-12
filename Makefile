CC        := g++
LL        := g++
CFLAGS    := -c
#LFLAGS    := -lpthread #-lm

EXECPATH  := Builds
SRCPATH   := Sources
STRUCTURE := $(shell find $(SRCPATH) -type d)

SRCFILES  := $(addsuffix /* , $(STRUCTURE))
SRCFILES  := $(wildcard $(SRCFILES))

CFILES 	  := $(filter %.cpp,$(SRCFILES))
HDRFILES  := $(filter %.h,$(SRCFILES))
OBJFILES  := $(CFILES:%.cpp=%.o)
OBJFILES  := $(filter-out src/init.o, $(OBJFILES))

EXECUTABLE = $(EXECPATH)/prjsim2
DEBUGGUBLE = $(EXECPATH)/prjsim2debug

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJFILES)
	$(LL) $(LFLAGS) $(OBJFILES) -o $@

%.o:%.cpp
	$(CC) $(CFLAGS) $< -o $@

debug: $(DEBUGGUBLE)

$(DEBUGGUBLE): $(OBJFILES)
	$(LL) $(LFLAGS) $(OBJFILES) -g -o $@

clean:
	rm $(OBJFILES)

.PHONY : clean