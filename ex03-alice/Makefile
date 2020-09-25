EXECUTABLE := ex03alice
INSTRUCTOR_MAIN := instructor_main
SRC_DIR := .
OBJ_DIR := .
LDFLAGS := 
CPPFLAGS :=
CXXFLAGS :=

all: Node.o AliceMain.o
	g++ -o $(EXECUTABLE) $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

test-all: test01out.txt test02out.txt test03out.txt test04out.txt test05out.txt

test01out.txt: 
	./$(EXECUTABLE) < test01in.txt > test01out.txt
	diff -i -B test01out.txt test01expected.txt

test02out.txt: 
	./$(EXECUTABLE) < test02in.txt > test02out.txt
	diff -i -B test02out.txt test02expected.txt

test03out.txt: 
	./$(EXECUTABLE) < test03in.txt > test03out.txt
	diff -i -B test03out.txt test03expected.txt

test04out.txt: 
	./$(EXECUTABLE) < test04in.txt > test04out.txt
	diff -i -B test04out.txt test04expected.txt

test05out.txt: 
	./$(EXECUTABLE) < test05in.txt > test05out.txt
	diff -i -B test05out.txt test05expected.txt

# Delete dependent files
# You can type "make clean" before committing to Git
clean:
	rm -f $(EXECUTABLE)
	rm -f *.o
	rm -f *out.txt

# Build a testcase to check Node API
instr-all: Node.o InstructorMain.o
	g++ -o $(INSTRUCTOR_MAIN) $^
	./$(INSTRUCTOR_MAIN)

