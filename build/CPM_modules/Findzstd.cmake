include("/mnt/151023c1-1726-4bc6-a47d-e17130eb28f2/c++ games/imagine engine/3rdParty/tracy/cmake/CPM.cmake")
CPMAddPackage("NAME;zstd;GITHUB_REPOSITORY;facebook/zstd;GIT_TAG;v1.5.7;OPTIONS;ZSTD_BUILD_SHARED OFF;EXCLUDE_FROM_ALL;TRUE;SOURCE_SUBDIR;build/cmake")
set(zstd_FOUND TRUE)