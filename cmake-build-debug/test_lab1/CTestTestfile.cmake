# CMake generated Testfile for 
# Source directory: D:/TU Darmstadt/Semester3/lab_1/test_lab1
# Build directory: D:/TU Darmstadt/Semester3/lab_1/cmake-build-debug/test_lab1
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(SerialTests "D:/TU Darmstadt/Semester3/lab_1/cmake-build-debug/bin/lab1_test.exe")
set_tests_properties(SerialTests PROPERTIES  _BACKTRACE_TRIPLES "D:/TU Darmstadt/Semester3/lab_1/test_lab1/CMakeLists.txt;66;add_test;D:/TU Darmstadt/Semester3/lab_1/test_lab1/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")
