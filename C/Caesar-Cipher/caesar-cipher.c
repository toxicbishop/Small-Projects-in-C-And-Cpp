#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER 1024

// Function prototypes
void encryptFile(const char* inputFile, const char* outputFile, int shift);
void decryptFile(const char* inputFile, const char* outputFile, int shift);
char encryptChar(char ch, int shift);
char decryptChar(char ch, int shift);
void displayMenu();
void clearScreen();
int getValidShift();
void displayFileContent(const char* filename);

int main() {
    int choice;
    char inputFile[256];
    char outputFile[256];
    int shift;
    
    while (1) {
        clearScreen();
        displayMenu();
        
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // Clear input buffer
            printf("\nInvalid input! Press Enter to continue...");
            getchar();
            continue;
        }
        getchar(); // Consume newline
        
        if (choice == 5) {
            printf("\n👋 Thank you for using Caesar Cipher! Goodbye!\n");
            break;
        }
        
        switch (choice) {
            case 1: // Encrypt file
                printf("\n📝 ENCRYPT FILE\n");
                printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
                printf("Enter input filename: ");
                fgets(inputFile, sizeof(inputFile), stdin);
                inputFile[strcspn(inputFile, "\n")] = 0;
                
                printf("Enter output filename: ");
                fgets(outputFile, sizeof(outputFile), stdin);
                outputFile[strcspn(outputFile, "\n")] = 0;
                
                shift = getValidShift();
                
                encryptFile(inputFile, outputFile, shift);
                printf("\n✅ File encrypted successfully!\n");
                printf("Press Enter to continue...");
                getchar();
                break;
                
            case 2: // Decrypt file
                printf("\n🔓 DECRYPT FILE\n");
                printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
                printf("Enter input filename: ");
                fgets(inputFile, sizeof(inputFile), stdin);
                inputFile[strcspn(inputFile, "\n")] = 0;
                
                printf("Enter output filename: ");
                fgets(outputFile, sizeof(outputFile), stdin);
                outputFile[strcspn(outputFile, "\n")] = 0;
                
                shift = getValidShift();
                
                decryptFile(inputFile, outputFile, shift);
                printf("\n✅ File decrypted successfully!\n");
                printf("Press Enter to continue...");
                getchar();
                break;
                
            case 3: // View file
                printf("\n👁️  VIEW FILE CONTENT\n");
                printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
                printf("Enter filename to view: ");
                fgets(inputFile, sizeof(inputFile), stdin);
                inputFile[strcspn(inputFile, "\n")] = 0;
                
                displayFileContent(inputFile);
                printf("\nPress Enter to continue...");
                getchar();
                break;
                
            case 4: // About Caesar Cipher
                printf("\n📚 ABOUT CAESAR CIPHER\n");
                printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
                printf("\nThe Caesar Cipher is one of the simplest and oldest\n");
                printf("encryption techniques. It is a substitution cipher\n");
                printf("where each letter is shifted by a fixed number of\n");
                printf("positions in the alphabet.\n\n");
                printf("Example (shift = 3):\n");
                printf("  Plain:  A B C D E F G H I J K L M\n");
                printf("  Cipher: D E F G H I J K L M N O P\n\n");
                printf("  \"HELLO\" → \"KHOOR\"\n\n");
                printf("Named after Julius Caesar who used it to protect\n");
                printf("military messages.\n");
                printf("\nPress Enter to continue...");
                getchar();
                break;
                
            default:
                printf("\n❌ Invalid choice! Please select 1-5.\n");
                printf("Press Enter to continue...");
                getchar();
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║                                        ║\n");
    printf("║      🔐 CAESAR CIPHER TOOL 🔐         ║\n");
    printf("║                                        ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    printf("  1. 🔒 Encrypt a file\n");
    printf("  2. 🔓 Decrypt a file\n");
    printf("  3. 👁️  View file content\n");
    printf("  4. 📚 About Caesar Cipher\n");
    printf("  5. 🚪 Exit\n\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
}

int getValidShift() {
    int shift;
    while (1) {
        printf("Enter shift value (1-25): ");
        if (scanf("%d", &shift) == 1 && shift >= 1 && shift <= 25) {
            getchar(); // Consume newline
            return shift;
        }
        while (getchar() != '\n'); // Clear input buffer
        printf("❌ Invalid! Enter a number between 1 and 25.\n");
    }
}

void encryptFile(const char* inputFile, const char* outputFile, int shift) {
    FILE *inFile = fopen(inputFile, "r");
    FILE *outFile = fopen(outputFile, "w");
    
    if (inFile == NULL) {
        printf("\n❌ Error: Cannot open input file '%s'\n", inputFile);
        return;
    }
    
    if (outFile == NULL) {
        printf("\n❌ Error: Cannot create output file '%s'\n", outputFile);
        fclose(inFile);
        return;
    }
    
    char ch;
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(encryptChar(ch, shift), outFile);
    }
    
    fclose(inFile);
    fclose(outFile);
}

void decryptFile(const char* inputFile, const char* outputFile, int shift) {
    FILE *inFile = fopen(inputFile, "r");
    FILE *outFile = fopen(outputFile, "w");
    
    if (inFile == NULL) {
        printf("\n❌ Error: Cannot open input file '%s'\n", inputFile);
        return;
    }
    
    if (outFile == NULL) {
        printf("\n❌ Error: Cannot create output file '%s'\n", outputFile);
        fclose(inFile);
        return;
    }
    
    char ch;
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(decryptChar(ch, shift), outFile);
    }
    
    fclose(inFile);
    fclose(outFile);
}

char encryptChar(char ch, int shift) {
    if (isupper(ch)) {
        return ((ch - 'A' + shift) % 26) + 'A';
    } else if (islower(ch)) {
        return ((ch - 'a' + shift) % 26) + 'a';
    }
    return ch; // Non-alphabetic characters remain unchanged
}

char decryptChar(char ch, int shift) {
    if (isupper(ch)) {
        return ((ch - 'A' - shift + 26) % 26) + 'A';
    } else if (islower(ch)) {
        return ((ch - 'a' - shift + 26) % 26) + 'a';
    }
    return ch; // Non-alphabetic characters remain unchanged
}

void displayFileContent(const char* filename) {
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("\n❌ Error: Cannot open file '%s'\n", filename);
        return;
    }
    
    printf("\n📄 Content of '%s':\n", filename);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    fclose(file);
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
