/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Computabilidad y algoritmia
///
/// @author Anabel Díaz Labrador <alu0101206011@ull.edu.es> 
/// @date 10 Nov 2020
/// @brief implementation of class Automata
/// 
/// @see https://en.wikipedia.org/wiki/Automata_theory
/// 
/// To compile: make 
/// To clean files: make clean

#include <iostream> 
#include <fstream>
#include <vector>

#include "automata.h"

void ErrorMessage(const int);

int main(int argc, char *argv[]) {
  if (argc != 4 && argc != 2) { ErrorMessage(1); }     
  if ((std::string)argv[1] == "--help" || (std::string)argv[1] == "-h")
    if (argc == 2)
      ErrorMessage(2);

  Set alphabet(256);
  std::string pattern = argv[1];
  for (unsigned iterator = 97; iterator < 123; iterator++)
    alphabet.InsertElement(iterator);

  Automata automata(alphabet, pattern);
  std::ifstream reader(argv[2]);
  if (!reader) ErrorMessage(3);

  std::vector<std::string> v_strings;
  while (!reader.eof()) {
    std::string analyze_words;
    reader >> analyze_words;
    v_strings.push_back(analyze_words);
  }
  reader.close();
  std::ofstream writer(argv[3]);
  for (unsigned iterator = 0; iterator < v_strings.size(); iterator++)
    automata.Write(writer, v_strings[iterator]);
  writer.close();

  return 0;
}

// Show error messages in terminal
void ErrorMessage(const int kError) {
  if (kError == 1) {
    std::cerr << "Invalid arguments to function.\n" 
              << "Write ./pattern_search --help for more info\n";
    exit(1);
  } else if (kError == 2) {
    std::cerr << "Usage: ./pattern_search pattern infile.txt outfile.txt" 
              << "\nFor OPTION:\n" 
              << "\t-h,--help\t\tShow this help message\n";
    exit(1);
  } else if (kError == 3) {
    std::cerr << "Error: file could not be opened"
              << "\nFor OPTION:\n" 
              << "\t-h,--help\t\tShow this help message\n";
    exit(1);
  }
}
