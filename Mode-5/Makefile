#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------

ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM")
endif

include $(DEVKITARM)/gba_rules

TARGET		:= $(notdir $(CURDIR))
BUILD		:= build

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

ifneq ($(BUILD),$(notdir $(CURDIR)))

export V 	:= 1

export OUTPUT	:=	$(CURDIR)/$(TARGET)

export VPATH	:=	$(foreach dir,$(SOURCES),$(CURDIR)/$(dir)) \
			$(foreach dir,$(DATA),$(CURDIR)/$(dir)) \
			$(foreach dir,$(GRAPHICS),$(CURDIR)/$(dir))

export DEPSDIR	:=	$(CURDIR)/$(BUILD)

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
					-I$(CURDIR)/$(BUILD)

export LIBPATHS	:=	$(foreach dir,$(LIBDIRS),-L$(dir)/lib)

.PHONY: $(BUILD) clean re

$(BUILD):
	@[ -d $@ ] || mkdir -p $@
	@$(MAKE) --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile

re: clean $(BUILD)

clean:
	@echo clean ...
	@rm -fr $(BUILD) $(TARGET).elf $(TARGET).gba

else
#Strip data
#--strip-all
#--strip-unneeded
$(OUTPUT).gba	:	$(OUTPUT).elf
#	@$(OBJSTRIP) --strip-all $(OUTPUT).elf
	@$(OBJCOPY) -O binary $(OUTPUT).elf $(OUTPUT).gba
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
