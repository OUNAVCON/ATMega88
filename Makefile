.SUFFIXES:
.SUFFIXES: .c .s .obj

@OS = $(shell echo %OS%)

ifeq ($(OS),Windows_NT)
  AVR_PATH = "C:\Users\isaac.rose\Downloads\embedded\Microchip\avr-gcc\avr8-gnu-toolchain\bin"
  AVRDUDE = "C:\Users\isaac.rose\Downloads\embedded\Microchip\avr-gcc\avrDude\avrdude.exe"
  MV = "mv"
else
  AVR_PATH = /opt/gcc-avr/bin
  AVRDUDE = /usr/bin/avrdude
  MV = mv 
endif


DEVICE = "atmega88"

NAME = main
PROJECT = app
AVR = "avr"
ASM = $(AVR_PATH)/$(AVR)-as
CC = $(AVR_PATH)/$(AVR)-gcc
LD = $(AVR_PATH)/$(AVR)-ld
SIZE = $(AVR_PATH/)$(AVR)-size
OBJ_CPY =  $(AVR_PATH)/$(AVR)-objcopy
OBJ_DUMP =  $(AVR_PATH)/$(AVR)-objdump

OUT_DIR = build
BUILD_LOG = build.log
SRC_PATH = src
SRC = $(wildcard  $(SRC_PATH)/*.c)
ASRC = $(wildcard  $(SRC_PATH)/*.S) 
INC_PATH = includes
CFLAGS = -c  -mmcu=$(DEVICE) -g -fno-common -Wall -ffreestanding -ffunction-sections -fdata-sections -I$(INC_PATH) -I"$(ARM)../includes"
ASMFLAGS = -mthumb  -mmcu=$(DEVICE)
LDFLAGS = -T lnk.ld -nostartfiles -nostdlib -Map=$(PROJECT).map 
DEPENDENCIES = $(subst .c,.d,$(SRC))

%.o : %.c
	@echo Compiling $<
	@echo >> ${BUILD_LOG}
	@echo $(CC) $(CFLAGS) -o $@ $< >> ${BUILD_LOG}
	@$(CC) $(CFLAGS) -o $@ $< >> ${BUILD_LOG}

%.o : %.S
	@echo Assembling $<
	@echo >> ${BUILD_LOG}
	@echo $(CC) -c  $< -o $@ >> ${BUILD_LOG}
	@$(CC) -c  $< -o $@ >> ${BUILD_LOG}

OBJ = $(subst .c,.o,$(SRC))  $(subst .S,.o,$(ASRC))
#OBJ2 = $(subst $(SRC_PATH),$(OUT_DIR),$(subst .c,.o,$(SRC)))

all: $(PROJECT).bin $(OUT_DIR)
#	@echo $(OBJ2)
	@$(OBJ_DUMP) -S $(PROJECT).elf > $(PROJECT).lst
	@$(MV) $(PROJECT).map $(PROJECT).elf $(PROJECT).bin $(PROJECT).lst $(OBJ) $(BUILD_LOG) $(OUT_DIR)/
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
#	@$(AVRDUDE) -P COM1 -p m88 -c usbasp -v -U "hfuse:r:<0x12>:m"
#	@$(AVRDUDE) -P COM1 -p m88 -c usbasp -v -U "lfuse:r:<0x12>:m"
#	@$(AVRDUDE) -P COM1 -p m88 -c usbasp -v -U "efuse:r:<0x12>:m"
	@$(AVRDUDE) -P usb -p m88 -c usbasp -v -U "flash:w:build/app.elf:e"
 
 
 
clean:
	@echo Removing Build Files
	@rm -rf ${OUT_DIR}/*

.PHONY: all clean test flash debug

 
