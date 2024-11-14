#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функція, яка зчитує вміст файлу t1 і зберігає його в string
string ReadFile(const char* filename) {
    ifstream fin(filename);
    string content, line;
    while (getline(fin, line)) {
        content += line + "\n";
    }
    fin.close();
    return content;
}

// Функція, яка видаляє всі символи між найбільш зовнішніми дужками «<» і «>»
string RemoveBracketsContent(const string& text) {
    string result;
    int bracketLevel = 0;  // рівень вкладеності дужок

    for (char ch : text) {
        if (ch == '<') {
            bracketLevel++;  // входимо в новий рівень дужок
        }
        else if (ch == '>') {
            if (bracketLevel > 0) {
                bracketLevel--;  // виходимо з рівня дужок
            }
        }
        else if (bracketLevel == 0) {
            result += ch;  // записуємо символ лише поза дужками
        }
    }
    return result;
}

// Функція, яка записує оброблений текст у файл t2
void WriteFile(const char* filename, const string& content) {
    ofstream fout(filename);
    fout << content;
    fout.close();
}

int main() {
    const char* inputFilename = "t1.txt";  // Ім'я вхідного файлу
    const char* outputFilename = "t2.txt"; // Ім'я вихідного файлу

    // Зчитуємо текст із файлу t1
    string text = ReadFile(inputFilename);

    // Видаляємо вміст між зовнішніми дужками
    string processedText = RemoveBracketsContent(text);

    // Записуємо результат у файл t2
    WriteFile(outputFilename, processedText);

    cout << "The file was successfully processed and written to " << outputFilename << endl;
    return 0;
}
