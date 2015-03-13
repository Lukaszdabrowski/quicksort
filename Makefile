TARGET=			quicksort

CFLAGS=			-Wall \
			-pedantic

SOURCES_DIR=		src
OBJECTS_DIR=		obj

SOURCES_FILES=		main.c \
			measure.c

SOURCES=		$(patsubst \
				%, \
				$(SOURCES_DIR)/%, \
				$(SOURCES_FILES))

OBJECTS=		$(patsubst \
				%.c, \
				$(OBJECTS_DIR)/%.o, \
				$(SOURCES_FILES))

all: \
		$(TARGET)

clean: \
		clean_$(TARGET) \
		clean_$(OBJECTS_DIR)

clean_$(TARGET): \
		clean_%:
	rm \
		-f \
		$*

clean_$(OBJECTS_DIR): \
		clean_%:
	rm \
		-rf \
		$*

$(TARGET): \
		$(OBJECTS)
	gcc \
		-o \
		$@ \
		$^

$(OBJECTS): \
		$(OBJECTS_DIR)/%.o: \
		$(SOURCES_DIR)/%.c | \
		$(OBJECTS_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJECTS_DIR):
	mkdir \
		-p \
		$@

