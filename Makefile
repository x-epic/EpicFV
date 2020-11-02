.PHONY: all clean run
default: all

all: yosys
	@make clean; mkdir ./obj
	g++ -I./binary/share/tcl/include/ -c epic_fv_start.cpp -o ./obj/epic_fv_start.o
	g++ ./obj/epic_fv_start.o -Lbinary/share/openmpi/lib -ltcl8.6 -o binary/epic_fv_start
	cp src/yosys/yosys binary/bin/.
	cp src/yosys/yosys-abc binary/bin/.

yosys:
	cd src/yosys; make -j10

clean:
	rm -rf binary/epic_fv_start ./obj

run:
	cd example/run; ../../epic_fv -f demo.tcl
