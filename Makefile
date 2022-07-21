  CC		= 	gcc
  LIBA		=	libstd.a
  LIBG		=	lisgraph.a
  MOD           =       rayon

  BIN           =       rayon
  FLAG          =       -W -Wall -Werror -Wextra -Wundef -g -s -std=c11

  INCLUDE       =       -I./include/ -I./include/graph/ -I./include/lib/ -I./include/gui/
  SRC           =       $(shell find ./ -name "*.c")
  OBJ           =       $(SRC:.c=.o)
  LIBPATH       =       -L${HOME}/.froot/lib/
  LIB           =       -llapin -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lstdc++ -lm -ldl -lpthread -lopencv_imgproc -lopencv_objdetect -lopencv_video -lopencv_core -l\
avcall -lusb

  all:          bin
  bin:          $(OBJ)
	@$(CC) $(OBJ) -o $(BIN) $(LIB) 
	@echo ${YELLOW} "[FINISHED] " ${DEFAULT} $(BIN)

  complib:      $(OBJ)
	@$(CC) $(OBJ) -o $(BIN) $(LIBA) #$(LIBG) $(LIB)
	@echo ${YELLOW} "[FINISHED] " ${DEFAULT} $(BIN)

  lib:          $(OBJ)
	@ar cr $(LIBA) $(OBJ)
	@ranlib $(LIBA)
	@echo ${PURPLE} "[DONE]" ${DEFAULT}

  .c.o:
	@$(CC) $(INCLUDE) $(FLAG) -c $< -o $@
	@echo ${GREEN} "[OK]" ${DEFAULT} $< 
  clean:
	@rm -f $(OBJ)
	@echo ${PURPLE} "[CLEANED]"
  fclean:       clean
	@rm -f $(BIN)
  re:           fclean all

  .PHONY: all clean fclean re

  .SUFFIXES: .cpp .o

# Colors                                                                                                                                                                                             
DEFAULT = "\033[00m"
GREEN = "\033[1;32m"
TEAL = "\033[1;36m"
RED = "\033[1;31m"
BLACK = "\033[1;30m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
PURPLE = "\033[1;35m"
WHITE = "\033[1;37m"
