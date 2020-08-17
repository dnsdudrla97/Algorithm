#include <stdio.h>

struct tag_Friend
{
    char Name[10];
    int Age;
    double Height;
};
void OutFriend(tag_Friend F);
void OutFriendPtr(tag_Friend *F);
void OutFriendRef(tag_Friend &F);

int main()
{
    tag_Friend Friend = {"나민", 25, 173};
    OutFriend(Friend);
    OutFriendPtr(&Friend);
    OutFriendRef(Friend);
}
void OutFriend(tag_Friend F) // 값 호출
{
    printf("이름=%s, 나이=%d, 키=%.1f\n",
           F.Name, F.Age, F.Height);
}
void OutFriendPtr(tag_Friend *F) // 포인터 참조 호출
{
    printf("이름=%s, 나이=%d, 키=%.1f\n",
           F->Name, F->Age, F->Height);
}
void OutFriendRef(tag_Friend &F) // 레퍼런스 참조 호출
{
    printf("이름=%s, 나이=%d, 키=%.1f\n",
           F.Name, F.Age, F.Height);
}