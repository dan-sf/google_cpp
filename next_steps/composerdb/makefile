# Most of this make file was borrowed from the gtest sample code:
# googletest-release-1.8.0/googletest/make/Makefile

# Update this path to point to where the gtest source was extracted
#GTEST_DIR = /PATH/TO/googletest-release-1.8.0/googletest
GTEST_DIR = /Users/dfowler/dev/lib/googletest-release-1.8.0/googletest
USER_DIR = .

CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread

# Targets for main and test
TESTS = tests
MAIN = composer_main

# All Google Test headers for unittesting
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# Main entry point build targets.
all: $(MAIN)

tests: $(TESTS)

clean:
	rm -rf $(MAIN) $(TESTS) gtest.a gtest_main.a *.o *.dSYM

# Builds gtest.a and gtest_main.a.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Testing and main target definitions

composerdb_unittest.o: $(USER_DIR)/composerdb_unittest.cpp database.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/composerdb_unittest.cpp

composer.o: $(USER_DIR)/composer.cpp $(USER_DIR)/composer.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/composer.cpp

database.o: $(USER_DIR)/database.cpp $(USER_DIR)/database.h composer.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/database.cpp

tests: composerdb_unittest.o gtest_main.a database.o composer.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

composer_main: composer.o database.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) composer.o database.o $(USER_DIR)/composer_main.cpp -o $@

