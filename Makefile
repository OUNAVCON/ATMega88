.SUFFIXES:
.SUFFIXES: .c .s .obj

@OS = $(shell echo %OS%)

ifeq ($(OS),Windows_NT)
  ARM = "C:\Users\isaac.rose\Downloads\embedded\Microchip\avr-gcc\avr8-gnu-toolchain\bin"
  #SEGGER = "C:\Program Files (x86)\SEGGER\JLink_V620e\JLink.exe"
  MV = "mv"
else
  AVR = /opt/gcc-arm/bin/arm-none-eabi
  AVRDUDE = /opt/SEGGER/JLink/JLinkExe
  MV = mv 
endif




#ARM = /opt/gcc-arm/bin/arm-none-eabi

DEVICE = "atmega88"

NAME = main
PROJECT = app
AVR = "avr"
ASM = $(AVR)-as
CC = $(AVR)-gcc
LD = $(AVR)-ld
SIZE = $(AVR)-size

OUT_DIR = build
BUILD_LOG = build.log
SRC_PATH = src
SRC = $(wildcard  $(SRC_PATH)/*.c) 
INC_PATH = includes
CFLAGS = -c  -mmcu=$(DEVICE) -g -fno-common -Wall -ffreestanding -ffunction-sections -fdata-sections -I$(INC_PATH) -I"$(ARM)../includes"
ASMFLAGS = -mthumb  -mmcu=$(DEVICE)
OBJ_CPY = $(ARM)-objcopy
LDFLAGS = -T lnk.ld -nostartfiles -nostdlib -Map=$(PROJECT).map 
DEPENDENCIES = $(subst .c,.d,$(SRC))

#SEGGER = /opt/SEGGER/JLink/JLinkExe

%.o: %.c
	@echo Compiling $<
	@echo >> ${BUILD_LOG}
	@echo $(CC) $(CFLAGS) -o $@ $< >> ${BUILD_LOG}
	@$(CC) $(CFLAGS) -o $@ $< >> ${BUILD_LOG}

OBJ = $(subst .c,.o,$(SRC))
#OBJ2 = $(subst $(SRC_PATH),$(OUT_DIR),$(subst .c,.o,$(SRC)))

all: $(PROJECT).bin $(OUT_DIR)
#	@echo $(OBJ2)
	@$(MV) $(PROJECT).map $(PROJECT).elf $(PROJECT).bin $(OBJ) $(BUILD_LOG) $(OUT_DIR)/
	@echo Code Size
#	@echo $(SIZE) $(OUT_DIR)/$(PROJECT).bin
	@$(SIZE) $(OUT_DIR)/$(PROJECT).elf

$(PROJECT).elf: $(OBJ)
	@echo Linking $@
	@echo >> ${BUILD_LOG}
#	@echo ${LD} ${LDFLAGS} ${OBJ} >> ${BUILD_LOG}
	@${LD} ${LDFLAGS} ${OBJ} -o $@ >> ${BUILD_LOG}
	@echo Created File: $@

$(PROJECT).bin: $(PROJECT).elf
#	@echo Creating Binary $<
	@echo >> ${BUILD_LOG}
#	@echo $(OBJ_CPY) -O binary $< $@ >> ${BUILD_LOG}
	@$(OBJ_CPY) -O binary $< $@ >> ${BUILD_LOG}
#	@echo Created File: $@


$(OUT_DIR):
	@echo Creating Build DIR
	@mkdir -p $@

debug:
#	@$(CFLAGS) = $(CFLAGS) -g3 -ggdb
#	@$(all)
#	@$(GDB) 

flash:
	#@$(SEGGER) -si swd -device ATSAMD10D13AS -speed auto -CommanderScript ./seggerScript.jlink
	@$(AVRDUDE)
 
clean:
	@echo Removing Build Files
	@rm -rf ${OUT_DIR}/*

.PHONY: all clean test flash debug

 
