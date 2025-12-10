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
#pragma once

#include "Common.h"

// Function that demonstrates multi-threaded document editing
// Maps to: void edit_document(std::string const& filename)
void edit_document_in_thread(const wchar_t* filename);

// Helper to create a new window in a separate thread
void open_new_document_window();
