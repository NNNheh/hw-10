#include <stdio.h>
#include <locale.h>
#include <math.h>


int main() {
    int choice;
    char ch;
    float a, b, h; 
    int height, top_base, bottom_base;
    setlocale(LC_ALL, "RUS");

    printf("Вы выбрали фигуру: Прямоугольная трапеция\n\n");

    printf("Меню:\n");
    printf("1) Рассчитать площадь\n");
    printf("2) Вывести определение фигуры\n");
    printf("3) Нарисовать фигуру\n");
    printf("Выберите пункт меню (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("Введите длину верхнего основания a: ");
        scanf("%f", &a);
        printf("Введите длину нижнего основания b: ");
        scanf("%f", &b);
        printf("Введите высоту h: ");
        scanf("%f", &h);

        printf("Площадь прямоугольной трапеции = %.2f\n", ((a + b) / 2) * h);
        break;

    case 2:
        printf("\nПрямоугольная трапеция — это трапеция, у которой один из углов прямой.\n");
        printf("Она имеет одно перпендикулярное боковое ребро, а второе — наклонное.\n");
        break;

    case 3:
        printf("Введите символ для рисования: ");
        scanf(" %c", &ch);

        printf("Введите высоту трапеции: ");
        scanf("%d", &height);

        printf("Введите длину верхнего основания: ");
        scanf("%d", &top_base);

        printf("Введите длину нижнего основания: ");
        scanf("%d", &bottom_base);

        if (bottom_base <= top_base) {
            printf("Ошибка: нижнее основание должно быть длиннее верхнего!\n");
            return 1;
        }

        int diff = bottom_base - top_base;
        float step = (float)diff / height;

        for (int i = 0; i < height; i++) {
            int spaces = (int)(i * step);
            int line_length = top_base + spaces;

            for (int j = 0; j < line_length; j++) {
                if (i == 0) { 
                    printf("%c", ch);
                }
                else if (i == height - 1) { 
                    printf("%c", ch);
                }
                else if (j == 0) {
                    printf("%c", ch);
                }
                else if (j == line_length - 1) {
                    printf("%c", ch);
                }
                else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        break;

    default:
        printf("Ошибка: нет такого пункта меню.\n");
    }

    return 0;
}