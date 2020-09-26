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
	#@echo installing manual page to ${DESTDIR}${MANPREFIX}/man1
	#@mkdir -p ${DESTDIR}${MANPREFIX}/man1
	#@sed "s/VERSION/${VERSION}/g" <slock.1 >${DESTDIR}${MANPREFIX}/man1/slock.1
	#@chmod 644 ${DESTDIR}${MANPREFIX}/man1/slock.1


uninstall:
	@echo removing executable file from ${DESTDIR}${PREFIX}/bin
	@rm -f ${DESTDIR}${PREFIX}/bin/smp
	@rm -f ${DESTDIR}${PREFIX}/bin/smp
#	@rm -f ${DESTDIR}${MANPREFIX}/man1/slock.1
