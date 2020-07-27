CC = g++
CXXFLAGS = -I. -no-pie -Wall
DEPS = crypt.h

ODIR = obj

BIN = XORCrypt

_OBJ = main.o crypt.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

.SECONDEXPANSION:

$(ODIR)/%.o: %.cpp $(DEPS) | $$(@D)
	$(CC) -c -o $@ $< $(CXXFLAGS)

XORCrypt: $(OBJ) | $$(@D)
	$(CC) -o $@ $^ $(CXXFLAGS)

$(ODIR):
	mkdir -p $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BIN)
