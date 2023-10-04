incspath = include/
srcspath = src/
srcsfiles = nsx_p.c
srcs = $(patsubst %.c, $(srcspath)%.c, $(srcsfiles))
outputs = $(srcsfiles:.c=.o)
flags = -Wall -Wextra -Werror
libname = libnsx_p.a

all: $(outputs)
	ar -crs $(libname) $(outputs)

$(outputs): 
	gcc -c $(srcs) 

clean:
	rm $(outputs)

fclean: clean
	rm $(libname)

re: fclean all

fc: fclean

c: clean

main: 
	gcc $(main) -L. -l$(patsubst lib%.a,% , $(libname)) -o c