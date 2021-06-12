HEADERS = config.h func.h 
default: smp 
all: smp

smp.o: smp.c $(HEADERS)
	gcc -c smp.c -o smp.o

smp: smp.o
	gcc smp.o -o smp 

clean:
	-rm -f smp.o
	-rm -f smp 


install: all 
	@echo installing executable file to ${DESTDIR}${PREFIX}/usr/local/bin
	@mkdir -p ${DESTDIR}${PREFIX}/usr/local/bin
	@cp -f smp ${DESTDIR}${PREFIX}/usr/local/bin
	@chmod 755 ${DESTDIR}${PREFIX}/usr/local/bin/smp
	@chmod u+s ${DESTDIR}${PREFIX}/usr/local/bin/smp


uninstall:
	@echo removing executable file from ${DESTDIR}${PREFIX}/bin
	@rm -f ${DESTDIR}${PREFIX}/usr/local/bin/smp
	@rm -f ${DESTDIR}${PREFIX}/usr/local/bin/smp
