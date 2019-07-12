#include <iostream>
#include <fstream>

int DB_File_Int(int run, int index = 1) {

  std::string runString, valueString;
  std::ifstream file;
  file.open("/Users/justingahley/apps/root/example/copies/test_folder/DB_in.csv");

  while (file.good()) {
    // Find the right line
    getline(file, runString, ',');
    if (runString.compare("") && std::stoi(runString) == run) {
      // Find the right value in this line
      for (int i = 0; i < index; i++) {
        getline(file, valueString, ',');
      }
      file.close();
      return std::stoi(valueString);
    }else getline(file, valueString);
  }
  file.close();
  return -2;
}

float DB_File_Float(int run, int index = 1) {

  std::string runString, valueString;
  std::ifstream file;
  file.open("/Users/justingahley/apps/root/example/copies/DB_in.csv");

  while (file.good()) {
    // Find the right line
    getline(file, runString, ',');
    if (runString.compare("") && std::stof(runString) == run) {
      // Find the right value in this line
      for (int i = 0; i < index; i++) {
        getline(file, valueString, ',');
      }
      file.close();
      return std::stof(valueString);
    }else getline(file, valueString);
  }
  file.close();
  return -2;
}



int run_num(int run){
  return DB_File_Int(run,10);
}

int HV(int run){
  return DB_File_Int(run,1);
}

int config(int run){
  return DB_File_Int(run,2);
}

float EBeam(int run){
  return DB_File_Float(run,3);
}

float xPos(int run){
  return DB_File_Float(run,4);
}

float yPos(int run){
  return DB_File_Float(run,5);
}

float delta_x(int run){
  return DB_File_Float(run,6);
}

float delta_y(int run){
  return DB_File_Float(run,7);
}

int events(int run){
  return DB_File_Int(run,8);
}

int goldEvents(int run){
  return DB_File_Int(run,9);
}
