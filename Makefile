FIRMWAREREPO := FEH/fehproteusfirmware
LIBRARYREPO := FEH/simulator_libraries

all:
	@echo Please specify a target.
	@echo "mingw32-make simulator" or
	@echo "mingw32-make physical"

ifeq ($(OS),Windows_NT)	
	SHELL := CMD
endif

simulator:
ifeq ($(OS),Windows_NT)	
	@cd $(LIBRARYREPO) && mingw32-make
else
	@cd $(LIBRARYREPO) && make
endif

TARGET = Proteus
physical:
ifeq ($(OS),Windows_NT)	
	@cd $(FIRMWAREREPO) && mingw32-make all TARGET=$(TARGET)
	@cd $(FIRMWAREREPO) && mingw32-make deploy TARGET=$(TARGET)
else
	@cd $(FIRMWAREREPO) && make all TARGET=$(TARGET)
	@cd $(FIRMWAREREPO) && make deploy TARGET=$(TARGET)
endif

clean:

# Simulator
ifeq ($(OS),Windows_NT)	
	@cd $(LIBRARYREPO) && mingw32-make clean
else
	@cd $(LIBRARYREPO) && make clean
endif

# Proteus
ifeq ($(OS),Windows_NT)	
	@cd $(FIRMWAREREPO) && mingw32-make clean TARGET=$(TARGET)
else
	@cd $(FIRMWAREREPO) && make clean TARGET=$(TARGET)
endif
