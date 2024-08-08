#include <iostream>
#include <string>

std::string caesarDecrypt(const std::string& text, int shift) {
    std::string decrypted = ""; 

    
    for (char ch : text) {
        
        if (isalpha(ch)) {
            
            char base = islower(ch) ? 'a' : 'A';
            
            decrypted += static_cast<char>(
                (static_cast<int>(ch) - static_cast<int>(base) - shift + 26) % 26 + static_cast<int>(base)
                );
        }
        else {
            
            decrypted += ch;
        }
    }

    return decrypted; 
}

int main() {
    std::string encryptedText; 
    int shift; 

    while (true) { 
        
        std::cout << "Enter the encrypted text (or 'exit' to exit): ";
        std::getline(std::cin, encryptedText); 

        
        if (encryptedText == "exit") {
            break; 
        }

        // Запрашиваем у пользователя ввод значения сдвига
        std::cout << "Enter an offset (for example, 3): ";
        std::cin >> shift; 
        std::cin.ignore(); 

        
        std::string decryptedText = caesarDecrypt(encryptedText, shift);

        // Выводим расшифрованный текст на экран
        std::cout << "Decrypted text:" << decryptedText << std::endl;
    }

    return 0; 
}
