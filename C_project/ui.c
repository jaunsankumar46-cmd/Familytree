#include <stdio.h>
#include <string.h>
#include "room.h"
#include "ui.h"
void checkIn(Node *room);
void checkOut(Node *room);
void changeRoomStatus(Node *room, RoomStatus status);
void add_room(RoomList *list);
int get_choice()
{
    char input[20];
    int choice;
    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%d", &choice) == 1)
        return choice;
    return -1;
}
void get_string(char *text, int size)
{
    fgets(text, size, stdin);
    text[strcspn(text, "\n")] = '\0';
}
void display_room(Room *room)
{
    printf("\nRoom Number : %d\n", room->room_number);
    printf("Guest Name  : %s\n", room->guest_name);
    printf("Price/Night : %.2f\n", room->price_per_night);
    printf("Nights      : %d\n", room->nights_booked);
    if (room->status == ROOM_AVAILABLE)
        printf("Status      : Available\n");
    else if (room->status == ROOM_OCCUPIED)
        printf("Status      : Occupied\n");
    else
        printf("Status      : Maintenance\n");
}
void list_rooms(RoomList *list)
{
    Node *temp = list->head;
    int choice;
    printf("\n1. All\n2. Available\n3. Occupied\n4. Maintenance\n");
    printf("Choice: ");
    choice = get_choice();
    while (temp != NULL)
    {
        if (choice == 1 ||
            (choice == 2 && temp->data.status == ROOM_AVAILABLE) ||
            (choice == 3 && temp->data.status == ROOM_OCCUPIED) ||
            (choice == 4 && temp->data.status == ROOM_MAINTENANCE))
        {
            display_room(&temp->data);
        }
        temp = temp->next;
    }
}
Node *select_room(RoomList *list)
{
    char input[20];
    int number;
    Node *temp = list->head;
    printf("Enter room number: ");
    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%d", &number) != 1)
    {
        printf("Invalid room number.\n");
        return NULL;
    }
    while (temp != NULL)
    {
        if (temp->data.room_number == number)
            return temp;
        temp = temp->next;
    }
    printf("Room not found.\n");
    return NULL;
}
void room_operations_menu(Node *room)
{
    int choice, status;
    do
    {
        printf("\n1. View Room\n");
        printf("2. Check-in\n");
        printf("3. Check-out\n");
        printf("4. Change Status\n");
        printf("5. Cancel Reservation\n");
        printf("6. Back\n");
        printf("Choice: ");
        choice = get_choice();
        if (choice == 1)
            display_room(&room->data);
        else if (choice == 2)
            checkIn(room);
        else if (choice == 3)
            checkOut(room);
        else if (choice == 4)
        {
            printf("1. Available\n");
            printf("2. Maintenance\n");
            printf("Choice: ");
            status = get_choice();
            if (status == 1)
                changeRoomStatus(room, ROOM_AVAILABLE);
            else if (status == 2)
                changeRoomStatus(room, ROOM_MAINTENANCE);
            else
                printf("Invalid status.\n");
        }
        else if (choice == 5)
        {
            room->data.status = ROOM_AVAILABLE;
            strcpy(room->data.guest_name, "N/A");
            room->data.nights_booked = 0;
            printf("Reservation cancelled.\n");
        }
        else if (choice != 6)
            printf("Invalid choice.\n");
    } while (choice != 6);
}
void main_menu(RoomList *list)
{
    int choice;
    do
    {
        printf("\n===== HOTEL BOOKING SYSTEM =====\n");
        printf("1. List Rooms\n");
        printf("2. Add Room\n");
        printf("3. Select Room\n");
        printf("4. Save & Exit\n");
        printf("Choice: ");
        choice = get_choice();
        if (choice == 1)
            list_rooms(list);
        else if (choice == 2)
            add_room(list);
        else if (choice == 3)
        {
            Node *room = select_room(list);
            if (room != NULL)
                room_operations_menu(room);
        }
        else if (choice == 4)
        {
            save_rooms_to_file(list);
            printf("Data saved. Goodbye!\n");
        }
        else
            printf("Invalid choice.\n");
    } while (choice != 4);
}