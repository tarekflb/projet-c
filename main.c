#include <stdio.h>
#include "raylib.h"
#define MAX_ELEMENTS 20

void selectionSortVisual(int arr[], int n, int ascending) {
    const int screenWidth = 900;
    const int screenHeight = 500;
    const int barWidth = 50;
    const int spacing = 10;
    const int startX = 150;
    const int textOffsetY = 40;

    InitWindow(screenWidth, screenHeight, "Selection Sort Visualization using Raylib");
    SetTargetFPS(1);

    int i, j, index;

    for (i = 0; i < n - 1; i++) {
        index = i;

        for (j = i + 1; j < n; j++) {
            if ((ascending && arr[j] < arr[index]) || (!ascending && arr[j] > arr[index])) {
                index = j;
            }
        }

        int temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText(ascending ? "Sorting Ascending :" : "Sorting Descending :", 60, 20 + textOffsetY, 30, BLACK);
 
       for (int k = 0; k < n; k++) {
            Color color = DARKGRAY;
            if (k == i || k == index) color = RED;

            DrawRectangle(startX + k * (barWidth + spacing), 300 - arr[k] * 5, barWidth, arr[k] * 5, color);
            DrawText(TextFormat("%d", arr[k]), startX + k * (barWidth + spacing) + 10, 310 + textOffsetY, 20, BLACK);
        }

        EndDrawing();

        for (int delay = 0; delay < 20000000; delay++) {}
    }

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGRAY);

        DrawText(ascending ? "Sorting Ascending :" : "Sorting Descending :", 60, 20 + textOffsetY, 30, BLACK);

        for (int k = 0; k < n; k++) {
            DrawRectangle(startX + k * (barWidth + spacing), 300 - arr[k] * 5, barWidth, arr[k] * 5, GREEN);
            DrawText(TextFormat("%d", arr[k]), startX + k * (barWidth + spacing) + 10, 310 + textOffsetY, 20, BLACK);
        }

        EndDrawing();
    }

    CloseWindow();
}


int main() {
    int taille;
    const int screenWidth = 900;
    const int screenHeight = 500;
    const int buttonWidth = 250;
    const int buttonHeight = 50;
    const int buttonSpacing = 20;
    const int inputBoxHeight = 50;

    printf("Enter the number of elements: ");
    scanf("%d", &taille);

    if (taille <= 0 || taille >= MAX_ELEMENTS) {
        printf("Invalid size.");
        return 1;
    }

    int arr[MAX_ELEMENTS];

    for (int i = 0; i < taille; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    InitWindow(screenWidth, screenHeight, "Selection Sort Visualization using Raylib");
    SetTargetFPS(60);

    Rectangle buttonAsc = { screenWidth / 2 - buttonWidth / 2, 100, buttonWidth, buttonHeight };
    Rectangle buttonDesc = { screenWidth / 2 - buttonWidth / 2, buttonAsc.y + buttonHeight + buttonSpacing, buttonWidth, buttonHeight };

    while (!WindowShouldClose()) {
        if (CheckCollisionPointRec(GetMousePosition(), buttonAsc) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            printf("Ascending Sort/\n");
            selectionSortVisual(arr, taille, 1); // Tri Croissant
        }

        if (CheckCollisionPointRec(GetMousePosition(), buttonDesc) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            printf("Descending Sort \\n");
            selectionSortVisual(arr, taille, 0); // Tri Décroissant
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the title
        DrawText("Selection Sort Visualization", screenWidth / 2 - MeasureText("Selection Sort Visualization", 30) / 2, 30, 30, BLACK);

        // Draw the buttons
        DrawRectangleRec(buttonAsc, DARKPURPLE);
        DrawRectangleRec(buttonDesc, DARKPURPLE );
        

        // Draw button text
        DrawText(" Ascending Sort", buttonAsc.x + 20, buttonAsc.y + 15, 20, BLACK);
        DrawText(" Descending Sort", buttonDesc.x + 20, buttonDesc.y + 15, 20, BLACK);
        
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
