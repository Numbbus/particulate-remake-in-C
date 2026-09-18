#include "raylib.h"
#include "stdio.h"
#include "string.h"

int main(void)
{

// Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;

    const int gridSize = 20;
    const int rows = screenHeight / gridSize;
    const int cols = screenWidth / gridSize;

    int matrix[rows][cols];
    memset(matrix, 0, sizeof(matrix)); // initialize all values to 0

    Color bgColor = BLACK;

    InitWindow(screenWidth, screenHeight, "Basic Sand Sim Demo");
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())    
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            //bgColor = WHITE;
            Vector2 mpos = GetMousePosition();
            int x = mpos.x / gridSize;
            int y = mpos.y / gridSize;

            if (matrix[y][x] == 0){
                matrix[y][x] = 1;
            }/*else{
                matrix[y][x] = 0;
            }*/
        }

        BeginDrawing();
        ClearBackground(bgColor);

        // iterate bottom to top through the matrix. Top to bottom would cause everything to happen instantly
        for(int r = rows; r >= 0; r--){
            for(int c = cols; c >=0; c--){
                if(matrix[r][c] == 1){

                    // Move tile if able
                    if (r+1 < rows && matrix[r+1][c] == 0){
                        matrix[r][c] = 0;
                        matrix[r+1][c] = 1;
                    }
                    else if (matrix[r+1][c] == 1){

                        if(matrix[r+1][c+1] == 0){
                            matrix[r][c] = 0;
                            matrix[r+1][c+1] = 1;
                        }else if(matrix[r+1][c-1] == 0){
                            matrix[r][c] = 0;
                            matrix[r+1][c-1] = 1;   
                        }
                    }

                    // Draw tile
                    DrawRectanglePro((Rectangle){c * gridSize, r * gridSize, gridSize, gridSize}, (Vector2){0, 0}, 0, WHITE);
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
