#include "iniMan.hpp"
#include <algorithm>
/*
██╗  ██╗███████╗██╗   ██╗
██║ ██╔╝██╔════╝╚██╗ ██╔╝
█████╔╝ █████╗   ╚████╔╝ 
██╔═██╗ ██╔══╝    ╚██╔╝  
██║  ██╗███████╗   ██║   
╚═╝  ╚═╝╚══════╝   ╚═╝   
*/
// Constructors
Key::Key(std::string name, std::string value){
    this->name = name;
    this->value = value;
}

// Getters
inline std::string Key::getName() const {
    return this->name;
}

inline std::string Key::getValue() const {
    return this->value;
}

// Setters
void Key::setName(std::string name){
    this->name = name;
}

void Key::setValue(std::string value){
    this->value = value;
}

// Operators
void Key::operator=(Key const& key){
    this->name = key.name;
    this->value = key.value;
}

void Key::operator=(std::string const value){
    this->value = value;
}

bool Key::operator==(std::string const name){
    return this->name == name;
}

bool Key::operator!=(std::string const name){
    return this->name != name;
}


/*
███████╗███████╗ ██████╗████████╗██╗ ██████╗ ███╗   ██╗
██╔════╝██╔════╝██╔════╝╚══██╔══╝██║██╔═══██╗████╗  ██║
███████╗█████╗  ██║        ██║   ██║██║   ██║██╔██╗ ██║
╚════██║██╔══╝  ██║        ██║   ██║██║   ██║██║╚██╗██║
███████║███████╗╚██████╗   ██║   ██║╚██████╔╝██║ ╚████║
╚══════╝╚══════╝ ╚═════╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝
*/
// Constructor
Section::Section(std::string name){
    this->name = name;
}

// Methods
std::string Section::readKey(std::string name){
    for (size_t i = 0; i < this->numOfKeys; i++){
        if (this->keys[i] == name){
            return this->keys[i].getValue();
        }
    }
    return "";
}

inline Key* Section::readKey(const size_t index){
    if (index < this->numOfKeys && index >= 0){
        return &this->keys[index];
    }
    return nullptr;
}

size_t Section::getNumOfKeys(){
    this->numOfKeys = this->keys.size(); // re-update the number of keys, for good luck
    return this->numOfKeys;
}

// Getters
inline std::string Section::getName() const{
    return this->name;
}

// Setters
void Section::setName(std::string name){
    this->name = name;
}

void Section::addKey(std::string name, std::string value){
    if (!this->keyExists(name)){
        this->keys.push_back(Key(name, value));
        this->numOfKeys++;
    }
}

void Section::delKey(std::string name){
    if (!this->keyExists(name)){ // First check if the key exists
        return;
    }
    for (size_t i = 0; i < this->numOfKeys; i++){
        if (this->keys[i] == name){
            this->keys.erase(this->keys.begin() + i);
            this->numOfKeys--;
            break;
        }
    }
}

// Operators
void Section::operator+=(Key const& key){
    this->addKey(key.getName(), key.getValue());
}

void Section::operator-=(std::string const& name){
    this->delKey(name);
}

bool Section::operator==(std::string const& name){
    return this->name == name;
}

bool Section::operator!=(std::string const& name){
    return this->name != name;
}

bool Section::keyExists(std::string name){
    for (size_t i = 0; i < this->numOfKeys; i++){
        if (this->keys[i] == name){
            return true;
        }
    }
    return false;
}

/*
██╗███╗   ██╗██╗
██║████╗  ██║██║
██║██╔██╗ ██║██║
██║██║╚██╗██║██║
██║██║ ╚████║██║
╚═╝╚═╝  ╚═══╝╚═╝
*/
// Constructor
ini::ini(std::string filepath){
    this->path = filepath;
    this->open();
    this->parse();
}

// Methods
void ini::open(){
    this->f.open(this->path);
}

void ini::close(){
    this->f.close();
}

void ini::parse(){
    ini::LineType lineType;
    std::string line;
    std::string section;
    while(f.is_open() && !f.eof()){
        line = ini::readCleanLine(lineType);
        if(lineType == LineType::SECTION){
            section = line;
            this->addSection(section);
        }
        else if(lineType == LineType::KEY){
            this->populateSection(section, line);
        }
    }
}

