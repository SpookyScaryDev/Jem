#include "JemPCH.h"
#include "Console.h"

#include <Renderer/Renderer.h>
#include <Core/Game/Game.h>
#include <vector>
#include <string>
#include <Core/Event/EventDispatcher.h>
#include <Core/Event/TextEvent.h>
#include <Core/Event/KeyEvent.h>
#include <Core/Event/MouseEvent.h>
#include <SDL.h> // TODO: Get rid of this!

namespace Jem {

namespace Console {
    Font*    font;
    bool     isShown;
    Vector2d size;
    Vector4d backgroundColour;
    int      textHeight;
    double   textWidth;
    Vector4d textColour;

    Vector2d cursorSize;             // Size of cursor rectangle.
    int      cursorPosition;         // Position in current command.
    int      bufferPosition;         // Position of all console text - used to scroll console.
    int      commandHistoryPosition; // Position of current displayed command in command history.

    std::vector<std::string> buffer;         // All messages printed to console
    std::vector<Vector4d>    colours;        // Colours of messages
    std::string              command;        // Current command being written.
    std::string              oldCommand;     // Back up of only command when checking history.
    std::vector<std::string> commandHistory; // All previously entered commands.

    void OnEvent(Event* event) {
        if (isShown) {
            switch (event->GetType()) {
            case EventType::TextInput:
                command.insert(cursorPosition, ((TextInputEvent*)event)->GetText());   // Add text to command.
                cursorPosition++;   // Move cursor to correct position.
                break;

            case EventType::MouseScrolled:
                bufferPosition += ((MouseScrolledEvent*)event)->GetYOffset(); // Move position in buffer.
                if (bufferPosition < 0) bufferPosition = 0;                   // Make sure buffer isn't moved too far.
                if (bufferPosition > buffer.size()) bufferPosition = buffer.size();
                break;

            case EventType::KeyPressed:
                switch (((KeyPressedEvent*)event)->GetKeyCode()) {
                case KeyCode::KEY_BACKSPACE:
                    if (cursorPosition > 0) {             // Check not at start of line.
                        cursorPosition--;                 // Move cursor back.
                        command.erase(cursorPosition, 1); // Erase character.
                    }
                    break;

                case KeyCode::KEY_DELETE:
                    if (cursorPosition < command.size()) { // Check not at end.
                        command.erase(cursorPosition, 1);  // Erase character.
                    }
                    break;

                case KeyCode::KEY_LEFT:
                    if (cursorPosition > 0) { // Don't move too far left.
                        cursorPosition--;     // Move cursor.
                    }
                    break;

                case KeyCode::KEY_RIGHT:
                    if (cursorPosition < command.size()) { // Don't go too far right either!
                        cursorPosition++;                  // Move cursor.
                    }
                    break;

                case KeyCode::KEY_RETURN:
                    if (!command.empty()) {                // Don't bother with empty command
                        Print(command);
                        commandHistory.push_back(command); // Add command to history,
                        command = "";                      // New command.
                        commandHistoryPosition = commandHistory.size(); // Move history to most recent.
                        cursorPosition = 0;                // Move cursor to start of line.
                    }
                    break;

                case KeyCode::KEY_UP:
                    if (!commandHistory.empty()) {  // Don't bother moving/
                        if (commandHistoryPosition == commandHistory.size()) { // Save command currently being written so it can be returned to.
                            oldCommand = command;
                        } 
                        if (commandHistoryPosition > 0) {    // If not at the end.
                            commandHistoryPosition--;        // Move back in history.
                            command = commandHistory[commandHistoryPosition]; // Set command.
                            cursorPosition = command.size(); // Move cursor to end of line.
                        }
                    }
                    break;

                case KeyCode::KEY_DOWN:
                    if (commandHistoryPosition < (int)commandHistory.size() - 1) {  // If not at start.
                        commandHistoryPosition++;                              // Move forward in history.
                        command = commandHistory[commandHistoryPosition];      // Set command.
                        cursorPosition = command.size();                       // Move cursor to end of line.
                    }
                    else if (commandHistoryPosition == (int)commandHistory.size() - 1){ // If returning to cached command  
                        commandHistoryPosition = commandHistory.size();            // Move to backed up command.
                        command = oldCommand;                                      // Set command.
                        cursorPosition = command.size();                           // Move cursor to end of line.
                    }
                    break;
                }
            }
        }
    }

    void Init() {
        isShown = false;
        size = { 1600.0, 400 };
        backgroundColour = { 0.0, 0.0, 0.0, 210.0 };
        textColour = { 255, 255, 255, 255 };

        command = "";

        cursorPosition = 0;
        bufferPosition = 0;
        commandHistoryPosition = 0;

        EventDispatcher::SetEventCallback(&OnEvent);

        font = new Font("C:\\Windows\\Fonts\\consola.ttf", 17, true);

        textWidth = font->GetGlyphClip(' ').size.x + 1; // TODO: Put in font class.
        textHeight = font->GetGlyphClip(' ').size.y + 1;
        cursorSize = { textWidth, 2 };
    }

    void Shutdown() {
        if (font != nullptr) {
            delete font;
            font = nullptr;
        }
    }

    void Toggle() {
        isShown = !isShown;
    }

    void Update() {
        if (isShown) { // Enable TextInput events.
            SDL_StartTextInput();
        } else {
            SDL_StopTextInput();
        }
    }

    void Draw() {
        if (isShown) {
            Renderer::DrawFilledRectangle({ 0.0, 0.0 }, size, backgroundColour);

            double yPos = size.y - textHeight;
            Renderer::DrawString({ 0.0, yPos }, ("> " + command).c_str(), font);
            Renderer::DrawFilledRectangle({ (cursorPosition + 2) * textWidth, size.y - cursorSize.y }, cursorSize, { 255.0, 255.0, 255.0, 255.0 });

            // Draw text in console.
            yPos -= textHeight;
            for (int i = buffer.size() - bufferPosition - 1; i >= 0; i--) {
                yPos -= textHeight;
                if (yPos < 0.0) break;

                Renderer::DrawString({ 0.0, yPos }, buffer[i].c_str(), font, colours[i]);
            }
        }
    }

    void Print(const char* message) {
        buffer.push_back(message);
        colours.push_back(textColour);
    }
}

}