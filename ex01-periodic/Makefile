OUTPUTFILE := periodic
SRC_DIR := .
OBJ_DIR := .
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS := 
CPPFLAGS :=
CXXFLAGS :=

# Default target
all: $(OBJ_FILES)
	g++ $(LDFLAGS) -o $(OUTPUTFILE) $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

# Delete palindromes
clean:
	rm -f $(OUTPUTFILE)
