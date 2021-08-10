CXX=g++
IDIR=lib
CFLAGS=-Wall -O2 -std=c++11 -I$(IDIR)

UDIR=utils
CFILES=Utils.cpp Structs.cpp Registry.cpp Dealer.cpp
CFILES:=$(patsubst %.cpp,$(UDIR)/%.cpp,$(CFILES))

DEPS=$(wildcard $(IDIR)/*.hh)

ODIR=obj
OBJ:=$(patsubst $(UDIR)/%.cpp,$(ODIR)/%.o,$(CFILES))


CDIR=strategies
EXTRA_CFILES=$(wildcard $(CDIR)/Strategy*.cpp)
CFILES += $(EXTRA_CFILES)

EXTRA_OBJ:=$(patsubst $(CDIR)/%.cpp,$(ODIR)/%.o,$(EXTRA_CFILES))
OBJ += $(EXTRA_OBJ)


all: create_dir environment.exe

create_dir:
	chmod +x create_dir.sh
	bash create_dir.sh

create_header:
	chmod +x create_headers.sh
	bash create_headers.sh

$(ODIR)/%.o: $(UDIR)/%.cpp $(IDIR)/%.hh
	$(CXX) -c -o $@ $< $(CFLAGS) 

$(ODIR)/%.o: $(CDIR)/%.cpp $(IDIR)/%.hh
	$(CXX) -c -o $@ $< $(CFLAGS) 

environment.o: environment.cpp $(OBJ)
	$(CXX) -c -o $@ $< $(CFLAGS) 

environment.exe: environment.o $(OBJ)
	$(CXX) $(CFLAGS) $^ -o $@

m='Auto'
git_upload:
	git add -A
	git commit -m "$(m)"
	git push

.PHONY: clean
clean:
	rm -rf $(ODIR)/*.o *.exe