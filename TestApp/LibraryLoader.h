#pragma once

#include <windows.h>

#include <iostream>

/** Library loader can safely load DLL and provides safe unload in destructor.
 *  Calling of FreeLibrary is important during application tear-down, otherwise there is risk of crash.
 *  The class is header-only.
 */
class LibraryLoader final
{
public:
    HMODULE handle;

    inline LibraryLoader() : handle(nullptr) {}
    inline LibraryLoader(const char* fileName) : handle(LoadLibrary(fileName))
    {
        if (!handle)
            std::cerr << "ERROR: unable to load library " << fileName<< ". Reason: " << GetLastError() << std::endl;
    }
    inline LibraryLoader(HMODULE h) : handle(h) {}
    inline LibraryLoader(LibraryLoader&& ll) : handle(ll.handle) { ll.handle = nullptr; }
    inline LibraryLoader& operator=(LibraryLoader&& ll)
    {
        if (handle)
            FreeLibrary(handle);
        handle = ll.handle;
        ll.handle = nullptr;
    }
    inline ~LibraryLoader()
    {
        if (handle)
            FreeLibrary(handle);
    }

    LibraryLoader(const LibraryLoader&) = delete;
    LibraryLoader& operator=(const LibraryLoader&) = delete;

    inline bool valid() const { return handle != nullptr; }
    inline bool load(const char* filename)
    {
        if (handle)
            FreeLibrary(handle);
        handle = LoadLibrary(filename);
        return handle != nullptr;
    }
    inline void free()
    {
        if (handle)
        {
            FreeLibrary(handle);
            handle = nullptr;
        }
    }
    template <typename T>
    inline T resolve(const char* funcName)
    {
        return reinterpret_cast<T>(GetProcAddress(handle, funcName));
    }
};

