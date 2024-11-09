#include <iostream>
#include <cctype>
#include <string>
#include <fstream>

using namespace std;

class Scanner {
    string input;
    int iterator;
    char logic[3] = { '>','<','=' };
    char aritmetic[4] = { '+','-','/','*' };
public:
    Scanner(string input) :input(input),iterator(0) {}

    bool checklogic(){
        for (int i = 0; i < 3; i++) {
            if (input[iterator] == logic[i])
                return 1;
        }
        return 0;
    }

    bool checkaritmetic() {
        for (int i = 0; i < 4; i++) {
            if (input[iterator] == aritmetic[i])
                return 1;
        }
        return 0;
    }

    bool next(){

        while (iterator < input.length() && isspace(input[iterator]))
            iterator++;

        if (iterator >= input.length()) {
            return 0;
        }

        string currInput;

        if (input[iterator] == '"') {
            int i_first=iterator;
            iterator++;
            while (isalnum(input[iterator]) || isalpha(input[iterator]) || input[iterator] == '_') {
                currInput += input[iterator];
                iterator += 1;
            }
            if (input[iterator] != '"') {
                cout << "No se puede incluir el elemento " << input[iterator] << " en un tipo text\n";
                return 0;
            }
            iterator++;
            currInput += input[iterator];
            iterator++;
            cout << "De la posicion de " << i_first << " hasta " << iterator << endl;
            cout << "Declaracion de text, text: " << currInput << " \n";
        }

        if (isalpha(input[iterator])) {
            switch (input[iterator])
            {
            case 'b':
                if (input[iterator + 1] == 'u' && input[iterator + 2] == 'c' && input[iterator + 3] == 'l' && input[iterator + 4] == 'e') {
                    cout << "De la posicion de " << iterator << " hasta " << iterator + 4 << endl;
                    iterator += 5;
                    cout << "El inicio de un bucle\n";
                    return 1;
                }
                break;
            case 's':
                if (input[iterator + 1] == 'i') {
                    cout << "De la posicion de " << iterator << " hasta " << iterator + 1 << endl;
                    iterator += 2;
                    cout << "El inicio de un if\n";
                    return 1;
                }
                break;
            case 'p':
                if (input[iterator + 1] == 'a' && input[iterator + 2] == 'g' && input[iterator + 3] == 'e') {
                    cout << "De la posicion de " << iterator << " hasta " << iterator + 3 << endl;
                    iterator += 4;
                    cout << "Declaracion de tipo pagina\n";
                    return 1;
                }
                break;
            case 'n':
                if (input[iterator + 1] == 'u' && input[iterator + 2] == 'm') {
                    cout << "De la posicion de " << iterator << " hasta " << iterator + 2 << endl;
                    iterator += 3;
                    cout << "Declaracion de tipo num\n";
                    return 1;
                }
                break;
            case 't':
                if (input[iterator + 1] == 'e' && input[iterator + 2] == 'x' && input[iterator + 3] == 't') {
                    cout << "De la posicion de " << iterator << " hasta " << iterator + 3 << endl;
                    iterator += 4;
                    cout << "Declaracion de tipo text\n";
                    return 1;
                }
                break;
            }
            int i_first = iterator;
            while (isalnum(input[iterator]) || isalpha(input[iterator]) || input[iterator] == '_') {
                currInput += input[iterator];
                iterator+=1;
            }
            if (!isspace(input[iterator]) && !checklogic() && !checkaritmetic() && input[iterator]!=';' && input[iterator]!=':') {
                cout << "No se puede incluir el elemento " << input[iterator] << " en un id\n";
                return 0;
            }
            cout << "De la posicion de " << i_first << " hasta " << iterator << endl;
            cout << "Declaracion de id, id: " << currInput << " \n";
            return 1;
        }

        if (isdigit(input[iterator])) {
            int i_first=iterator;
            while (isdigit(input[iterator])) {
                currInput += input[iterator];
                iterator+=2;
            }
            if (!isspace(input[iterator]) && !checklogic() && !checkaritmetic()&&input[iterator]!=';' && input[iterator] != '{') {
                cout << "No se puede incluir el elemento " << input[iterator] << " en un numero\n";
                return 0;
            }
            cout << "De la posicion de " << i_first << " hasta " << iterator << endl;
            cout << "Declaracion de numero, numero: " << currInput << "\n";
        }

        switch (input[iterator])
        {
        case '>':
            cout << "De la posicion de " << iterator << " hasta " << iterator +1 << endl;
            iterator+=2;
            cout << "Declaracion de tipo logica: >\n";
            break;
        case '<':
            cout << "De la posicion de " << iterator << " hasta " << iterator + 1 << endl;
            iterator+=2;
            cout << "Declaracion de tipo logica: <\n";
            break;
        case '=':
            if (input[iterator + 1] == '=') {
                cout << "De la posicion de " << iterator << " hasta " << iterator + 2 << endl;
                iterator+=3;
                cout << "Declaracion de tipo logica: ==\n";
            }
            else {
                cout << "No existe la declaracion para '='\n";
                return 0;
            }
            break;
        case '+':
            cout << "De la posicion de " << iterator << " hasta " << iterator + 1 << endl;
            iterator+=2;
            cout << "Declaracion de tipo logica: +\n";
            break;
        case '-':
            cout << "De la posicion de " << iterator << " hasta " << iterator + 1 << endl;
            iterator+=2;
            cout << "Declaracion de tipo logica: -\n";
            break;
        case '*':
            cout << "De la posicion de " << iterator << " hasta " << iterator + 1 << endl;
            iterator+=2;
            cout << "Declaracion de tipo logica: *\n";
            break;
        case '/':
            cout << "De la posicion de " << iterator << " hasta " << iterator + 1 << endl;
            iterator+=2;
            cout << "Declaracion de tipo logica: /\n";
            break;
        case ';':
            cout << "De la posicion de " << iterator << " hasta " << iterator + 1 << endl;
            iterator+=2;
            cout << "Declaracion de fin de linea: ;\n";
            break;
        case ':':
            if (input[iterator + 1] == '=') {
                cout << "De la posicion de " << iterator << " hasta " << iterator + 2 << endl;
                iterator+=3;
                cout << "Asignacion :=\n";
            }
            break;
        case '(':
            cout << "De la posicion de " << iterator << " hasta " << iterator + 1 << endl;
            iterator += 2;
            cout << "Delimitador (\n";
            break;
        case ')':
            cout << "De la posicion de " << iterator << " hasta " << iterator + 1 << endl;
            iterator += 2;
            cout << "Delimitador )\n";
            break;
        case '{':
            cout << "De la posicion de " << iterator << " hasta " << iterator + 1 << endl;
            iterator += 2;
            cout << "Delimitador {\n";
            break;
        case '}':
            cout << "De la posicion de " << iterator << " hasta " << iterator + 1 << endl;
            iterator += 2;
            cout << "Delimitador }\n";
            break;
        }
        
      
    }

    void scan() {
        while (next() != 0) {}
        cout << "Final del scanner";
    }
};

int main()
{
    std::string nombreArchivo = "input.txt";

    std::ifstream File(nombreArchivo);
    if (!File.is_open()) {
        std::cerr << "Nose puede abrir el archivo: " << nombreArchivo << std::endl;
        return 1;
    }

    std::string contenido((std::istreambuf_iterator<char>(File)),
        (std::istreambuf_iterator<char>()));

    File.close();

    std::cout << "Codigo ingresado:\n" << contenido << std::endl;
    std::cout << "\n";

    Scanner test(contenido);
    test.scan();
}