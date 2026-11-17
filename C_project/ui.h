#ifndef UI_H
#define UI_H
#include "room.h"
void main_menu(RoomList *list);
void list_rooms(RoomList *list);
Node *select_room(RoomList *list);
void display_room(Room *room);
void room_operations_menu(Node *room);
#endif