CC = g++
CXXFLAGS = -I. -no-pie -Wall
DEPS = crypt.h

ODIR = obj

BIN = XORCrypt

_OBJ = main.o crypt.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS)

XORCrypt: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BIN)