void ini::write(){
    // read this->sections and write them to file
    this->f << this->header << std::endl;
    for (size_t i = 0; (i < this->numOfSections) && (this->f.is_open()); i++){
        this->writeSection(this->sections[i]);
        if (i != this->numOfSections - 1){
            this->f << std::endl;
        }
    }
    this->f << this->footer;
}

void ini::write(std::string path){
    // T_T jank central but its the best way to do it without making another addSection method
    std::string old_path = this->path;
    this->f.close();
    this->f.open(path, std::ios::out);
    this->write();
    this->f.close();
    this->open();
}

// Getters
inline std::string ini::getPath() const{
    return this->path;
}

// Setters
void ini::setPath(std::string path){
    this->path = path;
}

// Methods - sections
void ini::addSection(std::string name){
    if (!name.empty() && name.front() == '[' && name.back() == ']') {
        name = name.substr(1, name.size() - 2);
    }
    if (!this->sectionExists(name)){
        this->sections.push_back(Section(name));
        this->numOfSections++;
    }
}

void ini::populateSection(std::string section, std::string keyLine){ // pushes back another key to the section
    // figure out where '=' is
    // give the key name with string to the left of '='
    // give the key value with string to the right of '='
    if (section.empty()){
        return; // WTF where is section, dear user?
    }
    // Remove any quotes from keyLine
    keyLine.erase(std::remove(keyLine.begin(), keyLine.end(), '\"'), keyLine.end());
    keyLine.erase(std::remove(keyLine.begin(), keyLine.end(), '\''), keyLine.end());
    this->addSection(section);
    size_t pos = keyLine.find('=');
    std::string keyName = keyLine.substr(0, pos);
    std::string keyValue = '\"' + keyLine.substr(pos + 1) + '\"';

    this->sections[this->numOfSections - 1].addKey(keyName, keyValue);
}

bool ini::sectionExists(std::string name){
    for (size_t i = 0; i < this->numOfSections; i++){
        if (this->sections[i] == name){
            return true;
        }
    }
    return false;
}

// Methods - file control
std::string ini::readCleanLine(LineType& type){
    std::string line;
    std::getline(this->f, line);
    // remove comments
    this->removeComments(line);
    // Remove whitespaces
    this->removeWhitespaces(line);

    // Remove whitespaces around '='
    this->removeSpacesAround(line, '=');
    // remove whitespaces around '['
    this->removeSpacesAround(line, '[');
    // remove whitespaces around ']'
    this->removeSpacesAround(line, ']');


    if (line.empty()){
        type = LineType::COMMENT;
    } else if (line[0] == '[' && line[line.length() - 1] == ']'){
        type = LineType::SECTION;
    } else if (line.find('=') != std::string::npos){
        type = LineType::KEY;
    } else{
        type = LineType::INVALID;
    }

    return line;
}

void ini::writeSection(Section section){
    this->f << "[" << section.getName() << "]" << std::endl;
    std::cout << "[" << section.getName() << "]" << std::endl;
    for (size_t i = 0; i < section.getNumOfKeys(); i++){
        Key *tmpKey = section.readKey(i);
        this->f << tmpKey->getName() << " = " << tmpKey->getValue() << std::endl;
        std::cout << tmpKey->getName() << " = " << tmpKey->getValue() << std::endl;
    }
}

// Methods - line control
void ini::removeWhitespaces(std::string& line){
    // Remove leading whitespaces
    line.erase(0, line.find_first_not_of(" \t\n\r\f\v"));

    // Remove trailing whitespaces
    line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);
}

void ini::removeComments(std::string& line){
    for (size_t i = 0; i < this->COMMENT_CHARS.size(); i++){
        size_t pos = line.find(this->COMMENT_CHARS[i]);
        if (pos == 0){ // if line begins with comment character
            line = "";
        } else if (pos != std::string::npos){
            line = line.substr(0, pos);
        }
    }
}

void ini::removeSpacesAround(std::string& line, char c){
    size_t pos = line.find(c);
    if (pos != std::string::npos) {
        // Remove spaces before c
        size_t start = pos;
        while (start > 0 && isspace(line[start - 1])) {
            start--;
        }
        line.erase(start, pos - start);
        pos = start;

        // Remove spaces after c
        size_t end = pos + 1;
        while (end < line.length() && isspace(line[end])) {
            end++;
        }
        line.erase(pos + 1, end - (pos + 1));
    }
}