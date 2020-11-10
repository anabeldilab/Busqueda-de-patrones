/// @class Automata
///
/// @brief This class contains the methods necessary to search a 
/// pattern in a string of characters
///
/// @author Anabel Díaz Labrador <alu0101206011@ull.edu.es>
/// @version Version 1: Automata with 
/// @date 6 Nov 2020
///
/// @see https://en.wikipedia.org/wiki/Set_(mathematics)

typedef unsigned long ulong;

class Set {
  private:
    std::vector<ulong> set_;  // Set of longs
    ulong long_size_;  // Size of long in bits
    ulong limit_elements_size_; // Limit number of elements

  public:
    // Default constructor
    Set(void);

    /// @brief Initialize all attributes using the following parameters
    /// @param kSize
    Set(const ulong); 

    /// @brief Default destructor
    ~Set();

    std::vector<ulong> get_set(void) const;
    ulong get_long_size(void) const;
    ulong get_limit_elements_size(void) const;

    void set_set(const std::vector<ulong>);
    void set_limit_elements_size(const ulong);

    /// @brief Sets the bit at the position given by the parameter named element to 1
    /// @param kAnalyzeWord
    void InsertElement(const ulong);

    /// @brief Sets the bit at the position given by the parameter named element to 0
    /// @param kElement
    void DeleteElement(const ulong);

    /// @brief Change the positions of the long vector that were at 1 to 0
    /// @param kElement
    void ClearSet(void);

    /// @brief Returns true if the long vector is empty
    bool SetIsEmpty(void);

    /// @brief Returns true if the element position in the long vector is at 1
    /// @param kElement
    bool ElementBelongsToSet(const ulong);
    
    void operator=(const Set);
    bool operator==(Set);
    Set operator+(Set);
    Set operator-(Set);
    Set operator*(Set);
    Set operator!(void);
    friend std::ostream& operator<<(std::ostream&, Set);

  private: 

    /// @brief Check if the element is out of limit
    /// @param kElement
    void CheckElement(const ulong) const;
};
