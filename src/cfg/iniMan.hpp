#pragma once

// A minimal ini file parser and writer
// Author: Aharon B.
// Date: 2024-12-05

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Key{
public:
    // Constructors
    Key(std::string name, std::string value);

    // Getters
    inline std::string getName() const;
    inline std::string getValue() const;

    // Setters
    void setName(std::string name);
    void setValue(std::string value);

    // Operators
    void operator=(Key const& key); // copy key
    void operator=(std::string const value); // set key value
    bool operator==(std::string const name); // compare key name with string (used to find duplicates, idc about the value)
    bool operator!=(std::string const name); // compare key name with string (used to find duplicates, idc about the value)

private:
    // Variables
    std::string name;
    std::string value;
};

class Section{
public:
    // Constructor
    Section(std::string name);

    // Methods
    std::string readKey(std::string name);            // get key value by name
    inline Key* readKey(const size_t index); // get key value by index, useful if you just wanna write to file
    size_t getNumOfKeys();                            // get number of keys in section

    // Getters
    inline std::string getName() const; // get section name

    // Setters
    void setName(std::string name);                   // set section name
    void addKey(std::string name, std::string value); // add key by name and value
    void delKey(std::string name);                    // remove key by name

    // Operators
    void operator+=(Key const& key);          // add key to section
    void operator-=(std::string const& name); // remove key from section
    bool operator==(std::string const& name);     // compare section name with string
    bool operator!=(std::string const& name);     // compare section name with string
    
private:
    // Variables
    std::string name;
    std::vector<Key> keys;
    size_t numOfKeys = 0;
    bool keyExists(std::string name);
};

class ini{
public:
    // Constructor
    ini(std::string filepath);

    // Methods
    void open();  // open file
    void close(); // close file
    void parse(); // parse file
    void write(); // write configuration to file
    void ini::write(std::string path); // write configuration to new file

    // Getters
    inline std::string getPath() const;
    inline Section& getSectionByName(std::string name) const;

    // Setters
    void setPath(std::string path);

private:
    // Constants
    const std::string COMMENT_CHARS = "#;"; // comment characters

    // Types
    enum class LineType{
        INVALID,
        COMMENT,
        SECTION,
        KEY
    };

    // Variables - sections
    std::vector<Section> sections;
    size_t numOfSections = 0;

    // Variables - file control
    std::string path; // file path
    std::fstream f;   // file stream

    // Methods - sections
    void addSection(std::string name);                              // create new section
    void populateSection(std::string section, std::string keyLine); // populate section with keys
    bool sectionExists(std::string name);                           // check if section exists

    // Methods - file control
    std::string readCleanLine(LineType& type); // read next line from file and remove comments
    std::string parseKey();                    // parse line and return new key if line is key
    void writeSection(Section section);        // write section to file from section

    // Methods - line control
    void removeWhitespaces(std::string& line);          // remove whitespaces
    void removeComments(std::string& line);             // remove comments
    void removeSpacesAround(std::string& line, char c); // remove spaces around character

};