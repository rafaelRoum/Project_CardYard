# === Configuration ===
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I./src
TARGET = main
SRCDIRS = src/affichage src/gestionnaire src/joueur src/pioche src/systeme src/controles

# === Fichiers Sources et Objets ===
SRC = main.c $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))
OBJ = $(SRC:.c=.o)

# === Règles Principales ===
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# === Nettoyage ===
clean:
	rm -f $(OBJ) $(TARGET)

# === Exécution ===
run: all
	./$(TARGET)

.PHONY: all clean run
