#include "../h/text.h"

void Text::setRandomLine(Monster* monster) {

    std::ifstream dataset("../dataset");

    if (!dataset.is_open()) {
        throw std::invalid_argument( "Couldn't open the file" );
    }

    std::string returnLine;

    int lineNum = rand() % 50 + 1;

    for (int i = lineNum + monster->getDatasetOffset(); i > 0; i--) {
        getline(dataset, returnLine);
    }
    
    lineToPrint = returnLine;

}   

void Text::randomizeLine() {

    for (int i = 0; i < static_cast<int>(lineToPrint.size()); i++) {

        if (rand() % 3 == 0) {

            if (lineToPrint[i] > 96 && lineToPrint[i] < 123) {

                lineToPrint[i] -= 32;

            } else if (lineToPrint[i] > 64 && lineToPrint[i] < 91) {

                lineToPrint[i] += 32;

            }
        }
    }
}

int Text::getTextLength() {
    return textLength;
};

std::string Text::getLineToPrint() {
    return lineToPrint;
};

std::string Text::getLetters() {
    return letters;
};

void Text::setLine(std::string line) {
    this->lineToPrint = line;
}

void Text::setTextLength(int length) {
    this->textLength = length;
}

int Text::operator[](int index) {
    return lineToPrint[index];
}

std::string Text::operator+=(char ch) {
    letters+=ch;
    return letters;
}