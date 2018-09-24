CC=avr-gcc
MCU=attiny24a
FLAGS=-mmcu=$(MCU)
TARGET=$(MCU)


SRC=$(shell cd src && ls *.c)
COLOR_GREEN=\033[0;32m
COLOR_OFF=\033[0m

.PHONY: all
all: $(addprefix obj/$(TARGET)/,$(SRC:.c=.o))
	$(CC) $(FLAGS) $(INC) $^ -o torque.bin
	@echo "$(COLOR_GREEN) Built firmware for $(TARGET) $(COLOR_OFF)"

obj/$(TARGET):
	mkdir -p $@

obj/$(TARGET)/%.o: src/%.c obj/$(TARGET)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

.PHONY: clean
clean:
	rm -rf torque.bin obj
