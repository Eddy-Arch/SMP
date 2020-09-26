HEADERS = config.h src/func.h 
default: smp 

smp.o: smp.c $(HEADERS)
	gcc -c smp.c -o smp.o

smp: smp.o
	gcc smp.o -o smp 

clean:
	-rm -f smp.o
	-rm -f smp 


install: 
	@echo installing executable file to ${DESTDIR}${PREFIX}/bin
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f smp ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/smp
	@chmod u+s ${DESTDIR}${PREFIX}/bin/smp


uninstall:
	@echo removing executable file from ${DESTDIR}${PREFIX}/bin
	@rm -f ${DESTDIR}${PREFIX}/bin/smp
	@rm -f ${DESTDIR}${PREFIX}/bin/smp
