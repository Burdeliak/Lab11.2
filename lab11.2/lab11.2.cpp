#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// �������, ��� ����� ���� ����� t1 � ������ ���� � string
string ReadFile(const char* filename) {
    ifstream fin(filename);
    string content, line;
    while (getline(fin, line)) {
        content += line + "\n";
    }
    fin.close();
    return content;
}

// �������, ��� ������� �� ������� �� ������� �������� ������� �<� � �>�
string RemoveBracketsContent(const string& text) {
    string result;
    int bracketLevel = 0;  // ����� ���������� �����

    for (char ch : text) {
        if (ch == '<') {
            bracketLevel++;  // ������� � ����� ����� �����
        }
        else if (ch == '>') {
            if (bracketLevel > 0) {
                bracketLevel--;  // �������� � ���� �����
            }
        }
        else if (bracketLevel == 0) {
            result += ch;  // �������� ������ ���� ���� �������
        }
    }
    return result;
}

// �������, ��� ������ ���������� ����� � ���� t2
void WriteFile(const char* filename, const string& content) {
    ofstream fout(filename);
    fout << content;
    fout.close();
}

int main() {
    const char* inputFilename = "t1.txt";  // ��'� �������� �����
    const char* outputFilename = "t2.txt"; // ��'� ��������� �����

    // ������� ����� �� ����� t1
    string text = ReadFile(inputFilename);

    // ��������� ���� �� �������� �������
    string processedText = RemoveBracketsContent(text);

    // �������� ��������� � ���� t2
    WriteFile(outputFilename, processedText);

    cout << "The file was successfully processed and written to " << outputFilename << endl;
    return 0;
}
