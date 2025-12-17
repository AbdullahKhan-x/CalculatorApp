#include "raylib.h"
#include "imgui.h"
#include "rlImGui.h"

int main()
{
	// Initialize Raylib window
	const int screenWidth = 800;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Calculator App - Library Test");
	SetTargetFPS(60);

	// Initialize rlImGui
	rlImGuiSetup(true);

	// Test variables for ImGui widgets
	bool showTestWindow = true;
	float testFloat = 0.0f;
	int testCounter = 0;
	char textBuffer[256] = "Type here...";
	float clearColor[3] = {0.2f, 0.2f, 0.2f};

	// Main game loop
	while (!WindowShouldClose())
	{
		// Update
		// ---------

		// Update background color from ImGui
		Color bgColor = {
			(unsigned char)(clearColor[0] * 255),
			(unsigned char)(clearColor[1] * 255),
			(unsigned char)(clearColor[2] * 255),
			255
		};

		// Draw
		// ---------
		BeginDrawing();
		ClearBackground(bgColor);

		// Raylib test drawing
		DrawText("Raylib is working!", 10, 10, 20, LIME);
		DrawCircle(screenWidth - 50, 50, 30, RED);
		DrawRectangle(10, 50, 100, 50, BLUE);

		// Start ImGui frame
		rlImGuiBegin();

		// ImGui test window
		if (showTestWindow)
		{
			ImGui::Begin("Library Test Window", &showTestWindow);

			ImGui::Text("All Libraries Working!");
			ImGui::Separator();

			// Test various ImGui widgets
			ImGui::Text("ImGui is functioning correctly!");
			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
						1000.0f / ImGui::GetIO().Framerate,
						ImGui::GetIO().Framerate);

			ImGui::Spacing();

			if (ImGui::Button("Click Me!"))
			{
				testCounter++;
			}
			ImGui::SameLine();
			ImGui::Text("Button clicked %d times", testCounter);

			ImGui::Spacing();

			ImGui::SliderFloat("Slider Test", &testFloat, 0.0f, 100.0f);
			ImGui::ProgressBar(testFloat / 100.0f);

			ImGui::Spacing();

			ImGui::InputText("Text Input", textBuffer, sizeof(textBuffer));

			ImGui::Spacing();
			ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "Green Text!");
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Red Text!");

			ImGui::Spacing();

			// Calculator preview section
			ImGui::Separator();
			ImGui::Text("Calculator Preview:");
			ImGui::BeginChild("CalcPreview", ImVec2(0, 150), true);
			ImGui::Text("Display: 0");
			if (ImGui::Button("7", ImVec2(50, 50))) {}
			ImGui::SameLine();
			if (ImGui::Button("8", ImVec2(50, 50))) {}
			ImGui::SameLine();
			if (ImGui::Button("9", ImVec2(50, 50))) {}
			ImGui::SameLine();
			if (ImGui::Button("/", ImVec2(50, 50))) {}
			ImGui::EndChild();

			ImGui::End();
		}

		// Another test window
		ImGui::Begin("rlImGui Bridge Test");
		ImGui::Text("rlImGui is linking Raylib + ImGui!");
		ImGui::Text("Mouse Position: (%.1f, %.1f)", GetMouseX(), GetMouseY());
		ImGui::ColorEdit3("Clear Color", clearColor);
		ImGui::End();

		// End ImGui frame
		rlImGuiEnd();

		EndDrawing();
	}

	// Cleanup
	rlImGuiShutdown();
	CloseWindow();

	return 0;
}
