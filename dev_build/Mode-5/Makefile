#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------

ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM")
endif

include $(DEVKITARM)/gba_rules

PROJECT_NAME	:= CoreGBA_dev_build
OBJ_DIR			:= obj

PROJECT_SRC   := src $(addprefix src/, utils keys graphics_context graphics tasks system)
PROJECT_INC   := includes

SOURCES       := $(PROJECT_SRC)
INCLUDES      := $(PROJECT_INC)


DATA		:=
MUSIC		:=
OBJCOPY		= arm-none-eabi-objcopy
OBJSTRIP	= arm-none-eabi-strip
ARCH		:=	-mthumb -mthumb-interwork
CXXFLAGS	:=	-g -Wall -O3 -Xlinker -Wl,-Map=output.map -mcpu=arm7tdmi \
				-mtune=arm7tdmi $(ARCH) $(INCLUDE) -fno-rtti -fno-exceptions
ASFLAGS		:=	-g $(ARCH)
LDFLAGS		=	-g $(ARCH) -Wl,-Map,$(notdir $*.map)
LIBS		:= -lmm -lgba
LIBDIRS	:=	$(LIBGBA)

ifneq ($(OBJ_DIR),$(notdir $(CURDIR)))

export V 	:= 1

export OUTPUT	:=	$(CURDIR)/$(PROJECT_NAME)

export VPATH	:=	$(foreach dir,$(SOURCES),$(CURDIR)/$(dir)) \
			$(foreach dir,$(DATA),$(CURDIR)/$(dir)) \
			$(foreach dir,$(GRAPHICS),$(CURDIR)/$(dir))

export DEPSDIR	:=	$(CURDIR)/$(OBJ_DIR)

CFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
SFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))
BINFILES	:=	$(foreach dir,$(DATA),$(notdir $(wildcard $(dir)/*.*)))

ifneq ($(strip $(MUSIC)),)
	export AUDIOFILES	:=	$(foreach dir,$(notdir $(wildcard $(MUSIC)/*.*)),$(CURDIR)/$(MUSIC)/$(dir))
	BINFILES += soundbank.bin
endif


ifeq ($(strip $(CPPFILES)),)
	export LD	:=	$(CC)
else
	export LD	:=	$(CXX)
endif

export OFILES_BIN := $(addsuffix .o,$(BINFILES))

export OFILES_SOURCES := $(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(SFILES:.s=.o)

export OFILES := $(OFILES_BIN) $(OFILES_SOURCES)

export HFILES := $(addsuffix .h,$(subst .,_,$(BINFILES)))

export INCLUDE	:=	$(foreach dir,$(INCLUDES),-iquote $(CURDIR)/$(dir)) \
					$(foreach dir,$(LIBDIRS),-I$(dir)/include) \
					-I$(CURDIR)/$(OBJ_DIR)

export LIBPATHS	:=	$(foreach dir,$(LIBDIRS),-L$(dir)/lib)

.PHONY: $(OBJ_DIR) clean re

$(OBJ_DIR):
	@printf "$(COLOR_CYAN)Creating directory $(OBJ_DIR)$(COLOR_RESET)\n"
	@[ -d $@ ] || mkdir -p $@
	@$(MAKE) --no-print-directory -C $(OBJ_DIR) -f $(CURDIR)/Makefile

re: clean $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)/*
	@rm -fr $(PROJECT_NAME).elf $(PROJECT_NAME).gba
	@printf "$(COLOR_BOLD)$(COLOR_YELLOW)All .o files and build removed.$(COLOR_RESET)\n"

else
#Strip data
#--strip-all
#--strip-unneeded
$(OUTPUT).gba	:	$(OUTPUT).elf
#	@$(OBJSTRIP) --strip-all $(OUTPUT).elf
	@$(OBJCOPY) -O binary $(OUTPUT).elf $(OUTPUT).gba
	@printf "$(COLOR_BOLD)$(COLOR_MAGENTA)Compilation done.$(COLOR_RESET)\n"
#	@mgba-qt $(OUTPUT).gba > /dev/null 2>&1

$(OUTPUT).elf	:	$(OFILES)

$(OFILES_SOURCES) : $(HFILES)

soundbank.bin soundbank.h : $(AUDIOFILES)
	@mmutil $^ -osoundbank.bin -hsoundbank.h

%.bin.o	%_bin.h :	%.bin
	@echo $(notdir $<)
	@$(bin2o)


-include $(DEPSDIR)/*.d
endif
