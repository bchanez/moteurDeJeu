EXENAME := app
ARG :=

DIRECSRC := ./src
DIRECBIN := ./bin
DIRECOBJ := ./obj

CC := g++ -std=c++14 -g#-O3 -s
CFLAGS := -Wall -Wextra

LIBS := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
INCLUDES :=

SRC := $(shell find $(DIRECSRC) -name '*.cpp')
OBJ := $(SRC:.cpp=.o)


all: $(EXENAME) install

$(EXENAME): $(OBJ)
	@echo "** Building the game"
	$(CC) -o $(DIRECSRC)/$@ $^ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

install:
	@echo "** Installing..."
	sh ./rsc/Tools/create_directories.sh
	cp $(DIRECSRC)/$(EXENAME) $(DIRECBIN)
	cp $(OBJ) $(DIRECOBJ)
	chmod u+x $(DIRECBIN)/$(EXENAME)

clean:
	@echo "** Removing object files and executable..."
	rm -f $(OBJ)
	rm -f $(DIRECSRC)/$(EXENAME)

execute:
	@echo "** start the game.."
	$(DIRECBIN)/$(EXENAME) $(ARG)
