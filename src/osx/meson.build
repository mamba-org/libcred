so_version = '1'

lib_sources = ['osxkeychain_darwin.c']

apple_deps = dependency('appleframeworks', modules : ['CoreFoundation', 'Security'])

credhelperlib = library('credhelper',
                lib_sources,
                c_args: [
                    '-ObjC',
                    '-DNS_FORMAT_ARGUMENT(A)=',
                    '-D_Nullable_result=_Nullable'
                ],
                include_directories: '.',
                dependencies: apple_deps,
                install: true,
                version: meson.project_version(),
                soversion: so_version
            )
