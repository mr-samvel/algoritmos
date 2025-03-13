CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2

all:
	@if [ -z "$(file)" ]; then \
		echo "Usage:"; \
		echo "  make file=path/to/file.cpp  - Run a specific C++ file"; \
		echo "  make clean                  - Remove all compiled executables"; \
	else \
		$(MAKE) run; \
	fi

run:
	@if [ -z "$(file)" ]; then \
		exit 1; \
	fi
	@if [ ! -f "$(file)" ]; then \
		echo "Error: File '$(file)' not found"; \
		exit 1; \
	fi
	@filename="$$(basename "$(file)" .cpp)" && \
	$(CXX) $(CXXFLAGS) -o "$${filename}" "$(file)" && \
	echo "Successfully compiled to $${filename}" && \
	echo "" && \
	echo "Running $${filename}..." && \
	echo "========== OUTPUT ==========" && \
	./"$${filename}" && \
	echo "============================="
	
clean:
	@find . -type f -executable -delete
	
.PHONY: all run clean