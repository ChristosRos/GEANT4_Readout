name := readout
G4TARGET := $(name)
G4EXLIB := true

ifndef G4INSTALL
	G4INSTALL = ../../../..
endif

.PHONY: all
all: lib bin

include $(G4INSTALL)/opt/local/share/Geant4/Geant4-10.3.3/geant4make/config/architecture.gmk 

include $(G4INSTALL)/opt/local/share/Geant4/Geant4-10.3.3/geant4make/config/binmake.gmk 

visclean:
	rm -f g4*.prim g4*.eps g4*.wrl
	rm -f .DAWN_*