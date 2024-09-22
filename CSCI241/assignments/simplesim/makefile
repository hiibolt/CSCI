# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Iinclude

# Source and include directories
SRCDIR = src
INCDIR = include
BUILDDIR = build
TESTDIR = tests

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
# Object files
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
# Test files
TESTS = $(wildcard $(TESTDIR)/*.sml) # Assuming your test files are .txt

# Target executable
TARGET = simplesim

# Rules
all: $(BUILDDIR) $(TARGET)

# Create build directory if it doesn't exist
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Link object files to create the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

# Compile source files to object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf $(BUILDDIR)/*.o $(TARGET)

test:
	@for test_file in $(TESTS); do \
		echo "Running test with $$test_file:"; \
		./$(TARGET) < $$test_file; \
	done

run:
	./$(TARGET)

# Phony targets
.PHONY: all clean
