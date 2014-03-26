lib_LIBRARIES = libtheciphers.a
libtheciphers_a_SOURCES = implementations/aes_cipher.cc factories/cipher_factory.cc

check_PROGRAMS = unit_test
unit_test_SOURCES = $(CURDIR)/../deps/gmock-1.7.0/gtest/fused-src/gtest/gtest-all.cc test/main.cc implementations/aes_cipher.cc
unit_test_CXXFLAGS = -I$(CURDIR)/../deps/gmock-1.7.0/gtest/include -lssl -lcrypto
