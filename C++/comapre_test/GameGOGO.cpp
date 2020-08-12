#include <iostream>
using namespace std;

void action()
{
    while(true) {
        cout<<"What do you?\n";
        string act;
        cin >> act;     // 문자열에서 문자를 읽기
        Point delta {0,0}; // Point {x, y} 쌍을 정장

        for (char ch : act) {
            switch(ch) {
                case 'u':   // 위로
                case 'n':   // 북쪽으로
                    ++delta.y;
                    break;
                case 'r':   // 오른쪽으로
                case 'e':   // 동쪽으로
                    ++delta.x;
                    break;
                //.. 다른 행동 ..
                default:
                    cout<<"STOP\n";                
            }
            move(current+delta*scale);
            update_display();
        }
    }
}