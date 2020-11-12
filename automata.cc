/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Computabilidad y algoritmia
///
/// @author Anabel Díaz Labrador <alu0101206011@ull.edu.es> 
/// @date 10 Nov 2020
/// @brief implementation of class Automata
/// 
/// @see https://en.wikipedia.org/wiki/Set_(mathematics)
/// 
/// To compile: make 
/// To clean files: make clean

#include <iostream>
#include <vector>
#include <string>
 
#include "automata.h"

// Default constructor
Automata::Automata(const Set kAlphabet, const std::string& kPattern): alphabet_(kAlphabet) {
  if (!BelongToAlphabet(kPattern)) {
    std::cerr << "Error: pattern does not belong to the alphabet\n";
    exit(1);
  }
  for (unsigned iterator = 0; iterator < kPattern.size(); iterator++)
    pattern_.push_back(kPattern[iterator]);
}

// Default destructor
Automata::~Automata() {}

Set Automata::get_alphabet() const { return alphabet_; }
std::vector<char> Automata::get_pattern() const { return pattern_; }

void Automata::set_alphabet(const Set NewAlphabet) { alphabet_ = NewAlphabet; }
void Automata::set_pattern(const std::vector<char> NewPattern) {
  pattern_ = NewPattern;
}

// Returns true if the string belongs to the alphabet
bool Automata::BelongToAlphabet(const std::string& kAnalyzeWord) {
  for (unsigned iterator = 0; iterator < kAnalyzeWord.size(); iterator++)
    if (!alphabet_.ElementBelongsToSet((ulong)kAnalyzeWord[iterator]))
      return false;
  return true;
}

// Search the pattern in the parameter string 
bool Automata::PatternSearch(const std::string& kAnalyzeWord) {
  int position = 0, state_ = 0;
  while (position < kAnalyzeWord.size()) {
    for (unsigned iterator = position; iterator < kAnalyzeWord.size(); 
                                       iterator++) {
      if (pattern_[state_] == kAnalyzeWord[iterator]) {
        ++state_;
        if (state_ == pattern_.size())
          return true;
      } else {
        state_ = 0;
        break;
      }
    }
    ++position;
  }
  return false;
}

// Write the results of automata
void Automata::Write(std::ostream& os, const std::string& kAnalyzeWord) {
  if (!BelongToAlphabet(kAnalyzeWord)) {
    os << "Error\n";
  } else if(PatternSearch(kAnalyzeWord)) {
    os << "Si\n";
  } else {
    os << "No\n";
  }
}