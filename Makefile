#---------------------------------------------------------------------------------
# Executable name
#---------------------------------------------------------------------------------
TARGET		=  indie_studio

#---------------------------------------------------------------------------------
# Compiler executables
#---------------------------------------------------------------------------------
CC			=	gcc
CXX			=	g++

#---------------------------------------------------------------------------------
# Compiler flags
#---------------------------------------------------------------------------------
CFLAGS		=	-g -Wall -Wextra -Wfatal-errors -pedantic -MD
CXXFLAGS	=	$(CFLAGS) -std=c++11 -Wno-variadic-macros
LDFLAGS		=	-g

#---------------------------------------------------------------------------------
# Source folders
#---------------------------------------------------------------------------------
find_rec	=	$(shell find $(1) -type d)

BUILD		=	build
SOURCES		=	source external $(call find_rec,source)
INCLUDES	=	include external $(call find_rec,include)

#---------------------------------------------------------------------------------
# Libraries
#---------------------------------------------------------------------------------
LIBS		= -lIrrlicht

#---------------------------------------------------------------------------------
# Additional folders for libraries
#---------------------------------------------------------------------------------
LIBDIRS		=

ifneq ($(BUILD),$(notdir $(CURDIR)))

#---------------------------------------------------------------------------------
# Source files
#---------------------------------------------------------------------------------
export OUTPUT	=	$(CURDIR)/$(TARGET)

export VPATH	=	$(foreach dir,$(SOURCES),$(CURDIR)/$(dir))

export CFILES	=	$(sort $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c))))
export CPPFILES	=	$(sort $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp))))

export OFILES	=	$(CPPFILES:.cpp=.o) $(CFILES:.c=.o)

export INCLUDE	=	$(foreach dir,$(INCLUDES),-I$(CURDIR)/$(dir))
export LIBPATHS	=	$(foreach dir,$(LIBDIRS),-L$(CURDIR)/$(dir))

#---------------------------------------------------------------------------------
# Use CXX for linking C++ projects, CC for standard C
#---------------------------------------------------------------------------------
ifeq ($(strip $(CPPFILES)),)
	export LD	=	$(CC)
else
	export LD	=	$(CXX)
endif

#---------------------------------------------------------------------------------
# Makefile targets
#---------------------------------------------------------------------------------
$(BUILD):
	@[ -d $@ ] || mkdir -p $@
	@make --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile
	@fixmes="$(shell cat $(shell find . -name "*.cpp" -or -name "*.hpp") | grep FIXME | wc -l)" && [ "$$fixmes" != "0" ] && echo $$fixmes "fixme(s) remaining." || echo -n

run: $(BUILD)
	@./$(TARGET) $(RUN_ARGS)

debug: $(BUILD)
	@gdb ./$(TARGET)

clean:
	@echo "Cleaning temporary build files..."
	@rm -rf $(BUILD)

fclean: clean
	@echo "Cleaning executable..."
	@rm -f $(TARGET)

re: fclean $(BUILD)

.PHONY: $(BUILD) run clean fclean re

#---------------------------------------------------------------------------------
else
#---------------------------------------------------------------------------------
all: $(OUTPUT)
	@echo "Done for $(notdir $(OUTPUT))."

$(OUTPUT): $(OFILES)
	@echo "Linking $(notdir $@)..."
	@$(LD) $(OFILES) $(LIBPATHS) $(LIBS) -o $@ $(CXXFLAGS)

%.o: %.c
	@echo "=>" $(notdir $<)
	@$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

%.o: %.cpp
	@echo "=>" $(notdir $<)
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDE)

-include *.d

#---------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------
