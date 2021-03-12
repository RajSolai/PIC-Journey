all: hex clean move

hex:
	xc8 --chip=$(chip) $(file)

clean:
	rm -f *.elf *.sdb *.lst *.p1 *.cmf *.sym *.d *.pre *.obj *.rlf *.as *hxl

move:
	cp main.hex /home/$(USER)/apps/pk2cmdv1.20LinuxMacSource

