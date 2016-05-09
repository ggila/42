
NAME = serialization

SRCSFILES = serialization.cpp

INCLUDES = -I ./
SRCPATH = .
OBJPATH = obj
CC = g++
CFLAGS = -Werror -Wall -Wextra
RM = rm -rf

SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))
OBJECTS = $(SRC:$(SRCPATH)/%.cpp=$(OBJPATH)/%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(OBJECTS)

$(OBJECTS): $(OBJPATH)/%.o : $(SRCPATH)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<

clean:
	$(RM) $(OBJPATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all
