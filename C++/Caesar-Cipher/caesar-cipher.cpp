#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

class CaesarCipher {
private:
    int shift;
    
    char encryptChar(char ch) {
        if (isupper(ch)) {
            return ((ch - 'A' + shift) % 26) + 'A';
        } else if (islower(ch)) {
            return ((ch - 'a' + shift) % 26) + 'a';
        }
        return ch; // Non-alphabetic characters remain unchanged
    }
    
    char decryptChar(char ch) {
        if (isupper(ch)) {
            return ((ch - 'A' - shift + 26) % 26) + 'A';
        } else if (islower(ch)) {
            return ((ch - 'a' - shift + 26) % 26) + 'a';
        }
        return ch; // Non-alphabetic characters remain unchanged
    }
    
public:
    CaesarCipher(int s = 3) : shift(s) {}
    
    void setShift(int s) {
        shift = s;
    }
    
    bool encryptFile(const string& inputFile, const string& outputFile) {
        ifstream inFile(inputFile);
        ofstream outFile(outputFile);
        
        if (!inFile.is_open()) {
            cerr << "\n❌ Error: Cannot open input file '" << inputFile << "'" << endl;
            return false;
        }
        
        if (!outFile.is_open()) {
            cerr << "\n❌ Error: Cannot create output file '" << outputFile << "'" << endl;
            return false;
        }
        
        char ch;
        while (inFile.get(ch)) {
            outFile.put(encryptChar(ch));
        }
        
        inFile.close();
        outFile.close();
        return true;
    }
    
    bool decryptFile(const string& inputFile, const string& outputFile) {
        ifstream inFile(inputFile);
        ofstream outFile(outputFile);
        
        if (!inFile.is_open()) {
            cerr << "\n❌ Error: Cannot open input file '" << inputFile << "'" << endl;
            return false;
        }
        
        if (!outFile.is_open()) {
            cerr << "\n❌ Error: Cannot create output file '" << outputFile << "'" << endl;
            return false;
        }
        
        char ch;
        while (inFile.get(ch)) {
            outFile.put(decryptChar(ch));
        }
        
        inFile.close();
        outFile.close();
        return true;
    }
    
    string encryptText(const string& text) {
        string result;
        for (char ch : text) {
            result += encryptChar(ch);
        }
        return result;
    }
    
    string decryptText(const string& text) {
        string result;
        for (char ch : text) {
            result += decryptChar(ch);
        }
        return result;
    }
    
    void displayFileContent(const string& filename) {
        ifstream file(filename);
        
        if (!file.is_open()) {
            cerr << "\n❌ Error: Cannot open file '" << filename << "'" << endl;
            return;
        }
        
        cout << "\n📄 Content of '" << filename << "':" << endl;
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        file.close();
    }
};

class CaesarCipherApp {
private:
    CaesarCipher cipher;
    
    void clearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }
    
    void displayMenu() {
        cout << "\n";
        cout << "╔════════════════════════════════════════╗" << endl;
        cout << "║                                        ║" << endl;
        cout << "║      🔐 CAESAR CIPHER TOOL 🔐         ║" << endl;
        cout << "║                                        ║" << endl;
        cout << "╚════════════════════════════════════════╝" << endl << endl;
        cout << "  1. 🔒 Encrypt a file" << endl;
        cout << "  2. 🔓 Decrypt a file" << endl;
        cout << "  3. 🔤 Encrypt text (quick)" << endl;
        cout << "  4. 🔤 Decrypt text (quick)" << endl;
        cout << "  5. 👁️  View file content" << endl;
        cout << "  6. 📚 About Caesar Cipher" << endl;
        cout << "  7. 🚪 Exit" << endl << endl;
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl << endl;
    }
    
    int getValidShift() {
        int shift;
        while (true) {
            cout << "Enter shift value (1-25): ";
            if (cin >> shift && shift >= 1 && shift <= 25) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return shift;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "❌ Invalid! Enter a number between 1 and 25." << endl;
        }
    }
    
    void showAbout() {
        cout << "\n📚 ABOUT CAESAR CIPHER" << endl;
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        cout << "\nThe Caesar Cipher is one of the simplest and oldest" << endl;
        cout << "encryption techniques. It is a substitution cipher" << endl;
        cout << "where each letter is shifted by a fixed number of" << endl;
        cout << "positions in the alphabet." << endl << endl;
        cout << "Example (shift = 3):" << endl;
        cout << "  Plain:  A B C D E F G H I J K L M" << endl;
        cout << "  Cipher: D E F G H I J K L M N O P" << endl << endl;
        cout << "  \"HELLO\" → \"KHOOR\"" << endl << endl;
        cout << "Named after Julius Caesar who used it to protect" << endl;
        cout << "military messages." << endl;
    }
    
