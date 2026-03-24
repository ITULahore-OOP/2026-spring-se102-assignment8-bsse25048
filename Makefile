# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Source Files for the core classes
CORE_SRCS = UniversityMember.cpp AccessCard.cpp Student.cpp Staff.cpp TeachingAssistant.cpp TutoringSession.cpp Department.cpp
CORE_OBJS = $(CORE_SRCS:.cpp=.o)

# Executable names
MAIN_EXEC = app
TEST_EXEC = run_tests
GRADE_EXEC = run_grade_tests

# Default Target (Builds the main application)
all: $(MAIN_EXEC)

# Run the main program
run: $(MAIN_EXEC)
	./$(MAIN_EXEC)

# Build the main program
$(MAIN_EXEC): $(CORE_OBJS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build and run the public test executable (using test.cpp)
test: $(CORE_OBJS) test.o
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $^
	./$(TEST_EXEC)

# Build and run the hidden test executable (using test_h.cpp)
grade: $(CORE_OBJS) test_h.o
	$(CXX) $(CXXFLAGS) -o $(GRADE_EXEC) $^
	./$(GRADE_EXEC)

# Compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts (Includes *.exe for Cygwin compatibility)
clean:
	rm -f *.o $(MAIN_EXEC) $(TEST_EXEC) $(GRADE_EXEC) *.exe