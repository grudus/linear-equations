#include "LZespolone.hh"

double& LZespolona::Re() {return _re;}
double LZespolona::Re() const {return _re;}
double& LZespolona::Im() {return _im;}
double LZespolona::Im() const {return _im;}


LZespolona LZespolona::operator+ (const LZespolona& lz) const {
    LZespolona doZwrotu;
    doZwrotu.Re() = _re + lz.Re();
    doZwrotu.Im() = _im + lz.Im();
    return doZwrotu;
}

LZespolona LZespolona::operator- (const LZespolona& lz) const {
    LZespolona doZwrotu;
    doZwrotu.Re() = _re - lz.Re();
    doZwrotu.Im() = _im - lz.Im();
    return doZwrotu;
}

LZespolona LZespolona::operator* (const LZespolona& lz) const {
    LZespolona doZwrotu;
    doZwrotu.Re() = _re * lz.Re() - _im * lz.Im();
    doZwrotu.Im() = _im * lz.Re() + _re * lz.Im();
    return doZwrotu;
}

LZespolona LZespolona::operator*(const int i) const {
    LZespolona doZwrotu;
    doZwrotu.Re() = _re * i;
    doZwrotu.Im() = _im * i;
    return doZwrotu;
}

LZespolona LZespolona::operator/ (const LZespolona& lz) const {
  const double dzielnik = (lz.Re()*lz.Re() + lz.Im()*lz.Im());
  LZespolona doZwrotu; 
  if (dzielnik == 0) {
    std::cerr << "DZIELENIE PRZEZ 0\n";
    return doZwrotu;
  }
    doZwrotu.Re() = ( _re * lz.Re() + _im * lz.Im() ) / dzielnik;
    doZwrotu.Im() = (_im * lz.Re() - _re * lz.Im() ) / dzielnik;
    return doZwrotu;
}


std::ostream& operator<< (std::ostream& stream, const LZespolona& lz) {
    stream << '{';
    if (lz.Re() != 0) stream << lz.Re();
    if (lz.Im() == 0) stream << '}';
    else {
        stream << (lz.Im() > 0 ? (lz.Re() != 0 ? "+" : "") : "");
        if (lz.Im() == -1) stream << "-i}";
        else if(lz.Im() == 1) stream << "i}";
        else stream << lz.Im() << "i}";
    }
    return stream;
}

std::istream& operator>> (std::istream& stream, LZespolona& lz) {
    /*char temp;
    stream >> temp;
    stream >> lz.Re();
    stream >> temp;
    stream >> lz.Im();
    if (temp == '-') lz.Im() *= -1; */
    std::string stringZespolony;
    std::string* ladnieZesplitowane;
    char temp;
    int counter = 0;
    bool bylIm = false;
    while (counter < 25) {
        stream >> temp;
        if (temp == '{') continue;
        if (temp == '}') break;
        if (temp == 'i') {
            bylIm = true;
            continue;
        }
        stringZespolony += temp;
        counter++;
    }
    if (counter == 25) {std::cerr << "\n###NumberFormatException\n"; return stream;}
    counter = 0;

    ladnieZesplitowane = splitGdyMinusLubPlus(stringZespolony, &counter);
    for (int i = 0; i < counter; i++) {
    }

    if (counter == 2) {
        lz.Re() = atof(ladnieZesplitowane[0].c_str());
        if (ladnieZesplitowane[1].size() == 1 && ladnieZesplitowane[1].at(0) == '+') lz.Im() = 1;
        else if (ladnieZesplitowane[1].size() == 1 && ladnieZesplitowane[1].at(0) == '-') lz.Im() = -1;
        else lz.Im() = atof(ladnieZesplitowane[1].c_str());
    }
    else if (counter == 1) {
        if (bylIm) {
            if (ladnieZesplitowane[0].size() == 0) lz.Im() = 1;
            else if (ladnieZesplitowane[0].size() == 1 && ladnieZesplitowane[0].at(0) == '-') lz.Im() = -1;
            else lz.Im() = atof(ladnieZesplitowane[0].c_str());
        }
        else lz.Re() = atof(ladnieZesplitowane[0].c_str());
    }
    else {std::cerr << "\n###NumberFormatException\n"; return stream;}

    delete[] ladnieZesplitowane;
    return stream;
}



std::string* splitGdyMinusLubPlus(std::string str, int* len) {
    unsigned int i;
    int ile = 1;
    int lastIndex = 0;
    std::string* doZwrotu;
    for (i = 0; i < str.size(); i++) {
        if ((str.at(i) == '+' || str.at(i) == '-') && i != 0) ile++;
    }
    doZwrotu = new std::string[ile]();
    *len = ile;
    ile = 0;

    for (i = 0; i < str.size(); i++) {
        if ((str.at(i) == '+' || str.at(i) == '-') && i != 0) {
            doZwrotu[ile++] += str.substr(lastIndex, i-lastIndex);
            lastIndex = i;
        }
    }
    doZwrotu[ile] += str.substr(lastIndex, str.size()-lastIndex);
    return doZwrotu;
}
