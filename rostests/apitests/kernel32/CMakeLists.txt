
list(APPEND SOURCE
    dosdev.c
    FindFiles.c
    GetComputerNameEx.c
    GetCurrentDirectory.c
    GetDriveType.c
    GetModuleFileName.c
    interlck.c
    lstrcpynW.c
    MultiByteToWideChar.c
    PrivMoveFileIdentityW.c
    SetConsoleWindowInfo.c
    SetCurrentDirectory.c
    SetUnhandledExceptionFilter.c
    TerminateProcess.c
    TunnelCache.c
    WideCharToMultiByte.c
    testlist.c
    Mailslot.c)

add_executable(kernel32_apitest ${SOURCE})
target_link_libraries(kernel32_apitest wine ${PSEH_LIB})
set_module_type(kernel32_apitest win32cui)
add_importlibs(kernel32_apitest advapi32 gdi32 user32 shlwapi msvcrt kernel32 ntdll)
add_cd_file(TARGET kernel32_apitest DESTINATION reactos/bin FOR all)
