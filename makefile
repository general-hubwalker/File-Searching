all: object_file_1 object_file_2 object_file_3 static_library object_file_for_main create_executable delit_bject_files run_executable

object_file_1:
	g++ -c file_in_folder.cpp
object_file_2:
	g++ -c find_file_path.cpp
object_file_3:
	g++ -c print_path.cpp
static_library:
	ar rs libfindpath.a file_in_folder.o find_file_path.o print_path.o
object_file_for_main:
	g++ -c find_path.cpp
create_executable:
	g++ -o findpath find_path.o libfindpath.a
delit_bject_files:
	rm *.o
run_executable:
	./findpath

