CC = clang
CFLAGS = -std=c23 -Wall -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lhpdf
OUT = resume_builder

all:
	$(CC) main.c $(CFLAGS) $(LDFLAGS) -o $(OUT)

install:
	sudo cp $(OUT) /usr/local/bin/$(OUT)

clean:
	rm -f $(OUT)
