#include <iostream>
using namespace std;
struct Coord {
    int x;
    int y;
};

class Rectangle {
private:
    int width;
    int height;
    char symbol;
    Coord position;
    bool isValidSize(int w, int h) {
        return w > 0 && h > 0;
    }

public:
    Rectangle() {
        width = 5;
        height = 3;
        symbol = '*';
        position = { 0, 0 };
    }

    Rectangle(int size) {
        if (size > 0) {
            width = height = size;
        }
        else {
            width = height = 1;
        }
        symbol = '#';
        position = { 0, 0 };
    }

    Rectangle(int w, int h) {
        if (isValidSize(w, h)) {
            width = w;
            height = h;
        }
        else {
            width = height = 1;
        }
        symbol = '@';
        position = { 0, 0 };
    }

    void draw() const {
        for (int i = 0; i < position.y; i++) {
            cout << endl;
        }

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < position.x; j++) {
                cout << ' ';
            }
            for (int j = 0; j < width; j++) {
                cout << symbol;
            }
            cout << endl;
        }
    }

    void resize(int deltaHeight, int deltaWidth) {
        int newHeight = height + deltaHeight;
        int newWidth = width + deltaWidth;

        if (isValidSize(newWidth, newHeight)) {
            height = newHeight;
            width = newWidth;
        }
        else {
            cout << "Помилка: некоректний розмір!" << endl;
        }
    }

    void move(int dx, int dy) {
        if (position.x + dx >= 0 && position.y + dy >= 0) {
            position.x += dx;
            position.y += dy;
        }
        else {
            cout << "Помилка: координати не можуть бути від’ємними!" << endl;
        }
    }
};

int main() {
    Rectangle r1;
    Rectangle r2(4);
    Rectangle r3(6, 2);

    cout << "Прямокутник r1:" << endl;
    r1.draw();

    cout << "\nПрямокутник r2 після переміщення:" << endl;
    r2.move(5, 2);
    r2.draw();

    cout << "\nПрямокутник r3 після зміни розміру:" << endl;
    r3.resize(1, 3);
    r3.draw();

    return 0;
}
