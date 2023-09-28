TARGET = pat
SRCS = pat.c file.c
OBJS = ${SRCS:.c=.o}

CXX = gcc
CFLAGS =  -Wall -Wextra --pedantic-errors

INSTALL = /usr/bin/install -c -D
BIN_DIR = /usr/bin

all: ${TARGET}

.PHONY: clean
clean:
	- rm -f ${TARGET} ${OBJS} config.h
 
.PHONY: install
install: all
	@echo "Installing ${BIN_DIR}/${TARGET} ..."
	${INSTALL} ${TARGET} "${BIN_DIR}/${TARGET}"

.PHONY: uninstall
uninstall:
	- rm "${BIN_DIR}/${TARGET}"

${TARGET}: ${OBJS}
	${CXX} -g -o $@ ${OBJS} 
pat.o:	file.h config.h
file.o: file.h

