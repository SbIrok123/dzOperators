#include <iostream>
#include<stdio.h>
#include<ctime>
#include"Time_.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    int lessons = 7;
    float lessonLength = 45.0f, smallPeremena = 15.0f, bigPeremena = 20.0f;
    Time_ lessonTime(8, 30, 0);

    for (int i = 1; i <= lessons; i++) {
        cout << "Начало урока №" << i << " в : ";
        lessonTime.showTime();
        cout << endl;

        lessonTime += 45.0f;

        cout << "Конец урока №" << i << " в : ";
        lessonTime.showTime();
        cout << endl;

        if (i < lessons) {
            if (i == 2 || i==4) {
                lessonTime += bigPeremena;
                cout << "Длинная перемена. Урок - " << i << endl;
            }
            else {
                lessonTime += smallPeremena;
                cout << "Короткая перемена. Урок - " << i << endl;
            }
        }
        cout << "\n";
    }
}