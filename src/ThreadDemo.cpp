// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved
//
// Contents:    Multi-threaded document editing demonstration.
//              Demonstrates the pattern: std::thread t(edit_document, filename); t.detach();
//
//----------------------------------------------------------------------------
#include "Common.h"
#include "PadWrite.h"
#include "ThreadDemo.h"

void open_new_document_window()
{
    // This function runs in a separate thread
    // It demonstrates the body of edit_document() from the code snippet
    
    // Initialize COM for this thread (required for DirectWrite/D2D)
    HRESULT hr = CoInitialize(NULL);
    if (FAILED(hr))
        return;
    
    // Create and run a new MainWindow instance
    // This maps to: open_document_and_display_gui(filename)
    MainWindow app;
    app.AddRef(); // implicit reference to the root window
    
    hr = app.Initialize();
    if (SUCCEEDED(hr))
    {
        // This maps to: while(!done_editing()) { get_user_input(); ... }
        // The message loop handles user input and keeps running until the window closes
        app.RunMessageLoop();
    }
    
    // Cleanup COM for this thread
    CoUninitialize();
}

void edit_document_in_thread(const wchar_t* filename)
{
    // This function maps to: void edit_document(std::string const& filename)
    // For this demo, we just open a new window
    // In a real implementation, you would load the specified file
    
    open_new_document_window();
    
    // Note: If you wanted to load a specific file, you would:
    // 1. Pass filename to MainWindow::Initialize()
    // 2. Load the file content in Initialize()
    // 3. Set the text in the TextEditor
}
