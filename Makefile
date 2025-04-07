# Compilador y banderas
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Archivos fuente
SRC = \
    ejercicio2/main.cpp \
    ejercicio2/personajes/guerreros/barbaro/barbaro.cpp \
    ejercicio2/personajes/guerreros/paladin/paladin.cpp \
    ejercicio2/personajes/guerreros/gladiador/gladiador.cpp \
    ejercicio2/personajes/guerreros/guerreros.cpp \
    ejercicio2/personajes/guerreros/caballero/caballero.cpp \
    ejercicio2/personajes/guerreros/mercenario/mercenario.cpp \
    ejercicio2/armas/magicas/amuleto/amuleto.cpp \
    ejercicio2/armas/magicas/libro_de_hechizos/libro_de_hechizos.cpp \
    ejercicio2/armas/magicas/pocion/pocion.cpp \
    ejercicio2/armas/magicas/baston/baston.cpp \
    ejercicio2/armas/magicas/magicas.cpp \
    ejercicio2/armas/combate/combate.cpp \
    ejercicio2/armas/combate/espada/espada.cpp \
    ejercicio2/armas/combate/hacha_simple/hacha_simple.cpp \
    ejercicio2/armas/combate/hacha_doble/hacha_doble.cpp \
    ejercicio2/armas/combate/garrote/garrote.cpp \
    ejercicio2/armas/combate/lanza/lanza.cpp 



# Archivos objeto
OBJ = $(SRC:.cpp=.o)

# Nombre del ejecutable
EXEC = programa

# Regla principal
.PHONY: all clean
all: clean $(EXEC)

# Compilar el ejecutable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar archivos .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJ) $(EXEC)
