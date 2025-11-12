# Makefile for Lambda laboratory

# ----------------- #
#  Configuration    #
# ----------------- #

# Compiler
CXX := g++

# Executable Name
TARGET := lambda

# Source files
SRCS := main.cpp

# Includes

# INCLUDES := 

# Compiler flags
CXXFLAGS := -std=c++20 -g -Wall -Wextra $(INCLUDES)


# Linker flags (-l)
# LDFLAGS :=

# ----------------- #
#  Build Rules      #
# ----------------- #

# Build target
$(TARGET): $(SRCS)
	@echo "🔗 Linking executable..."
	$(CXX) $^ -o $@ $(CXXFLAGS) $(LDFLAGS)
	@echo "✅ Build finished: ./$(TARGET)"

# Clean target

.PHONY: clean
clean:
	@echo "🧹 Cleaning up..."
	rm -f $(TARGET)
	@echo "✅ Clean finished."