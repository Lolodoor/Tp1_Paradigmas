# Compilador y banderas
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Archivos fuente
SRC = \
    main.cpp \
    personajes/guerreros/barbaro/barbaro.cpp \
    personajes/guerreros/paladin/paladin.cpp \
    personajes/guerreros/gladiador/gladiador.cpp \
    personajes/guerreros/guerreros.cpp \
    personajes/guerreros/caballero/caballero.cpp \
    personajes/guerreros/mercenario/mercenario.cpp \
    armas/magicas/amuleto/amuleto.cpp \
    armas/magicas/libro_de_hechizos/libro_de_hechizos.cpp \
    armas/magicas/pocion/pocion.cpp \
    armas/magicas/baston/baston.cpp \
    armas/magicas/magicas.cpp \
    armas/combate/combate.cpp \
    armas/combate/espada/espada.cpp \
    armas/combate/hacha_simple/hacha_simple.cpp \
    armas/combate/hacha_doble/hacha_doble.cpp \
    armas/combate/garrote/garrote.cpp \
    armas/combate/lanza/lanza.cpp \
    personajes/magos/magos.cpp \
    personajes/magos/hechicero/hechicero.cpp \
    personajes/magos/conjurador/conjurador.cpp \
    personajes/magos/brujo/brujo.cpp \
    personajes/magos/nigromante/nigromante.cpp 

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
