/// @class Automata
///
/// @brief This class contains the methods necessary to search a 
/// pattern in a string of characters
///
/// @author Anabel Díaz Labrador <alu0101206011@ull.edu.es>
/// @version Version 1: Automata with 
/// @date 10 Nov 2020

#include "set_calculator.h"

class Automata {
  private:
    Set alphabet_;  // Alphabet to be used by strings
    std::vector<char> pattern_;  // Pattern that strings should contain

  public:
    /// @brief Initialize all attributes using the following parameters
    /// @param kAlphabet
    /// @param kPattern
    Automata(const Set, const std::string);

    /// @brief Default destructor
    ~Automata();

    Set get_alphabet() const;
    std::vector<char> get_pattern() const;

    void set_alphabet(const Set NewAlphabet);
    void set_pattern(const std::vector<char> NewPattern);

    /// @brief Returns true if the string belongs to the alphabet
    /// @param kAnalyzeWord
    bool BelongToAlphabet(const std::string);

    /// @brief How the automata works
    /// @param kAnalyzeWord
    bool PatternSearch(const std::string);

    /// @brief Write the results of automata
    /// @param os
    /// @param kAnalyzeWord
    void Write(std::ostream&, const std::string);

};