public:
    void run() {
        int choice;
        string inputFile, outputFile, text;
        
        while (true) {
            clearScreen();
            displayMenu();
            
            cout << "Enter your choice (1-7): ";
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n❌ Invalid input! Press Enter to continue...";
                cin.get();
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            if (choice == 7) {
                cout << "\n👋 Thank you for using Caesar Cipher! Goodbye!" << endl;
                break;
            }
            
            switch (choice) {
                case 1: // Encrypt file
                    cout << "\n📝 ENCRYPT FILE" << endl;
                    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
                    cout << "Enter input filename: ";
                    getline(cin, inputFile);
                    
                    cout << "Enter output filename: ";
                    getline(cin, outputFile);
                    
                    cipher.setShift(getValidShift());
                    
                    if (cipher.encryptFile(inputFile, outputFile)) {
                        cout << "\n✅ File encrypted successfully!" << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.get();
                    break;
                    
                case 2: // Decrypt file
                    cout << "\n🔓 DECRYPT FILE" << endl;
                    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
                    cout << "Enter input filename: ";
                    getline(cin, inputFile);
                    
                    cout << "Enter output filename: ";
                    getline(cin, outputFile);
                    
                    cipher.setShift(getValidShift());
                    
                    if (cipher.decryptFile(inputFile, outputFile)) {
                        cout << "\n✅ File decrypted successfully!" << endl;
                    }
                    cout << "Press Enter to continue...";
                    cin.get();
                    break;
                    
                case 3: // Encrypt text
                    cout << "\n🔤 ENCRYPT TEXT" << endl;
                    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
                    cout << "Enter text to encrypt: ";
                    getline(cin, text);
                    
                    cipher.setShift(getValidShift());
                    
                    cout << "\n🔒 Encrypted: " << cipher.encryptText(text) << endl;
                    cout << "\nPress Enter to continue...";
                    cin.get();
                    break;
                    
                case 4: // Decrypt text
                    cout << "\n🔤 DECRYPT TEXT" << endl;
                    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
                    cout << "Enter text to decrypt: ";
                    getline(cin, text);
                    
                    cipher.setShift(getValidShift());
                    
                    cout << "\n🔓 Decrypted: " << cipher.decryptText(text) << endl;
                    cout << "\nPress Enter to continue...";
                    cin.get();
                    break;
                    
                case 5: // View file
                    cout << "\n👁️  VIEW FILE CONTENT" << endl;
                    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
                    cout << "Enter filename to view: ";
                    getline(cin, inputFile);
                    
                    cipher.displayFileContent(inputFile);
                    cout << "\nPress Enter to continue...";
                    cin.get();
                    break;
                    
                case 6: // About
                    showAbout();
                    cout << "\nPress Enter to continue...";
                    cin.get();
                    break;
                    
                default:
                    cout << "\n❌ Invalid choice! Please select 1-7." << endl;
                    cout << "Press Enter to continue...";
                    cin.get();
            }
        }
    }
};

int main() {
    CaesarCipherApp app;
    app.run();
    return 0;
}
