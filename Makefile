DEST=~/sketchbook/libraries/RelativeHMC6352

install: RelativeHMC6352.cpp RelativeHMC6352.h
	mkdir -p $(DEST)
	cp -R RelativeHMC6352/* $(DEST)
