#include <iostream>
#include <string>

using namespace std;

//Chequea si el string es un False o True
bool check_boolean(string bool_statement, int i, int j)
{
    int dif = i - j;
    if (bool_statement[i - dif] == 'T' &&
        bool_statement[i - dif + 1] == 'r' &&
        bool_statement[i - dif + 2] == 'u' &&
        bool_statement[i - dif + 3] == 'e') {
        return 1;
    }
    else if (bool_statement[i - dif] == 'F' &&
        bool_statement[i - dif + 1] == 'a' &&
        bool_statement[i - dif + 2] == 'l' &&
        bool_statement[i - dif + 3] == 's' &&
        bool_statement[i - dif + 4] == 'e') {
        return 1;
    }
    return 0;
}

//Chequea que tipo de condicion es
bool check_condition(string condition, int& i)
{
    if (condition[i] == '>' || condition[i] == '<') {
        if (condition[i + 1] == '=') {
            i = i + 2;
            return 1;
        }
        i++;
        return 1;
    }
    else if (condition[i + 1] == '=') {
        if (condition[i] == '!') {
            i = i + 2;
            return 1;
        }
        i++;
        return 1;
    }
    else if ((condition[i] == 'o' && condition[i + 1] == 'r') ||
        (condition[i] == '|' && condition[i + 1] == '|')) {
        i = i + 2;
        return 1;
    }
    if (i >= condition.length() - 1) {
        i = i + 2;
        return 0;
    }
    if (condition[i] == 'a' &&
        condition[i + 1] == 'n' &&
        condition[i + 2] == 'd') {
        i = i + 3;
        return 1;
    }
    return 0;
}

//Chequea si la expresion tiene algun negativo
bool check_negativo(string negation, int& i) {
    if (negation[i] == '!') {
        i++;
        return 1;
    }
    if (negation[i] == 'n' && negation[i + 1] == 'o'
        && negation[i + 2] == 't') {
        i += 3;
        return 1;
    }
    return 0;
        
}

//Elimina los espacios del string, para facilitar la correcion
void eliminate_spaces(string& a) {
    int i = 3, j = 3;
    string b = "if ";
    b.resize(a.length());
    while (i < a.length() && a[i] != ':') {
        if (a[i] != ' ') {
            b[j] = a[i];
            j++;
        }
        i++;
    }
    b[j] = ':';
    j++; i++;
    while (i < a.length()) {
        b[j] = a[i];
        j++; i++;
    }
    a = b;
}

//Imprime una parte del string
void print_substring(string str, int ini, int fin) {
    for (int i = ini; i < fin; i++) {
        cout << str[i];
    }
    cout << endl;
}

//Chequea que la estructura del if sea correcta
bool if_check(string if_statement) {
    bool boolean = 0;
    int conditional = 0;
    //Chequeamos que halla un if al principio del string.
    if (if_statement[0] != 'i' &&
        if_statement[1] != 'f' ||
        if_statement[2] != ' ') {
        cout << "This is not an if_statement" << endl;
        return 0;
    }
    int i = 3, j = 0, k = 0, k2 = 3, expr = 0, parenthesis = 0, negative = 0;

    eliminate_spaces(if_statement);

    //Bucle donde chequeamos el string hasta su final o los ":" del if
    while (if_statement[i] != ':' &&
        i < if_statement.length() - 1) {
        j = i;
        //segundo bucle donde buscara las condiciones,
        //al encontrar una imprime la expresion a la izquierda de la condicion y la condicion.
        while (i < if_statement.length() - 1 &&
            if_statement[i] != ':') {
            k = i;
            if (if_statement[i] == '(')
                parenthesis++;
            if (if_statement[i] == ')')
                parenthesis--;

            if (check_negativo(if_statement, i)) {
                negative++;
                cout << "Negative " << negative<<": ";
                print_substring(if_statement, k, i);
                k2 = i;
            }

            if (check_condition(if_statement, i)) {
                expr++;
                cout << "Expresion "<<expr<<": ";
                print_substring(if_statement, j, k);
                j = i;
                conditional++;
                cout << "Condition "<<conditional<<": ";
                print_substring(if_statement, k, i);
                k2 = i;
            }
            k = i;
            i++;
        }
        //al salir del bucle, si hay minimo una condicion, se asegura que halla una expresion a la derecha.
        expr++;
        cout << "Expression " << expr << ": ";
        //si i-j = 4 o 5 significa que puede ser un True o False, chequea si esa suposicion es correcta
        if ((i - j == 4 || i - j == 5) &&
            conditional == 0) {
            if (check_boolean(if_statement, i, j) == 1) {
                boolean = true;
            }
            print_substring(if_statement, i-(i-j), i);
        }
        else {
            print_substring(if_statement, k2, i);
        }
    }
    //Finalmente la ultima chequea que halla suficientes expresiones para las condicionales, o si es un True o False.
    if (if_statement[i] == ':' &&
        (((expr == 2 + 1*conditional-1 && conditional!=0) || (expr == 1 && boolean == 1)) || (expr==negative && expr!=1)) && parenthesis == 0) {
        return 1;
    }
    return 0;
}

int main() {
    //AQUI SE HACEN LOS CAMBIOS DEL STRING ORIGINAL----------------------------------------------------------------------
    string test = "if a==b";
    //-------------------------------------------------------------------------------------------------------------------
    cout << "Original string: " << test << endl;
    if (if_check(test)) {
        cout << "Correcto";
    }
    else {
        cout << "Incorrecto";
    }
}