#include <stdio.h>

double add(double x, double y) {
    printf("\t%.2lf + %.2lf = %.2lf\n", x, y, x+y);
    return x + y;
}

double subtract(double x, double y) {
    printf("\t%.2lf - %.2lf = %.2lf\n", x, y, x-y);
    return x - y;
}

double divide(double x, double y) {
    printf("\t%.2lf / %.2lf = %.2lf\n", x, y, x/y);
    return x / y;
}

double multiply(double x, double y) {
    printf("\t%.2lf * %.2lf = %.2lf\n", x, y, x*y);
    return x * y;
}

double calculate_equation(double numbers[], char inputSigns[]) {
    double help_numbers[4];
    char help_signs[3];

    // put copy of equation into help_equation //
    for(int i = 0; i < 4; i++) {
        help_numbers[i] = numbers[i];
    }
    // put copy of equation into help_equation //

    for(int i = 0; i < 3; i++) {
        help_signs[i] = inputSigns[i];
    }

//    printf("%c %.2lf %c %.2lf %c %.2lf %c %.2lf %c\n", help_signs[0], help_numbers[0], help_signs[1], help_numbers[1], help_signs[2], help_numbers[2], help_signs[3], help_numbers[3], help_signs[4]);
    printf("%.2lf %c %.2lf %c %.2lf %c %.2lf\n", help_numbers[0], inputSigns[0], help_numbers[1], inputSigns[1], help_numbers[2], inputSigns[2], help_numbers[3]);

    for(int i = 0; i < 3; i++) {
        if (help_signs[i] == '*') {
            int h = i;
            while(help_numbers[h] == -99) {
                h = h - 1;
            }
            help_numbers[h] = multiply(help_numbers[h], help_numbers[i+1]);
            help_signs[i] = ' ';
            help_numbers[i+1] = -99;
        } else if (help_signs[i] == '/') {
            int h = i;
            while(help_numbers[h] == -99) {
                h = h - 1;
            }
            help_numbers[h] = divide(help_numbers[h], help_numbers[i+1]);
            help_signs[i] = ' ';
            help_numbers[i+1] = -99;
        }
    }

    for(int i = 0; i < 3; i++) {
        if (help_signs[i] == '+') {
            int h = i;
            while(help_numbers[h] == -99) {
                h = h - 1;
            }
            help_numbers[h] = add(help_numbers[h], help_numbers[i+1]);
            help_signs[i] = ' ';
            help_numbers[i+1] = -99;
        } else if (help_signs[i] == '-') {
            int h = i;
            while(help_numbers[h] == -99) {
                h = h - 1;
            }
            help_numbers[h] = subtract(help_numbers[h], help_numbers[i+1]);
            help_signs[i] = ' ';
            help_numbers[i+1] = -99;
        }
    }

    for(int i = 0; i < 4; i++) {
        if(help_numbers[i] == 10.00) {
            return 10.00;
        }
        if(help_numbers[i] != -99) {
            printf("\tResult: %.2lf\n", help_numbers[i]);
        }
    }
    return 0.0;
}

int main() {
    double numbers[4];
    int amt_allowed_signs;
    char outsideSigns[]= {' '};
//    char signs[] = {'(', '+', '-', '*', '/', ')'};
//    char signs[] = {'+', '-', '*', '/'};

    double result = 0.0;

    printf("*: %d\n", '*');
    printf("/: %d\n", '/');
    printf("+: %d\n", '+');
    printf("-: %d\n", '-');
    printf(" : %d\n", ' ');
//    printf("%d\n", 47=='/');

    // Get Numbers //
    for(int i = 0; i < 4; i++) {
        printf("Input Number %d: ", i+1);
        scanf(" %lf", &numbers[i]);
    }
    // Get Numbers //

    //Get Allowed Signs //
    printf("How many allowed signs? ");
    scanf(" %d", &amt_allowed_signs);
    char signs[amt_allowed_signs];
    for(int i = 0; i < amt_allowed_signs; i++) {
        printf("Allowed Sign %d: ", i+1);
        scanf(" %c", &signs[i]);
    }
    //Get Allowed Signs //

    int counter = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                for(int l = 0; l < 4; l++) {
                    for(int m = 0; m < amt_allowed_signs; m++) {
                        for(int n = 0; n < amt_allowed_signs; n++) {
                            for(int o = 0; o < amt_allowed_signs; o++) {
                                for(int p = 0; p < amt_allowed_signs; p++) {
                                    for(int q = 0; q < amt_allowed_signs; q++) {
                                        // so that every digit only appears once in the equation
                                        if(i != j && i != k && i != l && j != k && j != l && k != l) {
                                            // outside operators are emtpy or brackets
                                            if ((outsideSigns[m] == ' ' || outsideSigns[m] == '(') && (outsideSigns[q] == ' ' || outsideSigns[q] == ')')) {
                                                //
//                                                if ((signs[m] == '(' && (signs[n] != '(' && signs[o] != '(' && signs[p] != '(')) || (signs[n] == '(' && (signs[m] != '(' && signs[o] != '(' && signs[p] != '(')) || (signs[o] == '(' && (signs[m] != '(' && signs[n] != '(' && signs[p] != '(') || (signs[p] == '(' && (signs[m] != '(' && signs[n] != '(' && signs[o] != '(')))) {
//                                                    if((signs[n] == ')' && (signs[o] != ')' && signs[p] != ')' && signs[q] != ')')) || (signs[o] == ')' && (signs[n] != ')' && signs[p] != ')' && signs[q] != ')')) || (signs[p] == ')' && (signs[n] != ')' && signs[o] != ')' && signs[q] != ')') || (signs[q] == ')' && (signs[n] != ')' && signs[o] != ')' && signs[p] != ')')))) {
                                                        double ordered_numbers[4] = {numbers[i], numbers[j], numbers[k], numbers[l]};
//                                                char inputSigns[] = {outsideSigns[m], signs[n],  signs[o], signs[p], outsideSigns[q]};
                                                        char inputSigns[] = {signs[n],  signs[o], signs[p]};
                                                        result = calculate_equation(ordered_numbers, inputSigns);

                                                        if(result == 10) {
//                                                            printf("%c %.2lf %c %.2lf %c %.2lf %c %.2lf %c\n", inputSigns[0], ordered_numbers[0], inputSigns[1], ordered_numbers[1], inputSigns[2], ordered_numbers[2], inputSigns[3], ordered_numbers[3], inputSigns[4]);
                                                            printf("%.2lf %c %.2lf %c %.2lf %c %.2lf\n", ordered_numbers[0], inputSigns[0], ordered_numbers[1], inputSigns[1], ordered_numbers[2], inputSigns[2], ordered_numbers[3]);
                                                            return 0;
                                                        }
                                                        counter++;
//                                                    }
//                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
