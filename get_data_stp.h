#ifndef MAIN_CPP_GET_DATA_STP_H
#define MAIN_CPP_GET_DATA_STP_H

#include <fstream>
#include "pin.h"

using namespace std;

string get_file_name();

void control_if_open(fstream& MyFile);

void goto_section_comment(fstream& MyFile);

void goto_section_graph(fstream& MyFile);

void goto_section_coordinates(fstream& MyFile);

int extract_number_of_nodes(fstream& MyFile);

vector<pin> extract_coordinates(fstream& MyFile, int number_nodes);

void print_comment(fstream& MyFile);

void get_data_from_File(int* number_nodes,vector<pin>* coordinates);

#endif //MAIN_CPP_GET_DATA_STP_H
